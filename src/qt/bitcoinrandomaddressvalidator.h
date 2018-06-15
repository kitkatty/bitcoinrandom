// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINRANDOM_QT_BITCOINRANDOMADDRESSVALIDATOR_H
#define BITCOINRANDOM_QT_BITCOINRANDOMADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitcoinRandomAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinRandomAddressEntryValidator(QObject* parent);

    State validate(QString& input, int& pos) const;
};

/** BitcoinRandom address widget validator, checks for a valid bitcoinrandom address.
 */
class BitcoinRandomAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinRandomAddressCheckValidator(QObject* parent);

    State validate(QString& input, int& pos) const;
};

#endif // BITCOINRANDOM_QT_BITCOINRANDOMADDRESSVALIDATOR_H
