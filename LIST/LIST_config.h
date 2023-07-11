/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _LIST_CONFIG_H_
#define _LIST_CONFIG_H_

#include  "LIST_private.h"

/* Select Which Type of Implementation You Need
   Options: ARRAY_BASED
            LINKED_BASED
*/
#define L_IMPLEMENTATION_METHOD L_ARRAY_BASED

#if L_IMPLEMENTATION_METHOD == L_ARRAY_BASED
#define MAX_LIST 100
#endif

typedef u8 List_Entry;

#endif



