#include "blocks.h"

#include <unordered_map>

extern const unsigned char checkpoints[];
extern const size_t checkpoints_len;
extern const unsigned char stagenet_blocks[];
extern const size_t stagenet_blocks_len;
extern const unsigned char testnet_blocks[];
extern const size_t testnet_blocks_len;

namespace blocks
{

  const std::unordered_map<cryptonote::network_type, const epee::span<const unsigned char>, std::hash<size_t>> CheckpointsByNetwork = {
    {cryptonote::network_type::MAINNET, {checkpoints, checkpoints_len}},
    {cryptonote::network_type::STAGENET, {stagenet_blocks, stagenet_blocks_len}},
    {cryptonote::network_type::TESTNET, {testnet_blocks, testnet_blocks_len}}
  };

  const epee::span<const unsigned char> GetCheckpointsData(cryptonote::network_type network)
  {
    // Zerqavon has its own mainnet chain. The inherited Monero
    // checkpoints.dat file contains Monero block hash-of-hashes data and must
    // not be used for Zerqavon mainnet sync validation, otherwise nodes can
    // reject valid Zerqavon peers with "usable is negative".
    if (network == cryptonote::network_type::MAINNET)
    {
      return nullptr;
    }

    const auto it = CheckpointsByNetwork.find(network);
    if (it != CheckpointsByNetwork.end())
    {
      return it->second;
    }
    return nullptr;
  }

}
