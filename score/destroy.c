#include "STU.h"

student *destroy(student *head)
{
	student *temp,*cursor;
	if(head == NULL){
		printf("parameter error!\n");
		return NULL;
	}
	cursor = head;
	while(cursor->next)
	{
		temp = cursor->next;
		cursor->next = cursor->next->next;
		free(temp);
	}
	head = NULL;
	printf("Destroy successfully!\n");
	numstus = 0;
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
	return 0;
}