// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../Data.h"

namespace TW::Avalanche {

// clang-format off

enum CredentialTypeID {
    SECPCred = 9,
    NFTCred = 14,
};

// clang-format on

class Credential {
  public:
    uint32_t typeID;
    std::vector<Data> signatures;

    /// Encodes the Credential into the provided buffer.
    void encode(Data& data) const;

    bool operator<(const Credential& other) const;

  protected:
    Credential(uint32_t typeID, std::vector<Data>& sigs) : typeID(typeID), signatures(sigs) {}
};

class SECP256k1Credential : public Credential {
  public:
    SECP256k1Credential(std::vector<Data>& sigs) : Credential(CredentialTypeID::SECPCred, sigs) {}
};

class NFTCredential : public Credential {
  public:
    NFTCredential(std::vector<Data>& sigs) : Credential(CredentialTypeID::NFTCred, sigs) {}
};

} // namespace TW::Avalanche
