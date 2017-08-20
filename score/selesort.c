#include <ctype.h>
#include "STU.h"

static int number(student *a, student *b)
{
	if (a->num > b->num) {
		return 1;
	} else {
		return 0;
	}
} 

static int totalscore(student *a,student *b)
{
	if (a->totalscore > b->totalscore){
		return 1;
	}else{
		return 0;
	}
}

static int finalscore(student *a,student *b)
{
	if (a->totalscore > b->totalscore){
		return 1;
	}else{
		return 0;
	}
}

static int usualscore(student *a,student *b)
{
	if((int)a->usualscore > (int)b->usualscore){
		return 1;	
	}else{
		return 0;
	}
}

static int testscore(student *a,student *b)
{
	if((int)a->testscore > (int)b->testscore){
		return 1;	
	}else{
		return 0;
	}
}

static int designscore(student *a,student *b)
{
	if((int)a->designscore > (int)b->designscore){
		return 1;	
	}else{
		return 0;
	}
}

typedef struct sort_menu_item {
	STU_COMPARE compare;
	char * des;
} SORT_MENU_ITEM;

static SORT_MENU_ITEM compare_functions[] = {
	{number, "number"}, 
	{totalscore, "total score"},
	{finalscore, "final score"},
	{usualscore, "usual score"},
	{testscore, "test score"},
	{designscore, "design score"},
	{NULL, NULL}
};

STU_COMPARE selesort(void)
{
	int count = 1;
	int input;
	SORT_MENU_ITEM *item = compare_functions;

	while (item->compare != NULL) {
		printf("\t\t%d. %s\n", count, item->des);
		count++;
		item++;
	}

	printf("Please select the sorting method:\n");
	getchar();
	input = getchar();
	
	if (isdigit(input)) {
		input -= '0';
		if (input < count) {
			return compare_functions[input - 1].compare;
		}
	}

	return NULL;
}