//
// Aspia Project
// Copyright (C) 2019 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "crypto/message_decryptor_openssl.h"

#include "base/logging.h"
#include "crypto/large_number_increment.h"
#include "crypto/secure_memory.h"

#include <openssl/evp.h>

namespace crypto {

namespace {

const int kKeySize = 32; // 256 bits, 32 bytes.
const int kIVSize = 12; // 96 bits, 12 bytes.
const int kTagSize = 16; // 128 bits, 16 bytes.

} // namespace

MessageDecryptorOpenssl::MessageDecryptorOpenssl(EVP_CIPHER_CTX_ptr ctx, const base::ByteArray& iv)
    : ctx_(std::move(ctx)),
      iv_(iv)
{
    DCHECK_EQ(EVP_CIPHER_CTX_key_length(ctx_.get()), kKeySize);
    DCHECK_EQ(EVP_CIPHER_CTX_iv_length(ctx_.get()), kIVSize);
}

MessageDecryptorOpenssl::~MessageDecryptorOpenssl()
{
    memZero(&iv_);
}

// static
std::unique_ptr<MessageDecryptor> MessageDecryptorOpenssl::createForAes256Gcm(
    const base::ByteArray& key, const base::ByteArray& iv)
{
    if (key.size() != kKeySize || iv.size() != kIVSize)
        return nullptr;

    EVP_CIPHER_CTX_ptr ctx =
        createCipher(CipherType::AES256_GCM, CipherMode::DECRYPT, key, kIVSize);
    if (!ctx)
        return nullptr;

    return std::unique_ptr<MessageDecryptor>(new MessageDecryptorOpenssl(std::move(ctx), iv));
}

// static
std::unique_ptr<MessageDecryptor> MessageDecryptorOpenssl::createForChaCha20Poly1305(
    const base::ByteArray& key, const base::ByteArray& iv)
{
    if (key.size() != kKeySize || iv.size() != kIVSize)
        return nullptr;

    EVP_CIPHER_CTX_ptr ctx =
        createCipher(CipherType::CHACHA20_POLY1305, CipherMode::DECRYPT, key, kIVSize);
    if (!ctx)
        return nullptr;

    return std::unique_ptr<MessageDecryptor>(new MessageDecryptorOpenssl(std::move(ctx), iv));
}

size_t MessageDecryptorOpenssl::decryptedDataSize(size_t in_size)
{
    return in_size - kTagSize;
}

bool MessageDecryptorOpenssl::decrypt(const uint8_t* in, size_t in_size, uint8_t* out)
{
    if (EVP_DecryptInit_ex(ctx_.get(), nullptr, nullptr, nullptr, iv_.data()) != 1)
    {
        LOG(LS_WARNING) << "EVP_DecryptInit_ex failed";
        return false;
    }

    int length;

    if (EVP_DecryptUpdate(ctx_.get(), out, &length, in + kTagSize, in_size - kTagSize) != 1)
    {
        LOG(LS_WARNING) << "EVP_DecryptUpdate failed";
        return false;
    }

    if (EVP_CIPHER_CTX_ctrl(ctx_.get(), EVP_CTRL_AEAD_SET_TAG, kTagSize,
                            const_cast<uint8_t*>(in)) != 1)
    {
        LOG(LS_WARNING) << "EVP_CIPHER_CTX_ctrl failed";
        return false;
    }

    if (EVP_DecryptFinal_ex(ctx_.get(), out + length, &length) <= 0)
    {
        LOG(LS_WARNING) << "EVP_DecryptFinal_ex failed";
        return false;
    }

    largeNumberIncrement(&iv_);
    return true;
}

} // namespace crypto
