#include <ctype.h>
#include "STU.h"


student *logging(char *data_file)
{
	FILE *fp;
    student *head,*pnew,*pend;
    pnew = pend = (student *)malloc(LEN);
	fp = fopen(data_file, "w+");
    printf("Please enter the student's message:\n\n");
    printf("Please enter the student's num:");  scanf("%ld",&pnew->num);
    printf("Please enter the student's name:"); scanf("%s",pnew->name);
    printf("Please enter the student's usualscore:"); scanf("%lf",&pnew->usualscore);
    printf("Please enter the student's testscore:"); scanf("%lf",&pnew->testscore);
    printf("Please enter the student's designscore:"); scanf("%lf",&pnew->designscore);
    printf("Please enter the student's finalscore:"); scanf("%lf",&pnew->finalscore);
    pnew->totalscore = 0.1*pnew->usualscore+0.15*pnew->testscore+0.15*pnew->designscore+0.6*pnew->finalscore;
    printf("end enter?\n");//end with 1;
    scanf("%d",&end);
    numstus++;
    head = pnew;
    while(end != 1)
    {
        pend->next = pnew;
        pend = pnew;
        pnew = (student *)malloc(LEN);
        printf("Please enter the student's message:\n\n");
        printf("Please enter the student's num:");  scanf("%ld",&pnew->num);
        printf("Please enter the student's name:"); scanf("%s",pnew->name);
        printf("Please enter the student's usualscore:"); scanf("%lf",&pnew->usualscore);
        printf("Please enter the student's testscore:"); scanf("%lf",&pnew->testscore);
        printf("Please enter the student's designscore:"); scanf("%lf",&pnew->designscore);
        printf("Please enter the student's finalscore:"); scanf("%lf",&pnew->finalscore);
        pnew->totalscore = 0.1*pnew->usualscore+0.15*pnew->testscore+0.15*pnew->designscore+0.6*pnew->finalscore;
        numstus++;
        printf("end enter?\n");//end with 1;
        scanf("%d",&end);
    }
    pend->next = pnew;
    pend = pnew;
    pnew = (student *)malloc(LEN);
    pend->next = NULL;
    printf("logging successfully!\n");
	if (fclose(fp) < 0 ) {
        printf("close file error\n");
    }
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
    return head;
}


/*
void logging(student stu[])
{
	int i;
	int end = 0;
	printf("Please enter the student's message:\n");
	for(i = 0;i < 100 && end != 1;i++)
	{
		printf("Please enter the student's num\n");
		scanf("%d",&stu[i].num);
		printf("Please enter the student's name\n");
		scanf("%s",&stu[i].name);
		printf("Please enter the student's usualscore\n");
		scanf("%lf",&stu[i].usualscore);
		printf("Please enter the student's testscore\n");
		scanf("%lf",&stu[i].testscore);
		printf("Please enter the student's designscore\n");
		scanf("%lf",&stu[i].designscore);
		printf("Please enter the student's finalscore\n");
		scanf("%lf",&stu[i].finalscore);
		stu[i].totalscore = 0.1*stu[i].usualscore+0.15*stu[i].testscore+0.15*stu[i].designscore+0.6*stu[i].finalscore;
		numstus++;
		printf("end enter?\n");//end with 1;
		scanf("%d",&end);
	}
	printf("logging successfully!\n");
	menu();
} */