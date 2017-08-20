#include "STU.h"

int	sort(student **head, STU_COMPARE compare)
{
	student *pre,*cur;
	student *tail = NULL;
	student temp;

	if (*head == NULL || compare == NULL) {
		printf("paramter error\n");
		return -1;
	}

	temp.next = *head;
	while(tail != temp.next)
	{
		pre = &temp;
		cur = temp.next;

		while(cur != tail && cur->next != tail)
		{
			if(compare(cur, cur->next))
			{
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = cur;
			}
			pre = pre->next;
			cur = pre->next;
		}
		tail = cur;
	}

	printf("sort successfully!\n");
	*head = temp.next;
    printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
	return 0;
}

/*student *sort(student *head)
{
	int i,j;
	student *pre,*cur, *next;
	
	for(i = 0;i < numstus;i++)
	{
		cur = pre = head;
		next = cur->next;
	
		for(j = 0;j < numstus-i-1;j++)
		{
			if(cur->num > next->num)
			{
				cur->next = next->next;
				next->next = cur;
				if (cur == head) {
					head = next; // the first node is changed, need to adjust head	
				}
				cur = next;
				next = next->next;
			}
			pre = cur;
			cur = cur->next;
			next = cur->next;
		}
	}

	return head;
}*/