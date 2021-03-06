/*
 * rcracki_mt is a multithreaded implementation and fork of the original 
 * RainbowCrack
 *
 * Copyright 2010 Martin Westergaard Jørgensen <martinwj2005@gmail.com>
 * Copyright 2010 James Nobis <frt@quelrod.net>
 *
 * This file is part of rcracki_mt.
 *
 * rcracki_mt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * rcracki_mt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rcracki_mt.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RTI2READER_H__
#define __RTI2READER_H__

#include "Public.h"
#include <string>

#if defined(_WIN32) && !defined(__GNUC__)
	#include <io.h>
#endif

#include <vector>
#include "BaseRTReader.h"

using namespace std;

typedef struct 
{
	char header[4];
	unsigned char rti_startptlength, rti_endptlength, rti_cplength, rti_index_numchainslength;
	uint64 prefixstart;
	unsigned int *m_cppos;
} RTI2Header;

class RTI2Reader : BaseRTReader
{
private:
	FILE *m_pFile;
	uint32 m_chainPosition;
	unsigned char *m_pPos, *m_pChainPos;
	static RTI2Header *m_pHeader;
	unsigned char *m_pIndex;
	uint32 m_chainsizebytes;
	uint32 m_indexrowsizebytes;
	

public:
	RTI2Reader(string Filename);
	~RTI2Reader(void);
	int ReadChains(uint32 &numChains, RainbowChainO *pData);
	unsigned int GetChainsLeft();
	static RTI2Header *GetHeader() { return m_pHeader; }
};


#endif
