/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _STACK_CONFIG_H_
#define _STACK_CONFIG_H_

#include  "STACK_private.h"

/* Select Which Type of Implementation You Need
   Options: ARRAY_BASED
            LINKED_BASED
*/
#define IMPLEMENTATION_METHOD LINKED_BASED

#if IMPLEMENTATION_METHOD == ARRAY_BASED
#define MAX_STACK 100
#endif

typedef u8 Stack_Entry;

#endif
