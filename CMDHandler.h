#ifndef CMDHANDLER_H
#define CMDHANDLER_H
#include <stdio.h>

#include <conio.h>
#include "BooksHandler.h"
#include <stdlib.h>
#include "STD_DataTypes.h"
typedef enum
{
    RET_OK,
    RET_N_OK,
    RET_NULL_PTR,
    RET_EXIT
} states_T;

states_T showMain(Book **listOfBooks);
states_T handleChoice(u8 choice, Book **listOfBooks);
#endif