/*
 * Fast implementation of the MD5 message-digest algorithm as per RFC
 * (see http://tools.ietf.org/html/rfc1321)
 *
 * Author: Joao Inacio <jcinacio at gmail.com>
 * License: Use and share as you wish at your own risk, please keep this header ;)
 *
 * Optimizations:
 *  - For lengths < 16, transformation steps are "unrolled" using macros/defines
 *  - Constants used whenever possible, it's the compiler's job to sort them out
 *  - Padding is done on 4-byte words, and memory copied as last resort.
 * 
 * Copyright 2009, 2010 Daniël Niggebrugge <niggebrugge@fox-it.com>
 * Copyright 2009, 2010 James Nobis <frt@quelrod.net>
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

#ifndef FAST_MD5_H
#define FAST_MD5_H

#include "global.h"

#define MD5_DIGEST_LENGTH 16

void fast_MD5(unsigned char *pData, int len, unsigned char *pDigest);

#endif // FAST_MD5_H
