/***********************************************************************************/
/* File Name : BooksHandler.c                                                      */
/* File Info : This file contains books handlers functions implementation          */
/* Version   : V1.3                                                                */
/* Date      : 28 Dec 2021                                                         */
/* Author    : Alhussainy Khaled Anwar                                             */
/***********************************************************************************/

/***********************************************************************************/
/*********************************Linking Section***********************************/
/***********************************************************************************/
#include "BooksHandler.h"

/***********************************************************************************/
/* Function Name  : bookListIsEmpty                                                */
/* Function Info  : This function checks if the list of books is empty or not      */
/* Fucntion Input : First element it the list of books                             */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY or LIST_EMPTY)                                   */
/***********************************************************************************/
LIST_STATES_t bookListIsEmpty(Book *listOfBooks)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_N_EMPTY;

    /* Checks if the first element of the list is NULL or NOT*/
    if (NULL == listOfBooks)
    {
        /* if the first element points to NULL, The list is empyt*/
        returnVal = LIST_EMPTY;
    }
    /*returns the return value*/
    return returnVal;
}
/**************************End bookListIsEmpty function*****************************/

/***********************************************************************************/
/* Function Name  : addBook                                                        */
/* Function Info  : This function adds a new book to the list                      */
/* Fucntion Input : Pointer to pointer of the first element in the list            */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, ERR or LIST_OK)                                 */
/***********************************************************************************/
LIST_STATES_t addBook(Book **listOfBooksPTR)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_N_EMPTY;

    /* Checks if the pointer to pointer passed to the fucntion is NULL or NOT*/
    if (NULL == listOfBooksPTR)
    {
        /* if the if the pointer to pointer is NULL, Return NULL_PTR state*/
        returnVal = NULL_PTR;
    }
    else
    {
        /*Dynamic allocation for new book node */
        Book *newBook = (Book *)malloc(sizeof(Book));
        /*checks if the dynamic allocation failed by checking for NULL pointer*/
        if (NULL == newBook)
        {
            printf("Could not added the new book!\n");
            /* if the dynamic allocation failed, Make return value equal ERR constant*/
            returnVal = ERR;
        }
        else
        {
            /*Calls addBookData function to add new data to the node*/
            returnVal = addBookData(newBook, *listOfBooksPTR);
            /*makes the new node point to the first node of the list*/
            newBook->next = *listOfBooksPTR;
            /*makes the list pointer point to the new node*/
            *listOfBooksPTR = newBook;
        }
    }
    /*returns the return value*/
    return returnVal;
}
/**************************End addBook function*****************************/

/***********************************************************************************/
/* Function Name  : addBookData                                                    */
/* Function Info  : This function adds data for the new node in the list           */
/* Fucntion Input : Pointer to the new node and pointer to the list                */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, NULL_PTR or LIST_OK)                            */
/***********************************************************************************/
LIST_STATES_t addBookData(Book *newBook, Book *listOfBooks)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    /*checks if the passed pointer to the new node is NULL*/
    /*listOfBooks can be null during addding the first book*/
    if (NULL == newBook)
    {
        /* if the if the pointer to the new node is NULL, Return NULL_PTR state*/
        returnVal = NULL_PTR;
    }
    else
    {
        /*calls system(cls) to clear the screen of the CMD in Windows*/
        system("cls");
        /*prompts the user to enter the data of the new Book*/
        printf("Enter a new book data : \n");
        /*prompts the user to enter the name of the new Book*/
        printf("Book Name : ");
        /*vaiable to store the name of the book*/
        u8 bookName[BOOK_NAME_SIZE];
        /*gets the input string from the user in BookName */
        gets(bookName);
        /*prompts the user to enter the name of the author of the new Book*/
        printf("Author Name : ");
        /*vaiable to store the name of the author*/
        u8 authorName[BOOK_NAME_SIZE];
        /*gets the input string from the user in authorName */
        gets(authorName);
        /*vaiable to store the price of the book*/
        f32 price;
        /*prompts the user to enter the price of the new Book*/
        printf("Price : ");
        /*gets the input price from the user in price */
        scanf("%f", &price);
        /*calls the generateBookId to generate unique ID for the new book*/
        generateBookId(newBook, listOfBooks);
        /*copies the value of the BookName in the new book name member*/
        strcpy(newBook->name, bookName);
        /*copies the value of the authorName in the new book author member*/
        strcpy(newBook->author, authorName);
        /*copies the value of the price in the new book price member*/
        newBook->pice = price;
        /*if all data is set successfully, Makes the return value is LIST_OK*/
        returnVal = LIST_OK;
    }
    /*returns the return value*/
    return returnVal;
}
/**************************End addBookData function*****************************/

/***********************************************************************************/
/* Function Name  : viewAllBooks                                                   */
/* Function Info  : This function views data  of all books in the list             */
/* Fucntion Input : Pointer to the list and books_modes_t constant to indicates    */
/*                  the mode of read books                                         */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, LIST_EMPTY or LIST_OK)                          */
/***********************************************************************************/
LIST_STATES_t viewAllBooks(Book *listOfBooks, books_modes_t mode)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    /*checks if the list of books is empty by calling bookListIsEmpty function*/
    if (LIST_EMPTY == bookListIsEmpty(listOfBooks))
    {
        /*if the list is empty, Makes return value equal LIST_EMPTY constant*/
        returnVal = LIST_EMPTY;
        /*Show that there are no books available to the user*/
        printf("Sorry, There are no books available!\n");
    }
    /*the list contains books*/
    else
    {
        /*calls system(cls) to clear the screen of the CMD in Windows*/
        system("cls");
        /*Iterates as the end of the list (NULL pointer) is not reached*/
        while (NULL != listOfBooks)
        {
            /*prints Book ID to the user*/
            printf("Book ID is %lu\n", listOfBooks->id);
            /*prints Book name to the user*/
            printf("Book name is %s\n", listOfBooks->name);
            /*prints Book author to the user*/
            printf("Book author is %s\n", listOfBooks->author);
            /*prints Book price to the user*/
            printf("Book price is %5.2f\n", listOfBooks->pice);
            /*prints seperating line*/
            printf("------------------------------------\n");
            /*updates the pointer to next node in the list*/
            listOfBooks = listOfBooks->next;
        }
    }
    /*BOOKS_VIEW_ALL constant is used to make the printed list await*/
    if (BOOKS_VIEW_ALL == mode)
    {
        /*prompts the user to press anykey to back*/
        printf("please press any key to return!");
        /*clears input buffer*/
        fflush(stdin);
        /*waits for the user to press a key*/
        getch();
    }
    /*returns the return value*/
    return returnVal;
}
/**************************End viewAllBooks function*****************************/

/***********************************************************************************/
/* Function Name  : generateBookId                                                 */
/* Function Info  : This function generates unique ID for new inserted books       */
/* Fucntion Input : Pointer to the list and pointer to the new created book        */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (NULL_PTR or LIST_OK)                                          */
/***********************************************************************************/
LIST_STATES_t generateBookId(Book *book, Book *listOfBooks)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_OK;
    /*checks is the passed pointer to the new book is NULL*/
    if (NULL == book)
    {
        /*if  the passed pointer is NULL, Makes the return value NULL_PRT*/
        returnVal = NULL_PTR;
    }
    /*The passed pointer is not NULL*/
    else
    {
        /*variable  to store the result of the SearchForBook function*/
        Search_states_t res;
        /*By default a random new ID must be assigned, then checks if it's duplicated */
        do
        {
            /*variable to store the seed of srand fucntion*/
            time_t t;
            /*current time as a seed for random generator*/
            srand((unsigned)time(&t));
            /*gets random number in range from 1 to 1000*/
            book->id = rand() % 1000 + 1;
            /*searches if the generated ID is duplicated*/
            res = SearchForBook(book->id, listOfBooks);
            /*repeats if only the ID is found in previous book to generate a new unique one*/
        } while (FOUND == res);
    }
    /*returns the return value*/
    return returnVal;
}
/**************************End generateBookId function*****************************/

/***********************************************************************************/
/* Function Name  : SearchForBook                                                  */
/* Function Info  : This function searches for a book in the list by ID            */
/* Fucntion Input : BookID and a pointer to the start of the list                  */
/* Function Return: Search_states_t constant indicates the result of the search    */
/*                  (NOT_FOUND or FOUND)                                           */
/***********************************************************************************/
Search_states_t SearchForBook(u32 BookID, Book *listOfBooks)
{
    /* return value to indicate the state of search*/
    Search_states_t searchRes = NOT_FOUND;
    /*checks if the passed pointer is NULL*/
    if (NULL == listOfBooks)
    {
        /*prints that the passed pointer is NULL*/
        printf("NULL pointer is passed to SearchForBook Fun!\n");
    }
    else
    {
        /*iterates until the end of the list*/
        while (NULL != listOfBooks)
        {
            /*checks if the ID is found in the list*/
            if (listOfBooks->id == BookID)
            {
                /*sets the search result to FOUND constant to indicate that */
                /*the book ID is found*/
                searchRes = FOUND;
                /*breaks the while loop*/
                break;
            }
            /*updates the iterator to the next book*/
            listOfBooks = listOfBooks->next;
        }
    }
    /*returns the return value*/
    return searchRes;
}
/**************************End SearchForBook function*****************************/

/***********************************************************************************/
/* Function Name  : deleteBook                                                     */
/* Function Info  : This function deletes a book in the list                       */
/* Fucntion Input : a pointer to the pointer of the first element of the list      */
/* Function Return: Search_states_t constant indicates the result of the search    */
/*                  (LIST_OK, NULL_PTR,ERR or LIST_EMPTY)                          */
/***********************************************************************************/
LIST_STATES_t deleteBook(Book **listOfBooksPTR)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_OK;
    /*checks if the passed pointer is NULL*/
    if (NULL == listOfBooksPTR)
    {
        /*if the passed pointer is NULL, makes the return value is NULL_PTR*/
        returnVal = NULL_PTR;
    }
    /*The passed pointer is not NULL*/
    else
    {
        /*calls bookListIsEmpty function to check if the list is empty*/
        if (LIST_EMPTY == bookListIsEmpty(*listOfBooksPTR))
        {
            /*if the list is empty, make the return value LIST_EMPTY*/
            returnVal = LIST_EMPTY;
            /*prints to the user that there are no books available*/
            printf("Sorry, There are no books available!\n");
        }
        /*the list is not empty*/
        else
        {
            /*calls viewAllBooks function to view all books*/
            viewAllBooks(*listOfBooksPTR, BOOK_DELETE);
            /*prompts the user to enter the id of the book to be deleted*/
            printf("please Enter the ID of the book to be deleted : ");
            /*variable to store the ID of the book*/
            u32 toBeRemovedID;
            /*store the input value from the user*/
            scanf("%lu", &toBeRemovedID);
            /*creates a new iterator for the list to delete the book*/
            Book *currentBook = *listOfBooksPTR;
            /*creates a helper pointer to delete the book */
            Book *preBook = currentBook;
            /*iterates as long as the end of the list is not reached */
            /*or the required id is found*/
            while ((NULL != currentBook) && (currentBook->id != toBeRemovedID))
            {
                /*updates the previous pointer*/
                preBook = currentBook;
                /*updates the current pointer to the next book*/
                currentBook = currentBook->next;
            }
            /*checks if the ID is found or not*/
            if (NULL == currentBook)
            {
                /*prints to the user that book id is not found*/
                printf("Book ID is not found!\n");
                /*makes the return value equal to ERR constant*/
                returnVal = ERR;
            }
            /*the required ID is found*/
            else
            {
                /*checks if the required book is at the start of the list*/
                if (preBook == currentBook)
                {
                    /*updates the pointer to the first element*/
                    *listOfBooksPTR = currentBook->next;
                }
                /*the required book is not at the start of the list*/
                else
                {
                    /*make the previous book node points to the next book*/
                    preBook->next = currentBook->next;
                }
                /*calls free to free the found book*/
                free(currentBook);
                /*prints to the user that the book is deleted*/
                printf("Book with ID = %lu is successfully deleted!\n", toBeRemovedID);
                /*makes the return value equal to LIST_OK constant*/
                returnVal = LIST_OK;
            }
        }
    }
    /*prompts the user to press anykey to back*/
    printf("please press any key to return!");
    /*clears input buffer*/
    fflush(stdin);
    /*waits for the user to press a key*/
    getch();
    /*returns the return value*/
    return returnVal;
}
/**************************End SearchForBook function*****************************/

/***********************************************************************************/
/* Function Name  : countAvailableBooks                                            */
/* Function Info  : This function counts all books in the list                     */
/* Fucntion Input : Pointer to the list                                            */
/* Function Return: LIST_STATES_t constant indicates the state of the list         */
/*                  (LIST_N_EMPTY, LIST_EMPTY or LIST_OK)                          */
/***********************************************************************************/
LIST_STATES_t countAvailableBooks(Book *listOfBooks)
{
    /* return value to indicate the state of list*/
    LIST_STATES_t returnVal = LIST_N_EMPTY;
    /*calls system(cls) to clear the screen of the CMD in Windows*/
    system("cls");
    /*checks if the list of books is empty by calling bookListIsEmpty function*/
    if (LIST_EMPTY == bookListIsEmpty(listOfBooks))
    {
        /*if the list is empty, Makes return value equal LIST_EMPTY constant*/
        returnVal = LIST_EMPTY;
        /*Show that there are no books available to the user*/
        printf("Sorry, There are no books available!\n");
    }
    /*the list contains books*/
    else
    {
        /*variable to store the number of books*/
        u32 numOfBooks = 0;
        /*Iterates as the end of the list (NULL pointer) is not reached*/
        while (NULL != listOfBooks)
        {
            /*increments the counter*/
            numOfBooks++;
            /*updates the pointer to next node in the list*/
            listOfBooks = listOfBooks->next;
        }
        /*prints the number of available books*/
        printf("There are %lu books available!\n", numOfBooks);
        /*makes the return value LIST_OK constant*/
        returnVal = LIST_OK;
    }

    /*prompts the user to press anykey to back*/
    printf("please press any key to return!");
    /*clears input buffer*/
    fflush(stdin);
    /*waits for the user to press a key*/
    getch();

    /*returns the return value*/
    return returnVal;
}
/**************************End countAvailableBooks function*****************************/