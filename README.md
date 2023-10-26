# DATA_STRUCTURES_Library
```
>> This is a C library that provides implementations of basic data structures,
   including a stack, queue, and list. 
>> The library allows you to choose between two different implementation methods:
   array-based or linked-list-based.
```
## Installation
```
>> To use this library in your C project, simply download the source code or
   clone this repository. 
>> You can then include the header files (STACK_interface.h, QUEUE_interface.h, and LIST_interface.h)
   in your code 
```
## Usage
#### To use the data structures provided by this library, follow these steps:
```
>> Create a new instance of the data structure and initialize it using one of the provided 
   creation functions (e.g., Stack_Create, Queue_Create, or List_Create).
>> Use the various functions provided by the library to manipulate the data structure
   (e.g., STACK_Push, Queue_Append, or List_Insert).
```
## Configuration
```
>> The library provides configuration options that allow you to choose between array-based or
   linked-list-based implementations of the data structures. 
>> By default, the library is configured to use Array-based implementations.
>> To configure the library to use array-based implementations, you must define the
   IMPLEMENTATION_METHOD macro located in STACK_config.h, QUEUE_config.h, and LIST_config.h.
```
