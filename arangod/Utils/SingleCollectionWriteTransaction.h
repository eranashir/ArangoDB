////////////////////////////////////////////////////////////////////////////////
/// @brief wrapper for self-contained, single collection write transactions
///
/// @file
///
/// DISCLAIMER
///
/// Copyright 2004-2012 triAGENS GmbH, Cologne, Germany
///
/// Licensed under the Apache License, Version 2.0 (the "License");
/// you may not use this file except in compliance with the License.
/// You may obtain a copy of the License at
///
///     http://www.apache.org/licenses/LICENSE-2.0
///
/// Unless required by applicable law or agreed to in writing, software
/// distributed under the License is distributed on an "AS IS" BASIS,
/// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
/// See the License for the specific language governing permissions and
/// limitations under the License.
///
/// Copyright holder is triAGENS GmbH, Cologne, Germany
///
/// @author Jan Steemann
/// @author Copyright 2011-2012, triAGENS GmbH, Cologne, Germany
////////////////////////////////////////////////////////////////////////////////

#ifndef TRIAGENS_UTILS_SINGLE_COLLECTION_WRITE_TRANSACTION_H
#define TRIAGENS_UTILS_SINGLE_COLLECTION_WRITE_TRANSACTION_H 1

#include "Utils/SingleCollectionTransaction.h"

#include "Utils/CollectionWriteLock.h"

#include "VocBase/transaction.h"
#include "VocBase/vocbase.h"

namespace triagens {
  namespace arango {

// -----------------------------------------------------------------------------
// --SECTION--                            class SingleCollectionWriteTransaction
// -----------------------------------------------------------------------------

    template<bool E, uint64_t M>
    class SingleCollectionWriteTransaction : public SingleCollectionTransaction<E> {

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ArangoDB
/// @{
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                      constructors and destructors
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ArangoDB
/// @{
////////////////////////////////////////////////////////////////////////////////

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief create the transaction, using a collection object
///
/// A single collection write transaction must at most execute one write operation
/// on the underlying collection. Whenever it tries to execute more than one
/// write operation, an error is returned. Executing only one operation is
/// sufficient for the basic CRUD operations and allows using the transaction
/// API even for the single CRUD operations. However, much of the transaction 
/// overhead can be avoided if the transaction only consists of a single 
/// operation on a single collection. 
////////////////////////////////////////////////////////////////////////////////

        SingleCollectionWriteTransaction (TRI_vocbase_t* const vocbase,
                                          TRI_transaction_t* previousTrx,
                                          const string& collectionName, 
                                          const TRI_col_type_e collectionType, 
                                          const bool createCollection, 
                                          const string& trxName) :
          SingleCollectionTransaction<E>(vocbase, previousTrx, collectionName, collectionType, createCollection, trxName, TRI_TRANSACTION_WRITE), 
          _numWrites(0), 
          _synchronous(false) {
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief end the transaction
////////////////////////////////////////////////////////////////////////////////

        virtual ~SingleCollectionWriteTransaction () {
        }

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ArangoDB
/// @{
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                  public functions
// -----------------------------------------------------------------------------

      public:

////////////////////////////////////////////////////////////////////////////////
/// @brief return whether the last write in a transaction was synchronous
////////////////////////////////////////////////////////////////////////////////

        inline bool synchronous () const {
          return _synchronous;
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief create a single document within a transaction
////////////////////////////////////////////////////////////////////////////////

        int createDocument (TRI_doc_mptr_t** mptr,
                            TRI_json_t const* json, 
                            const bool forceSync) {
          if (_numWrites++ > M) {
            return TRI_ERROR_TRANSACTION_INTERNAL;
          }

          TRI_primary_collection_t* primary = this->primaryCollection();
          _synchronous = forceSync || primary->base._info._waitForSync;

          return this->createCollectionDocument(primary, TRI_DOC_MARKER_KEY_DOCUMENT, mptr, json, 0, forceSync);
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief create a single edge within a transaction
////////////////////////////////////////////////////////////////////////////////

        int createEdge (TRI_doc_mptr_t** mptr,
                        TRI_json_t const* json, 
                        bool forceSync, 
                        void const* data) {
          if (_numWrites++ > M) {
            return TRI_ERROR_TRANSACTION_INTERNAL;
          }

          TRI_primary_collection_t* primary = this->primaryCollection();
          _synchronous = forceSync || primary->base._info._waitForSync;
          
          return this->createCollectionDocument(primary, TRI_DOC_MARKER_KEY_EDGE, mptr, json, data, forceSync);
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief update a single document within a transaction
////////////////////////////////////////////////////////////////////////////////

        int updateJson (const string& key,
                        TRI_doc_mptr_t** mptr, 
                        TRI_json_t* const json, 
                        const TRI_doc_update_policy_e policy, 
                        bool forceSync, 
                        const TRI_voc_rid_t expectedRevision, 
                        TRI_voc_rid_t* actualRevision) {
          if (_numWrites++ > M) {
            return TRI_ERROR_TRANSACTION_INTERNAL;
          }

          TRI_primary_collection_t* primary = this->primaryCollection();
          _synchronous = forceSync || primary->base._info._waitForSync;

          return this->updateCollectionDocument(primary, key, mptr, json, policy, expectedRevision, actualRevision, forceSync);
        }

////////////////////////////////////////////////////////////////////////////////
/// @brief delete a single document within a transaction
////////////////////////////////////////////////////////////////////////////////

        int destroy (const string& key, 
                     const TRI_doc_update_policy_e policy, 
                     bool forceSync, 
                     const TRI_voc_rid_t expectedRevision, 
                     TRI_voc_rid_t* actualRevision) {
          if (_numWrites++ > M) {
            return TRI_ERROR_TRANSACTION_INTERNAL;
          }

          TRI_primary_collection_t* primary = this->primaryCollection();
          _synchronous = forceSync || primary->base._info._waitForSync;

          return this->deleteCollectionDocument(primary, key, policy, expectedRevision, actualRevision, forceSync);
        }

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// @addtogroup ArangoDB
/// @{
////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// --SECTION--                                                 private variables
// -----------------------------------------------------------------------------

      private:

////////////////////////////////////////////////////////////////////////////////
/// @brief number of writes the transaction has executed
/// the value should be 0 or 1, but not get any higher because values higher
/// than one indicate internal errors
////////////////////////////////////////////////////////////////////////////////

        uint64_t _numWrites;

////////////////////////////////////////////////////////////////////////////////
/// @brief whether of not the last write action was executed synchronously
////////////////////////////////////////////////////////////////////////////////

        bool _synchronous;

////////////////////////////////////////////////////////////////////////////////
/// @}
////////////////////////////////////////////////////////////////////////////////

    };

  }
}

#endif

// Local Variables:
// mode: outline-minor
// outline-regexp: "^\\(/// @brief\\|/// {@inheritDoc}\\|/// @addtogroup\\|/// @page\\|// --SECTION--\\|/// @\\}\\)"
// End: