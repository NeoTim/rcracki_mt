/*
 * authors have been contacted and the code in this file has been approved
 * for gpl 2/3
 *
 * rcracki_mt is a multithreaded implementation and fork of the original 
 * RainbowCrack
 *
 * Copyright (C) Zhu Shuanglei <shuanglei@hotmail.com>
 * Copyright Martin Westergaard Jørgensen <martinwj2005@gmail.com>
 * Copyright 2009, 2010 Daniël Niggebrugge <niggebrugge@fox-it.com>
 * Copyright 2009, 2010 James Nobis <frt@quelrod.net>
 *
 * This file is part of racrcki_mt.
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

#ifndef _CRACKENGINE_H
#define _CRACKENGINE_H

#include "Public.h"
#include "HashSet.h"
#include "ChainWalkContext.h"
#include "MemoryPool.h"
#include "ChainWalkSet.h"
#include "rcrackiThread.h"
#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif
#include <pthread.h>

class CCrackEngine
{
public:
	CCrackEngine();
	virtual ~CCrackEngine();

private:
	CChainWalkSet m_cws;
	int maxThreads;
	uint64 maxMem;
	bool writeOutput;
	bool resumeSession;
	string outputFile;
	string sSessionPathName;
	string sProgressPathName;
	string sPrecalcPathName;
	//string sPrecalcIndexPathName;
	bool debug;
	bool keepPrecalcFiles;

	// Statistics
	float m_fTotalDiskAccessTime;
	float m_fTotalCryptanalysisTime;
	int m_nTotalChainWalkStep;
	int m_nTotalFalseAlarm;
	int m_nTotalChainWalkStepDueToFalseAlarm;
	FILE *m_fChains;

private:
	void ResetStatistics();
	RainbowChain *BinarySearch(RainbowChain *pChain, int nChainCountRead, uint64 nIndex, IndexChain *pIndex, int nIndexSize, int nIndexStart);
	int BinarySearchOld(RainbowChainO* pChain, int nRainbowChainCount, uint64 nIndex);
	void GetChainIndexRangeWithSameEndpoint(RainbowChainO* pChain,
										    int nRainbowChainCount,
										    int nChainIndex,
										    int& nChainIndexFrom,
										    int& nChainIndexTo);
	void SearchTableChunk(RainbowChain* pChain, int nRainbowChainLen, int nRainbowChainCount, CHashSet& hs, IndexChain *pIndex, int nIndexSize, int nChainStart);
	void SearchTableChunkOld(RainbowChainO* pChain, int nRainbowChainLen, int nRainbowChainCount, CHashSet& hs);
	//bool CheckAlarm(RainbowChain* pChain, int nGuessedPos, unsigned char* pHash, CHashSet& hs);
	//bool CheckAlarmOld(RainbowChainO* pChain, int nGuessedPos, unsigned char* pHash, CHashSet& hs);

public:
	void SearchRainbowTable(string sPathName, CHashSet& hs);
	void Run(vector<string> vPathName, CHashSet& hs, int i_maxThreads, uint64 i_maxMem, bool resume, bool bDebug);
	float GetStatTotalDiskAccessTime();
	float GetStatTotalCryptanalysisTime();
	int   GetStatTotalChainWalkStep();
	int   GetStatTotalFalseAlarm();
	int   GetStatTotalChainWalkStepDueToFalseAlarm();
	void setOutputFile(string sPathName);
	void setSession(string sSessionPathName, string sProgressPathName, string sPrecalcPathName, bool keepPrecalc);
};

#endif