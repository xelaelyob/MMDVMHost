/*
 *   Copyright (C) 2020 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(M17CRC_H)
#define	M17CRC_H

#include <cstdint>

class CM17CRC
{
public:
	static bool checkCRC(const unsigned char* in, unsigned int nBytes);
	static void encodeCRC(unsigned char* in, unsigned int nBytes);

private:
	static uint16_t createCRC(const unsigned char* in, unsigned int nBytes);
};

#endif
