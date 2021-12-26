#ifndef BOOKSHANDLER_H
#define BOOKSHANDLER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "STD_DataTypes.h"

#ifndef BOOK_NAME_SIZE
#define BOOK_NAME_SIZE 20
#endif

#ifndef AUTHOR_NAME_SIZE
#define AUTHOR_NAME_SIZE 20
#endif

typedef struct book
{
    u32 id;
    u8 name[BOOK_NAME_SIZE];
    u8 author[AUTHOR_NAME_SIZE];
    f32 pice;
    struct book *next;
} Book;

typedef enum
{
    LIST_EMPTY,
    LIST_N_EMPTY,
    NULL_PTR,
    ERR,
    LIST_OK
} LIST_STATES_t;

LIST_STATES_t bookListIsEmpty(Book *listOfBooks);
LIST_STATES_t addBook(Book **listOfBooks);
LIST_STATES_t addBookData(Book *newBook);
LIST_STATES_t viewAllBooks(Book *listOfBooks);
LIST_STATES_t generateBookId(Book *book);
#endif