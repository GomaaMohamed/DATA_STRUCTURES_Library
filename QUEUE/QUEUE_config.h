/***************************************/
/* Author  :Gomaa                      */
/* Date    :1 Aug 2021                 */
/* Version :V01                        */
/***************************************/

#ifndef _QUEUE_CONFIG_H_
#define _QUEUE_CONFIG_H_

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
#define MAX_QUEUE 100
#endif

// define the type of the element that will be pushed
typedef u8 Queue_Entry;

#endif
