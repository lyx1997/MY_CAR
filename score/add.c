#include <ctype.h>
#include "STU.h"

student *add(student *head)
{ 
    student *stu;
    student *p,*p1,*p2;
	
    while(end != 1)
    {
		p = stu = (student *)malloc(LEN);
        p1 = head;
        printf("Please enter the student message you want to add:\n");
        printf("Please enter the student's message:\n\n");
        printf("Please enter the student's num:");  scanf("%ld",&p->num);
        printf("Please enter the student's name:"); scanf("%s",p->name);
        printf("Please enter the student's usualscore:"); scanf("%lf",&p->usualscore);
        printf("Please enter the student's testscore:"); scanf("%lf",&p->testscore);
        printf("Please enter the student's designscore:"); scanf("%lf",&p->designscore);
        printf("Please enter the student's finalscore:"); scanf("%lf",&p->finalscore);
        p->totalscore = 0.1*p->usualscore+0.15*p->testscore+0.15*p->designscore+0.6*p->finalscore;
        if(p1 == NULL)
            { p = head;p->next = NULL;}
        else
        {
            while(p->num > p1->num && p1->next != NULL)
                { p2 = p1;p1 = p1->next;}
            if(p->num <= p1->num)
            {
                if(p1 == head)
                    head = p;
                else
                    p2->next = p;
                p->next = p1;
            }
            else
                { p1->next = p;p->next = NULL;}
        }
        printf("add successfully!\n");
		numstus++;
        printf("end?\n");//end with 1
        scanf("%d",&end);
    }
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
    return head;
}

