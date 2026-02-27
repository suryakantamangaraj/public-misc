#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
typedef struct Stack
{
        TYPE info;
        struct Stack *next;
}Stack;
Stack* push(Stack *top,TYPE ele)
{
       	Stack *nw;
       	nw=(Stack*)malloc(sizeof(Stack));
       	if(nw==NULL)
                printf("\nStack is Full.\n");
        else
       	{
           		nw->info=ele;
           		nw->next=top;
           		top=nw;
       	}
       	return top;
}
Stack* pop(Stack *top)
{
       	Stack *p=top;
       	if(top==NULL)
                printf("\nStack is Empty.\n");
        else
       	{
           		top=top->next;
           		p->next=NULL;
           		printf("\nThe deleted element=%d\n",p->info);
                free(p);
        }
        return top;
}
void peep(Stack *top)
{
   		Stack *p;
   		if(top==NULL)
                printf("\nNo elements are available\n");
   		else
   		{
       			printf("\nThe Stack elements are:\n");
                for(p=top;p;p=p->next)
              		printf("%d\n",p->info);
       			printf("\n");
   		}
      	return;
}
int main()
{
      	Stack *top=NULL;
      	int ch;
      	TYPE ele;
      	do
      	{
       			printf("STACK OPERATIONS\n");
                printf("****************\n");
                printf("1.PUSH\n");
       			printf("2.POP\n");
       			printf("3.PEEP\n");
       			printf("4.EXIT\n");
       			printf("\n\n\t\t\tENTER U'R CHOICE:");
       			scanf("%d",&ch);
       			switch(ch)
       			{
          			case 1:
           				  printf("\nEnter the data:");
           				  scanf("%d",&ele);
          				  top=push(top,ele);
          				  break;
          			case 2:
           				  top=pop(top);
           				  break;
          			case 3:
          				  peep(top);
          				  break;
          			case 4:
           				exit(0);
               }
     	}while(1);
      	system("PAUSE");
      	return 0;
}

