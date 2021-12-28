/***********************************************************************************/
/* File Name : BooksHandler.h                                                      */
/* File Info : This file contains books handlers functions declaration             */
/*             and the user-defined data types                                     */
/* Version   : V1.3                                                                */
/* Date      : 28 Dec 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Header File Gaurd*********************************/
/***********************************************************************************/
#ifndef BOOKSHANDLER_H
#define BOOKSHANDLER_H

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "STD_DataTypes.h"

/***********************************************************************************/
/****************************Macro Constant Definition******************************/
/***********************************************************************************/

/*the size of the name of the book*/
#ifndef BOOK_NAME_SIZE
#define BOOK_NAME_SIZE 20
#endif
/*the size of the name of the author*/
#ifndef AUTHOR_NAME_SIZE
#define AUTHOR_NAME_SIZE 20
#endif

/***********************************************************************************/
/****************************User-defined datatypes*********************************/
/***********************************************************************************/

/*The struct of the node of the linked list of the books*/
typedef struct book
{
    u32 id;
    u8 name[BOOK_NAME_SIZE];
    u8 author[AUTHOR_NAME_SIZE];
    f32 pice;
    struct book *next;
} Book;

/*Enum to indicate  the state of the list operations*/
typedef enum
{
    LIST_EMPTY,
    LIST_N_EMPTY,
    NULL_PTR,
    ERR,
    LIST_OK
} LIST_STATES_t;

/*Enum to indicate  the state of the mode of reads the list of the books*/
typedef enum
{
    BOOK_VIEW,
    BOOK_DELETE,
    BOOKS_VIEW_ALL
} books_modes_t;

/*Enum to indicate  the state of the search operation*/
typedef enum
{
    FOUND,
    NOT_FOUND
} Search_states_t;

/***********************************************************************************/
/****************************Functions Declaration**********************************/
/***********************************************************************************/

/***********************************************************************************/
/* Function Name  : bookListIsEmpty                                                */
/* Function Info  : This function checks if the list of books is empty or not      */
/* Fucntion Input : First element it the list of books                             */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY or LIST_EMPTY)                                   */
/***********************************************************************************/
LIST_STATES_t bookListIsEmpty(Book *listOfBooks);

/***********************************************************************************/
/* Function Name  : addBook                                                        */
/* Function Info  : This function adds a new book to the list                      */
/* Fucntion Input : Pointer to pointer of the first element in the list            */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, ERR or LIST_OK)                                 */
/***********************************************************************************/
LIST_STATES_t addBook(Book **listOfBooks);

/***********************************************************************************/
/* Function Name  : addBookData                                                    */
/* Function Info  : This function adds data for the new node in the list           */
/* Fucntion Input : Pointer to the new node and pointer to the list                */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, NULL_PTR or LIST_OK)                            */
/***********************************************************************************/
LIST_STATES_t addBookData(Book *newBook, Book *listOfBooks);

/***********************************************************************************/
/* Function Name  : viewAllBooks                                                   */
/* Function Info  : This function views data  of all books in the list             */
/* Fucntion Input : Pointer to the list and books_modes_t constant to indicates    */
/*                  the mode of read books                                         */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, LIST_EMPTY or LIST_OK)                          */
/***********************************************************************************/
LIST_STATES_t viewAllBooks(Book *listOfBooks, books_modes_t mode);

/***********************************************************************************/
/* Function Name  : generateBookId                                                 */
/* Function Info  : This function generates unique ID for new inserted books       */
/* Fucntion Input : Pointer to the list and pointer to the new created book        */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (NULL_PTR or LIST_OK)                                          */
/***********************************************************************************/
LIST_STATES_t generateBookId(Book *book, Book *listOfBooks);

/***********************************************************************************/
/* Function Name  : deleteBook                                                     */
/* Function Info  : This function deletes a book in the list                       */
/* Fucntion Input : a pointer to the pointer of the first element of the list      */
/* Function Return: Search_states_t constant indicates the result of the search    */
/*                  (LIST_OK, NULL_PTR,ERR or LIST_EMPTY)                          */
/***********************************************************************************/
LIST_STATES_t deleteBook(Book **listOfBooks);

/***********************************************************************************/
/* Function Name  : SearchForBook                                                  */
/* Function Info  : This function searches for a book in the list by ID            */
/* Fucntion Input : BookID and a pointer to the start of the list                  */
/* Function Return: Search_states_t constant indicates the result of the search    */
/*                  (NOT_FOUND or FOUND)                                           */
/***********************************************************************************/
Search_states_t SearchForBook(u32 BookID, Book *listOfBooks);

/***********************************************************************************/
/* Function Name  : countAvailableBooks                                            */
/* Function Info  : This function counts all books in the list                     */
/* Fucntion Input : Pointer to the list                                            */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, LIST_EMPTY or LIST_OK)                          */
/***********************************************************************************/
LIST_STATES_t countAvailableBooks(Book *listOfBooks);
#endif