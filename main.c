#include "main.h"

int main(void)
{
    Book *BookList = NULL;
    states_T programStat = RET_OK;
    while (programStat == RET_OK)
    {
        programStat = showMain(&BookList);
        if (RET_EXIT == programStat)
        {
            printf("See you later!\n");
            exit(EXIT_SUCCESS);
        }
    }

    return 0;
} //end of main functin