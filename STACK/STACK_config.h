/*****************************************************************************
* @file:    STACK_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			   This is free software: you are free to change and redistribute it.  
*			   There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   Stack module: Array based and Linked based methods are supported
******************************************************************************/
#ifndef _STACK_CONFIG_H_
#define _STACK_CONFIG_H_

#include  "STACK_private.h"

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/* Select Which Type of Implementation You Need
   Options: ARRAY_BASED
            LINKED_BASED
*/
#define IMPLEMENTATION_METHOD LINKED_BASED

#if IMPLEMENTATION_METHOD == ARRAY_BASED
   // Define stack size
   #define MAX_STACK 100
#endif

// Define entry type
typedef u8 StackEntry_type;

#endif
