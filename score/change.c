#include "STU.h"

student *change(student *head)
{
    student *pnew;
    int i = 0;
	unsigned long num;
	if(head == NULL){
		printf("parameter error!\n");
		return NULL;
	}
    while(end != 1)
    {
        pnew = head;
        printf("Please enter the student num you want to amend:\n");
        scanf("%d",&num);
        while(pnew != NULL)
        {
            if(num == pnew->num)
            {
                printf("Please enter the new student's message:\n\n");
                printf("Please enter the new student's num:");  scanf("%ld",&pnew->num);
                printf("Please enter the new student's name:"); scanf("%s",pnew->name);
                printf("Please enter the new student's usualscore:"); scanf("%lf",&pnew->usualscore);
                printf("Please enter the new student's testscore:"); scanf("%lf",&pnew->testscore);
                printf("Please enter the new student's designscore:"); scanf("%lf",&pnew->designscore);
                printf("Please enter the new student's finalscore:"); scanf("%lf",&pnew->finalscore);
                pnew->totalscore = 0.1*pnew->usualscore+0.15*pnew->testscore+0.15*pnew->designscore+0.6*pnew->finalscore;
                i++;
            }
            pnew = pnew->next;
        }
        if(i == 0)
            { printf("can not find this student's messages\n"); return head;}
        printf("end?\n");//end with1
        scanf("%d",&end);
    }
    printf("change successfully!\n");
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
    return head;
}


/*
void change(student stu[])
{
    int num;
    int i = 0;
    while(end != 1)
    {
        printf("Please enter the student num you want to amend:\n");
    scanf("%d",&num);
    while(i < numstus)
        {
            if(num == stu[i].num)
            {
                printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                        stu[i].num,stu[i].name,stu[i].usualscore,stu[i].testscore,
                        stu[i].designscore,stu[i].finalscore,stu[i].totalscore);
                printf("Please enter the new message of this student\n");
                printf("Please enter the new student's num\n");
                scanf("%d",&stu[i].num);
                printf("Please enter the new student's name\n");
                scanf("%s",&stu[i].name);
                printf("Please enter the new student's usualscore\n");
                scanf("%lf",&stu[i].usualscore);
                printf("Please enter the new student's testscore\n");
                scanf("%lf",&stu[i].testscore);
                printf("Please enter the new student's designscore\n");
                scanf("%lf",&stu[i].designscore);
                printf("Please enter the new student's finalscore\n");
                scanf("%lf",&stu[i].finalscore);
                stu[i].totalscore = 0.1*stu[i].usualscore+0.15*stu[i].testscore+0.15*stu[i].designscore+0.6*stu[i].finalscore;
            }
            i++;
        }
        printf("end?\n");//end with1
        scanf("%d",&end);
    }
    printf("change successfully!\n");
    menu();
}
*/