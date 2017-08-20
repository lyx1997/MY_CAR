#include "STU.h"

typedef struct menu_item {
	char *fun;
} MENU_ITEM;


static MENU_ITEM functions[] = {
	{"delete message"}, 
	{"search for message"},
	{"display message"},
	{"change message"},
	{"add message"},
	{"sort message"},
	{"grade section"},
	{"destroy message"},
	{"file backup"},
	{NULL}
};


void menu()
{
	int count = 1;
	MENU_ITEM *item = functions;

    system("title 学生成绩管理系统  By liyixuan");
    printf("*****************************   This is the student's score managerment system!*****************************");
    printf("\n\n\n");
    printf("*****************************   Score message -> There are %d records!         *****************************",numstus);
    printf("\n\n\n");
    printf("*****************************   Student message -> There are %d records!       *****************************",numstus);
    printf("\n\n\n");
    printf("*****************************   This is the menu   please choose a function    *****************************");
    printf("\n\n\n");
    
    while (item->fun != NULL) 
	{
		printf("\t\t\t\t\t%d. %s\n", count, item->fun);
		count++;
		item++;
	}



	/*for(i = 0;i < 7;i++)
    {
        for(j = 0;j < 33;j++)
        {
            if(i == 0)
            {
                printf(" ");
                if(j == 32)
                    printf("1.delete message\n");
            }
            if(i == 1)
            {
                printf(" ");
                if(j == 32)
                    printf("2.search for message\n");
            }
            if(i == 2)
            {
                printf(" ");
                if(j == 32)
                    printf("3.display message\n");
            }
            if(i == 3)
            {
                printf(" ");
                if(j == 32)
                    printf("4.change message\n");
            }
			if(i == 4)
            {
                printf(" ");
                if(j == 32)
                    printf("5.add message\n");
            }
			if(i == 5)
            {
                printf(" ");
                if(j == 32)
                    printf("6.sort message\n");
            }
			if(i == 6)
            {
                printf(" ");
                if(j == 32)
                    printf("7.grade section\n");
            }
        }
    }*/
}


