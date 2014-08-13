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
#ifndef ADDRESS_HPP
#define ADDRESS_HPP

#include <iostream>
#include <string>
#include <bitcoin/bitcoin.hpp>
#include <sx/define.hpp>
#include <sx/serializer/ec_private.hpp>
#include <sx/serializer/ec_public.hpp>

/* NOTE: don't declare 'using namespace foo' in headers. */

namespace sx {
namespace serializer {

/**
 * Serialization helper to convert between base58 string and payment_address.
 */
class address
{
public:

    /**
     * Default constructor.
     */
    address();

    /**
     * Initialization constructor.
     * @param[in]  base58  The value to initialize with.
     */
    address(const std::string& base58);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    address(const bc::payment_address& value);

    /**
     * Copy constructor.
     * @param[in]  other  The object to copy into self on construct.
     */
    address(const address& other);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    address(const libwallet::hd_private_key& value);

    /**
     * Initialization constructor.
     * @param[in]  value  The value to initialize with.
     */
    address(const libwallet::hd_public_key& value);

    /**
     * Return a reference to the data member.
     * @return  A reference to the object's internal data.
     */
    bc::payment_address& data();

    /**
     * Overload cast to internal type.
     * @return  This object's value cast to internal type.
     */
    operator const bc::payment_address&() const;

    /**
     * Overload stream in. Throws if input is invalid.
     * @param[in]   input     The input stream to read the value from.
     * @param[out]  argument  The object to receive the read value.
     * @return                The input stream reference.
     */
    friend std::istream& operator>>(std::istream& input, address& argument);

    /**
     * Overload stream out.
     * @param[in]   output    The output stream to write the value to.
     * @param[out]  argument  The object from which to obtain the value.
     * @return                The output stream reference.
     */
    friend std::ostream& operator<<(std::ostream& output,
        const address& argument);

private:

    /**
     * The state of this object.
     */
    bc::payment_address value_;
};

} // sx
} // serializer

#endif