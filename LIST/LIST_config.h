/*****************************************************************************
* @file:    LIST_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			   This is free software: you are free to change and redistribute it.  
*			   There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   List module: Array based and Linked based methods are supported
******************************************************************************/
#ifndef _LIST_CONFIG_H
#define _LIST_CONFIG_H

#include  "LIST_private.h"

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/* Select Which Type of Implementation You Need
   Options: ARRAY_BASED
            LINKED_BASED
*/
#define L_IMPLEMENTATION_METHOD L_ARRAY_BASED

#if L_IMPLEMENTATION_METHOD == L_ARRAY_BASED
   // Define size of array
   #define MAX_LIST 100
#endif

// Define entry type
typedef u8 ListEntry_type;

#endif



