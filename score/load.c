#include "STU.h"

student *load(char *data_file)
{
	int ret;
    student *previous;
	student *p;
    student *head = 0;
   	FILE *fp = 0;

    fp = fopen(data_file,"rt+");

    if (fp == NULL) {
        printf("open file error\n");
        return NULL;
    }
     
    // go to the start of file
    fseek(fp, 0, SEEK_SET);

    while(1) { 
        
        p = (student *)malloc(sizeof(student));
        
        if(p == NULL) {
            printf("malloc in display.c error\n");
            return NULL;
        }

        ret = fscanf(fp,"%ld\t%s\t%lf\t%lf\t%lf\t%lf\t%lf\n",
                    &p->num,p->name,&p->usualscore,&p->testscore,
                    &p->designscore,&p->finalscore,&p->totalscore);
        
        if (ret == -1) {
            free(p);
            break;
        }

        if (numstus == 0) {
            head = p;
            previous = p;
        } else {
            previous->next = p;
            previous = p;
            
        }
		numstus++;
        p->next = NULL;
    }

    if (fclose(fp) < 0 ) {
        printf("close file error\n");
    }
    
    return head;
}