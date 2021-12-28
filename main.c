/***********************************************************************************/
/* File Name : main.c                                                              */
/* File Info : This file contains main function of the application                 */
/* Version   : V1.3                                                                */
/* Date      : 28 Dec 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "main.h"

/***********************************************************************************/
/* Function Name  : main                                                           */
/* Function Info  : This function is the main function of the application          */
/* Fucntion Input : None                                                           */
/* Function Return: integer value indicates the state of the application execution */
/***********************************************************************************/
int main(void)
{
    /*The pointer to the list of the book*/
    /*initial is NULL to indicate that the list is empty*/
    Book *BookList = NULL;
    /*variable to store the state of the application*/
    states_T programStat = RET_OK;
    /*infinite while loop to make the application alive as long as the user did not*/
    /*choose to exit form the application*/
    while (1)
    {
        /*calls the main handler and gets the states of the program*/
        programStat = showMain(&BookList);
        /*checks if the return value is equal to RET_EXIT*/
        if (RET_EXIT == programStat)
        {
            /*prints See you later to the user*/
            printf("See you later!\n");
            /*calls exit function to terminate the application with success state*/
            exit(EXIT_SUCCESS);
        }
    }
    return 0;
}
/**************************End main function*****************************/