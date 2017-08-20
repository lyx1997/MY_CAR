#ifndef H_STUDENT
#define H_STUDENT

#include "stdio.h"
#include "string.h"
#include "malloc.h"
#include "stdlib.h"

#define LEN sizeof(struct students_message) //it can record 100 students
typedef struct students_message
{
	unsigned long num;
	char name[30];
	double usualscore;
	double testscore;
	double designscore;
	double finalscore;
	double totalscore;
	struct students_message *next;
}student;

typedef int (* STU_COMPARE)(student *a, student *b);


extern int numstus,end;//the acount of students

void menu();  //the declaration of function
student *logging(char *data_file);
int display(student *head);
student *deleterecord(student *head);
int search(student *head);
student *change(student *head);
student *add(student *head);
int save(student *head, char *data_file);
student *load(char *data_file);
int sort(student **head, STU_COMPARE compare);
int grade(student *head);
STU_COMPARE selesort(void);
student *destroy(student *head);
int backup(student *head,char *data_file);

/*
函数注释掉的为数组做法
*/


#endif