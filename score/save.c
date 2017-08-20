#include "STU.h"

int save(student *head, char *data_file)
{
    int res;
    student *p;
    FILE *fp;
    p = head;

    fp = fopen(data_file, "w+");

    if(head == NULL || fp == NULL)
    {
        printf("parameter error\n");
        return -1;
    }

    do {
        res = fprintf(fp, "%ld\t%s\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\n",
                p->num,p->name,p->usualscore,p->testscore,
                p->designscore,p->finalscore,p->totalscore);
        
        if (res < 0) {
            printf("write node error\n");
            return -1;
        }
        p = p ->next;
    } while(p != NULL);
    
    if (fclose(fp) < 0 ) {
        printf("close file error\n");
    }
	return 0;
}