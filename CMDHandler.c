#include "CMDHandler.h"
#include "BooksHandler.h"
states_T showMain(Book **listOfBooks)
{
    states_T returnValue = RET_OK;
    system("cls");
    printf("Welcome to Library Management Application\n");
    printf("please Choose one of the following options : \n");
    printf("1- Add a new book.\n"
           "2- View all books.\n"
           "3- Delete a book.\n"
           "4- Number of available books.\n"
           "5- Exit.\n");
    u8 choice;
    choice = getch();
    returnValue = handleChoice(choice, listOfBooks);
    return returnValue;
}

states_T handleChoice(u8 choice, Book **listOfBooks)
{
    states_T returnValue = RET_OK;
    switch (choice)
    {
    case '1':
        addBook(listOfBooks);
        break;
    case '2':
        viewAllBooks(*listOfBooks);
        break;
    case '3':
        printf("Delete a book.\n");
        break;
    case '4':
        printf("Number of available books.\n");
        break;
    case '5':
        returnValue = RET_EXIT;
        break;
    default:
        returnValue = RET_N_OK;
        break;
    }
    return returnValue;
}