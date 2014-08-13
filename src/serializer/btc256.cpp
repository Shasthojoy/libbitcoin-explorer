/**
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "precompile.hpp"
#include <sx/serializer/btc256.hpp>

#include <iostream>
#include <sstream>
#include <string>
#include <boost/program_options.hpp>
#include <bitcoin/bitcoin.hpp>
#include <sx/define.hpp>
#include <sx/serializer/hex.hpp>

using namespace bc;
using namespace po;

namespace sx {
namespace serializer {

btc256::btc256()
    : value_()
{
}

btc256::btc256(const std::string& hexcode)
{
    std::stringstream(hexcode) >> *this;
}

btc256::btc256(const hash_digest& value)
    : value_(value)
{
}

btc256::btc256(const btc256& other)
    : btc256(other.value_)
{
}

hash_digest& btc256::data()
{
    return value_;
}

btc256::operator const hash_digest&() const
{
    return value_; 
}

//btc256::operator const std::string() const
//{
//    std::stringstream result;
//    result << *this;
//    return result.str();
//}

std::istream& operator>>(std::istream& input, btc256& argument)
{
    std::string hexcode;
    input >> hexcode;

    auto hash = decode_hash(hexcode);
    if (hash == null_hash)
        throw invalid_option_value(hexcode);

    std::copy(hash.begin(), hash.end(), argument.value_.begin());
    return input;
}

std::ostream& operator<<(std::ostream& output, const btc256& argument)
{
    output << hex(argument.value_);
    return output;
}

} // sx
} // serializer