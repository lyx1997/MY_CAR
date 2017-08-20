#include "STU.h"

// <0 error >=0 ok
int display(student *head)
{
    int i;
    student *p;
	if(head == NULL){
		printf("parameter error!\n");
		return -1;
	}
    p = head;

    for(i = 0;i < 16;i++)
    {
        printf(" ");
        if(i == 15)
           printf("num\tname\tusualscore\ttestscore\tdesignscore\tfinalscore\ttotalscore\n\n");
    }
 
    do
    {
        for(i = 0;i < 16;i++) {
            printf(" ");
            if(i == 15) {
                printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
                       p->num,p->name,p->usualscore,p->testscore,
                       p->designscore,p->finalscore,p->totalscore);
            }
        }
        p = p->next;
    } while (p != NULL);
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
    return 0;
}


/*
void display(student stu[])
{
    int i,j;
    int end = 0;
    for(i = 0;i < 16;i++)
    {
        printf(" ");
        if(i == 15)
            printf("num\tname\tusualscore\ttestscore\tdesignscore\tfinalscore\ttotalscore\n\n");
    }
    for(i = 0;i < numstus;i++)
    {
        for(j = 0;j < 16;j++)
        {
            printf(" ");
            if(j == 15)
            {
                printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                stu[i].num,stu[i].name,stu[i].usualscore,stu[i].testscore,
                stu[i].designscore,stu[i].finalscore,stu[i].totalscore);
            }
        }
    }
    while(end != 1)
    {
        printf("return to menu?\n");
        scanf("%d",&end);//end with 1
    }
    menu();
}
*/