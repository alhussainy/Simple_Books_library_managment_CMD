/***********************************************************************************/
/* File Name : CMDHandler.h                                                        */
/* File Info : This file contains CMD handlers functions declaration               */
/*             and the user-defined data types                                     */
/* Version   : V1.3                                                                */
/* Date      : 28 Dec 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef CMDHANDLER_H
#define CMDHANDLER_H

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include <stdio.h>
#include <conio.h>
#include "BooksHandler.h"
#include <stdlib.h>
#include "STD_DataTypes.h"

/***********************************************************************************/
/****************************User-defined datatypes*********************************/
/***********************************************************************************/

/*Enum to indicate  the state of the operations*/
typedef enum
{
    RET_OK,
    RET_N_OK,
    RET_NULL_PTR,
    RET_EXIT
} states_T;

/***********************************************************************************/
/* Function Name  : showMain                                                       */
/* Function Info  : This function displays the main application options            */
/* Fucntion Input : a pointer to the pointer of the first element of the list      */
/* Function Return: states_T constant indicates the state of the applicatio        */
/*                  (RET_OK,RET_N_OK or RET_EXIT)                                  */
/***********************************************************************************/
states_T showMain(Book **listOfBooksPTR);

/***********************************************************************************/
/* Function Name  : handleChoice                                                   */
/* Function Info  : This function handles the input from the users to select       */
/*                  the responding function                                        */
/* Fucntion Input : the input choise from the user and a pointer to the pointer of */
/*                  the first element of the list                                  */
/* Function Return: states_T constant indicates the state of the applicatio        */
/*                  (RET_OK,RET_N_OK or RET_EXIT)                                  */
/***********************************************************************************/
states_T handleChoice(u8 choice, Book **listOfBooksPTR);

#endif