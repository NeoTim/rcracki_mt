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

#ifndef _HASHALGORITHM_H
#define _HASHALGORITHM_H

void HashLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashNTLM(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashMD2(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashMD4(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashDoubleMD5(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
//void HashRIPEMD160(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashMSCACHE(unsigned char *pPlain, int nPlainLen, unsigned char* pHash);
//****************************************************************************
// MySQL Password Hashing
//****************************************************************************
void HashMySQL323(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashMySQLSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);

//****************************************************************************
// Cisco PIX Password Hashing
//****************************************************************************
void HashPIX(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);

//****************************************************************************
// (HALF) LM CHALL hashing
void HashLMCHALL(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashHALFLMCHALL(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);

// From mao
void HashNTLMCHALL(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);
void HashORACLE(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);

#ifndef _WIN32
char *strupr(char *s1);
#endif
#endif
