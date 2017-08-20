#include "STU.h"

int numstus = 0;
int end = 0;

void main()
{
    int keyvalue;
    //int len = 100;
    student *head = 0;
    /*
    student *pointer;
    pointer = (student *)malloc(len*LEN);
    */
    head = load("score.txt");

    if (head == NULL) {
        printf("no data in file\n");
		head = logging("score.txt");
    }
    menu();
    while(keyvalue != 0)
    {
		end = 0;
        printf("Please enter a count about function:\n");
        scanf("%d",&keyvalue);//choose the function
        switch(keyvalue)
        {
		    case 0:break;
            case 1:system("cls");
				   head = deleterecord(head);
				   break;
            case 2:system("cls");
				   search(head);
				   break;
            case 3:system("cls");
				   display(head);
				   break;
            case 4:system("cls");
				   head = change(head);
				   break;
            case 5:system("cls");
				   head = add(head);
				   break;
			case 6:system("cls");
				   sort(&head,selesort());
				   break;
			case 7:system("cls");
				   grade(head);
				   break;
			case 8:system("cls");
				   head = destroy(head);
				   break;
			case 9:system("cls");
				if(backup(head,"score0.txt") != 0){
					printf("backup error\n");
				}
				   break;
            default :printf("There is no such a function\n");continue;
        }
		
    }
	printf("\t\tEnd of program!\n");
	if (save(head, "score.txt") != 0) {
		printf("save error\n");
	}
}