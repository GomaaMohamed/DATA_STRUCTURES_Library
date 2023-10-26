/*****************************************************************************
* @file:    QUEUE_config.h
* @author:  Copyright (c) 2023 Gomaa Mohammed Gomaa.
* @license: GNU GPL version 3 or later.
*			   This is free software: you are free to change and redistribute it.  
*			   There is NO WARRANTY, to the extent permitted by law.
* @version: V0.2   
* @date:    Tue, 3 Oct 2023 16:21:12 +0200
* @brief:   Queue module: Array based and Linked based methods are supported
******************************************************************************/
#ifndef _QUEUE_CONFIG_H
#define _QUEUE_CONFIG_H

#include  "QUEUE_private.h"

/* ==================================================================== */
/* =================== Configurations Selection ======================= */
/* ==================================================================== */

/* Select Which Type of Implementation You Need
   Options: Q_ARRAY_BASED
            Q_LINKED_BASED
*/
#define Q_IMPLEMENTATION_METHOD Q_LINKED_BASED

// if the ARRAY_BASED method is selected, you have to define the size of array 
#if Q_IMPLEMENTATION_METHOD == Q_ARRAY_BASED
   // Determine queue size
   #define MAX_QUEUE 100
#endif

// define the type of the element that will be pushed
typedef u8 QueueEntry_type;

#endif
