#include <stdio.h>
#include <stdlib.h>
typedef int TYPE;
typedef struct Queue
{
        TYPE info;
        struct Queue *next;
}Queue;
Queue* insert(Queue *rear,TYPE ele)
{
       	Queue *nw;
       	nw=(Queue*)malloc(sizeof(Queue));
       	if(nw==NULL)
                printf("\nQueue is Full.\n");
        else
       	{
           		nw->info=ele;
           		nw->next=NULL;
           		if(rear!=NULL)
               			rear->next=nw;
           		rear=nw;
       	}
       	return rear;
}
Queue* delet(Queue *front)
{
       	Queue *p=front;
       	if(front==NULL)
                printf("\nQueue is Empty.\n");
        else
       	{
           		front=front->next;
           		p->next=NULL;
           		printf("\nThe deleted element=%d\n",p->info);
                free(p);
        }
        return front;
}
void traverse(Queue *front,Queue *rear)
{
   		Queue *p;
   		if(front==NULL)
                printf("\nNo elements are available\n");
   		else
   		{
       			printf("\nThe Queue elements are:\n");
                for(p=front;p!=rear->next;p=p->next)
              		printf("%d\t",p->info);
       			printf("\n");
   		}
      	return;
}
int main()
{
      	Queue *front,*rear;
      	int ch;
      	TYPE ele;
      	front=rear=NULL;
      	do
      	{
       			printf("LINEAR QUEUE OPERATIONS\n");
                printf("***********************\n");
                printf("1.INSERT\n");
       			printf("2.REMOVE\n");
       			printf("3.DISPLAY\n");
       			printf("4.EXIT\n");
       			printf("\n\n\t\t\tENTER U'R CHOICE:");
       			scanf("%d",&ch);
       			switch(ch)
       			{
          			case 1:
           				printf("\nEnter the data:");
           				scanf("%d",&ele);
          				rear=insert(rear,ele);
          				if(front==NULL)
              				front=rear;
          				break;
          			case 2:
           				front=delet(front);
           				if(front==NULL)
           				rear=front;
           				break;
          			case 3:
          				traverse(front,rear);
          				break;
          			case 4:
           				exit(0);
               }
     	}while(1);
      	system("PAUSE");
      	return 0;
}

