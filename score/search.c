#include "STU.h"

int search(student *head)
{
     student *p;
     int sele = 0;
	 unsigned long num;
     int i = 0;
     char name[30];
	 if(head == NULL){
		printf("parameter error!\n");
		return -1;
	}
     while(end != 1)
     {
        p = head;
        printf("search by name choose 1,search by num choose 2:");
        scanf("%d",&sele);
        if(sele == 1)
        {
            printf("Please enter the name you want to search for:\n");
            scanf("%s",name);
            while(p != NULL)
            {
                if(strcmp(name,p->name) == 0)
                {
                        printf("%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                        p->num,p->name,p->usualscore,p->testscore,
                        p->designscore,p->finalscore,p->totalscore);
                        i++;
                }
                p = p->next;
            }
            if(i == 0)
                printf("can not find this student's name\n");
        }
        else if(sele == 2)
        {
                printf("Please enter the num you want to search for:\n");
                scanf("%d",&num);
                while(p != NULL)
                {
                        if(num == p->num)
                        {
                                printf("%ld\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
                                p->num,p->name,p->usualscore,p->testscore,
                                p->designscore,p->finalscore,p->totalscore);
                                i++;
                        }
                        p = p->next;
                }
                if(i == 0)
                printf("can not find this student's num\n"); 
        }
		else 
			printf("There is no this option!\n");
        printf("end?\n");//end with 1
        scanf("%d",&end);
     }
    printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
	 return 0;
}

/*
void search(student stu[])
{
	int sele = 0;
        int i,j = 0;
	int num = 1;
	char name[20];
	printf("search by name choose 1,search by num choose 2\n");
	scanf("%d",&sele);
	if(sele == 1)
	{
		while(end != 1)
		{
			printf("Please enter the name you want to search for:\n");
		    scanf("%s",name);
                for(i = 0;i < numstus;i++)
                {
			        if(strcmp(name,stu[i].name)==0)
					{
			            printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
				        stu[i].num,stu[i].name,stu[i].usualscore,stu[i].testscore,
				        stu[i].designscore,stu[i].finalscore,stu[i].totalscore);
					}
					else
						printf("error! try again.\n");
                }
			printf("end?\n");//end with 1
			scanf("%d",&end);
		}
	}
	else if(sele == 2)
	{
		while(end != 1)
		{
			printf("Please enter the num you want to search for:\n");
		    scanf("%d",&num);
                for(i = 0;i < numstus;i++)
                {
			        if(num == stu[i].num)
					{
			            printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n",
				        stu[i].num,stu[i].name,stu[i].usualscore,stu[i].testscore,
				        stu[i].designscore,stu[i].finalscore,stu[i].totalscore);
					}
					else
						printf("error! try again.\n");
                }
				printf("end?\n");//end with 1
			    scanf("%d",&end);
		}
	}
	menu();
}
*/