#include "BooksHandler.h"
LIST_STATES_t bookListIsEmpty(Book *listOfBooks)
{
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    if (NULL == listOfBooks)
    {
        returnVal = LIST_EMPTY;
    }
    return returnVal;
}
LIST_STATES_t addBook(Book **listOfBooks)
{
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    if (NULL == listOfBooks)
    {
        returnVal = NULL_PTR;
    }
    else
    {
        Book *newBook = (Book *)malloc(sizeof(Book));
        returnVal = addBookData(newBook);
        newBook->next = *listOfBooks;
        *listOfBooks = newBook;
    }
    return returnVal;
}

LIST_STATES_t addBookData(Book *newBook)
{
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    if (NULL == newBook)
    {
        returnVal = NULL_PTR;
    }
    else
    {
        system("cls");
        printf("Enter a new book data : \n");
        printf("Book Name : ");
        u8 bookName[BOOK_NAME_SIZE];
        gets(bookName);
        printf("Author Name : ");
        u8 authorName[BOOK_NAME_SIZE];
        gets(authorName);
        f32 price;
        printf("Price : ");
        scanf("%f", &price);
        generateBookId(newBook);
        strcpy(newBook->name, bookName);
        strcpy(newBook->author, authorName);
        newBook->pice = price;
        returnVal = LIST_OK;
    }
    return returnVal;
}

LIST_STATES_t viewAllBooks(Book *listOfBooks)
{
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    if (LIST_EMPTY == bookListIsEmpty(listOfBooks))
    {
        returnVal = LIST_EMPTY;
        printf("Sorry, There are no books available!\n");
    }
    else
    {
        system("cls");
        while (NULL != listOfBooks)
        {
            printf("Book no. is %lu\n", listOfBooks->id);
            printf("Book name is %s\n", listOfBooks->name);
            printf("Book author is %s\n", listOfBooks->author);
            printf("Book price is %5.2f\n", listOfBooks->pice);
            printf("------------------------------------\n");
            listOfBooks = listOfBooks->next;
        }
    }
    fflush(stdin);
    printf("please press any key to return!");
    getch();
}
LIST_STATES_t generateBookId(Book *book)
{
    LIST_STATES_t returnVal = LIST_OK;
    if (NULL == book)
    {
        returnVal = NULL_PTR;
    }
    else
    {
        time_t t;
        srand((unsigned)time(&t));
        book->id = rand() % 1000 + 1;
    }
    return returnVal;
}