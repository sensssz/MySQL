/*****************************************************************************

Copyright (c) 1996, 2009, Oracle and/or its affiliates. All Rights Reserved.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; version 2 of the License.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Suite 500, Boston, MA 02110-1335 USA

*****************************************************************************/

/**************************************************//**
@file include/lock0types.h
The transaction lock system global types

Created 5/7/1996 Heikki Tuuri
*******************************************************/

#ifndef lock0types_h
#define lock0types_h
#include "ut0rnd.h"
#include "univ.i"
#include <vector>
#include <list>

using std::vector;
using std::list;

#define lock_t ib_lock_t
struct lock_t;
struct lock_sys_t;

/* Basic lock modes */
enum lock_mode {
	LOCK_IS = 0,	/* intention shared */
	LOCK_IX,	/* intention exclusive */
	LOCK_S,		/* shared */
	LOCK_X,		/* exclusive */
	LOCK_AUTO_INC,	/* locks the auto-inc counter of a table
			in an exclusive mode */
	LOCK_NONE,	/* this is used elsewhere to note consistent read */
	LOCK_NUM = LOCK_NONE, /* number of lock modes */
	LOCK_NONE_UNSET = 255
};

struct struct_lock_info
{
    ulint space_id;
    ulint page_no;
    ulint heap_no;
    ulint type_mode;
    
    bool operator==(const struct struct_lock_info &lock_info) const
    {
        return space_id == lock_info.space_id && page_no == lock_info.page_no
        && heap_no == lock_info.heap_no && type_mode == lock_info.type_mode;
    }
};
typedef struct_lock_info lock_info;

struct struct_record_lock
{
    lock_info info;
    list<long> waiting_times;
};
typedef struct struct_record_lock record_lock;

struct struct_lock_request
{
    record_lock *lock;
    const lock_t *lock_object;
    timespec start_waiting_time;
};
typedef struct struct_lock_request lock_request;

namespace std
{
    template<>
    struct hash<lock_info>
    {
        ulint operator()(const struct struct_lock_info &lock_info) const
        {
            ulint page_fold = ut_fold_ulint_pair(lock_info.space_id, lock_info.page_no);
            ulint record_fold = ut_fold_ulint_pair(lock_info.space_id, lock_info.page_no);
            return ut_fold_ulint_pair(page_fold, record_fold);
        }
    };
}

#endif
