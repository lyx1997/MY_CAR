#include "STU.h"

int grade(student *head)
{
	student *p;
	int i;
	int count[6] = {0};
	if(head == NULL){
		printf("parameter error!\n");
		return NULL;
	}
	p = head;
	printf("The amount of 100:\n");
	while(p != NULL)
	{
			if(p->totalscore == 100)
			{
				count[0]++;
				printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
					       p->num,p->name,p->usualscore,p->testscore,
						   p->designscore,p->finalscore,p->totalscore);
			}
			p = p->next;
	}
	p = head;
	printf("The amount of 90-99:\n");
	while(p != NULL)
	{
		    if(p->totalscore < 100 && p->totalscore >= 90)
			{
				count[1]++;
				printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
			               p->num,p->name,p->usualscore,p->testscore,
			               p->designscore,p->finalscore,p->totalscore);
			}
			p = p->next;
	}
	p = head;
	printf("The amount of 80-89:\n");
	while(p != NULL)
	{
			if(p->totalscore < 90 && p->totalscore >= 80)
			{
				count[2]++;
				printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
				           p->num,p->name,p->usualscore,p->testscore,
					       p->designscore,p->finalscore,p->totalscore);
			}
			p = p->next;
	}
	p = head;
	printf("The amount of 70-79:\n");
	while(p != NULL)
	{
			if(p->totalscore < 80 && p->totalscore >= 70)
			{
				count[3]++;
				printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
					       p->num,p->name,p->usualscore,p->testscore,
						   p->designscore,p->finalscore,p->totalscore);
			}
			p = p->next;
	}
	p = head;
	printf("The amount of 60-69:\n");
	while(p != NULL)
	{
			if(p->totalscore < 70 && p->totalscore >= 60)
			{
				count[4]++;
				printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
					       p->num,p->name,p->usualscore,p->testscore,
						   p->designscore,p->finalscore,p->totalscore);
			}
			p = p->next;
	}
	p = head;
	printf("Below 60 :\n");
	while(p != NULL)
	{
			if(p->totalscore >= 0 && p->totalscore < 60)
			{
				count[5]++;
				printf("%ld\t%s\t%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n",
				           p->num,p->name,p->usualscore,p->testscore,
				           p->designscore,p->finalscore,p->totalscore);
			}
			p = p->next;
	}
    printf("%d:\t%dstudent\t%.2f%%\n",100,count[0],(double)count[0]/numstus*100);
	for(i = 1;i < 5;i++){
		printf("%d-%d:\t%dstudents\t%.2f%%\n",100-i*10,100-(i-1)*10,count[i],(double)count[i]/numstus*100);
	}
    printf("<%d:\t%dstudent\t%.2f%%\n",60,count[5],(double)count[5]/numstus*100);
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
	return 0;
}