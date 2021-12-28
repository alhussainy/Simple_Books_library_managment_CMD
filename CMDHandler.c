/***********************************************************************************/
/* File Name : CMDHandler.c                                                        */
/* File Info : This file contains CMD handlers functions implementation            */
/* Version   : V1.3                                                                */
/* Date      : 28 Dec 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "CMDHandler.h"
#include "BooksHandler.h"

/***********************************************************************************/
/* Function Name  : showMain                                                       */
/* Function Info  : This function displays the main application options            */
/* Fucntion Input : a pointer to the pointer of the first element of the list      */
/* Function Return: states_T constant indicates the state of the applicatio        */
/*                  (RET_OK,RET_N_OK or RET_EXIT)                                  */
/***********************************************************************************/
states_T showMain(Book **listOfBooksPTR)
{
    /*variable to store the return value*/
    states_T returnValue = RET_OK;
    /*calls system(cls) to clear the screen of the CMD in Windows*/
    system("cls");
    /*prints welcome message to the user*/
    printf("Welcome to Library Management Application\n");
    /*prompts the user to choose an option*/
    printf("please Choose one of the following options : \n");
    printf("1- Add a new book.\n"
           "2- View all books.\n"
           "3- Delete a book.\n"
           "4- Number of available books.\n"
           "5- Exit.\n");
    /*variable to store the user choice*/
    u8 choice;
    /*clears input buffer*/
    fflush(stdin);
    /*gets a character from the user*/
    choice = getch();
    /*calls handleChoice function to call the responding function*/
    returnValue = handleChoice(choice, listOfBooksPTR);
    /*returns the return value*/
    return returnValue;
}
/**************************End showMain function*****************************/

/***********************************************************************************/
/* Function Name  : handleChoice                                                   */
/* Function Info  : This function handles the input from the users to select       */
/*                  the responding function                                        */
/* Fucntion Input : the input choise from the user and a pointer to the pointer of */
/*                  the first element of the list                                  */
/* Function Return: states_T constant indicates the state of the applicatio        */
/*                  (RET_OK,RET_N_OK or RET_EXIT)                                  */
/***********************************************************************************/
states_T handleChoice(u8 choice, Book **listOfBooksPTR)
{
    /*variable to store the return value*/
    states_T returnValue = RET_OK;
    /* Checks if the pointer to pointer passed to the fucntion is NULL or NOT*/
    if (NULL == listOfBooksPTR)
    {
        /* if the if the pointer to pointer is NULL, Return NULL_PTR state*/
        returnValue = NULL_PTR;
    }
    else
    {
        /*switch the input value from the user*/
        switch (choice)
        {
        /*handles option 1 and calls addBook fucntion*/
        case '1':
            addBook(listOfBooksPTR);
            break;
        /*handles option 2 and calls viewAllBooks fucntion*/
        case '2':
            viewAllBooks(*listOfBooksPTR, BOOKS_VIEW_ALL);
            break;
        /*handles option 3 and calls deleteBook fucntion*/
        case '3':
            deleteBook(listOfBooksPTR);
            break;
        /*handles option 4 and calls countAvailableBooks fucntion*/
        case '4':
            countAvailableBooks(*listOfBooksPTR);
            break;
        /*handles option 5 and returns RET_EXIT*/
        case '5':
            returnValue = RET_EXIT;
            break;
        /*handles any other input form the user and returns RET_N_OK constant*/
        default:
            returnValue = RET_N_OK;
            break;
        }
    }
    /*returns the return value*/
    return returnValue;
}
/**************************End handleChoice function*****************************/