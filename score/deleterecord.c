#include "STU.h"

student *deleterecord(student *head)
{
	student *p1,*p2;
	unsigned long num;
	if(head == NULL){
		printf("parameter error!\n");
		return NULL;
	}
	while(end != 1)
	{
		if(head == NULL)
		{ printf("No messages have been entered!\n");  return head;}
	    else  
		    p1 = head;
	    printf("Please enter the num you want to delete:\n"); scanf("%ld",&num);
	    while(num != p1->num && p1->next != NULL)
	    {
		    p2 = p1;
		    p1 = p1->next;
     	}
	    if(num == p1->num)
	    {
			if(p1 == head){
			head = p1->next;
			free(p1);
			}
			else{
			p2->next = p1->next;
			free(p1);
			}
			printf("delete successfully!\n");
			numstus--;
	    }
	    else
		    printf("can not find this student's messages\n");
		printf("end?\n");//end with 1
		scanf("%d",&end);
	}
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
	return head;
}

/*
void deleterecord(student stu[])
{
	int end = 0;
	int num;
	int i,j;
	while(end != 1)
	{
		printf("Please enter the num you want to delete\n");
	    scanf("%d",&num);
	    for(i = 0;i < numstus;i++)
        {
			 if(num == stu[i].num)
			 {
				 for(j = 0;j < numstus-i;j++)
				 stu[i] = stu[i+1];
			 }
		}	
		numstus--;
	    printf("delete successfully!\n");
		printf("end?");//end with 1
		scanf("%d",&end);
	}
	menu();
}
*/