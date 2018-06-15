// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "consensus.h"








/** The maximum allowed size for a serialized block, in bytes (only for buffer size limits) */
unsigned int MAX_BLOCK_SERIALIZED_SIZE = 4000000;
/** The maximum allowed weight for a block, see BIP 141 (network rule) */
unsigned int MAX_BLOCK_WEIGHT = 4000000;
/** The maximum allowed number of signature check operations in a block (network rule) */
int64_t MAX_BLOCK_SIGOPS_COST = 80000;
/** Coinbase transaction outputs can only be spent after this number of new blocks (network rule) */
int COINBASE_MATURITY = 100;
/** Fork block number */
int FORK_BLOCK = 530208;
/** Whether fork should occur or not (-disablefork sets to false) */
bool FORK_ALLOWED = true;

/** Fork hash */
std::string FORK_HASH = "4e64e5bc70ef7530d48099e561ff031e5690e6b4373e9684dd8f5f6e526cce7e";
uint256 FORK_HASH_UINT256 = uint256S(FORK_HASH);

const int WITNESS_SCALE_FACTOR = 4;

const size_t MIN_TRANSACTION_WEIGHT = WITNESS_SCALE_FACTOR * 60; // 60 is the lower bound for the size of a valid serialized CTransaction
const size_t MIN_SERIALIZABLE_TRANSACTION_WEIGHT = WITNESS_SCALE_FACTOR * 10; // 10 is the lower bound for the size of a serialized CTransaction

Conforksus fork_conforksus(
    64000000,
    64000000,
    100);

Conforksus base_conforksus(
    MAX_BLOCK_SERIALIZED_SIZE,
    MAX_BLOCK_WEIGHT,
    COINBASE_MATURITY);

void conforksus_init(int current_height, bool is_regtest)
{
    if (is_regtest && FORK_ALLOWED) {
        // we do all forks at block 500 in regtest mode
        FORK_BLOCK = 500;
    }
    if (current_height >= FORK_BLOCK) {
        // we are beyond the fork point; use new rules
        fork_conforksus.enable();
    }
}
