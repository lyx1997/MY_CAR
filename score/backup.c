#include "STU.h"

int backup(student *head,char *data_file)
{
	student *p;
	int res;
	FILE *fw;
	p = head;
	if((fw = fopen(data_file,"w+")) == NULL){
		printf("open file error\n");
		return -1;
	}
	while(p != NULL){
		res = fprintf(fw, "%ld\t%s\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\n",
                p->num,p->name,p->usualscore,p->testscore,
                p->designscore,p->finalscore,p->totalscore);
        
        if (res < 0) {
            printf("write node error\n");
            return -1;
        }
        p = p ->next;
	}
	if(fclose(fw) < 0){
		printf("close file error\n");
	}
	printf("File backup!\n");
	printf("Display menu?\n");
	scanf("%d",&end);
	if(end == 1)
		menu();
	return 0;
}