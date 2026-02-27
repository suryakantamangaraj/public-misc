#include <stdio.h>
#include <stdlib.h>
typedef struct Poly
{
     double coef;
     int expo;
     struct Poly *next;
}Poly;
Poly* create_poly(Poly *head)
{
      int opt;
      Poly *nw,*p=head;
      do
      {
           nw=(Poly*)malloc(sizeof(Poly));
           printf("Enter the coefficient & exponent:");
           scanf("%lf %d",&nw->coef,&nw->expo);
           nw->next=NULL;
           if(head==NULL)
               head=nw;
           else
               p->next=nw;
           p=nw;
           printf("Another term(1/0):");
           scanf("%d",&opt);
      }while(opt==1);
      return head;
}
Poly* add_poly(Poly *head1,Poly *head2)
{
      Poly *nw,*res,*p=head1,*q=head2,*head3=NULL;
      while(p && q)
      {
           nw=(Poly*)malloc(sizeof(Poly));
           nw->next=NULL;
           if(p->expo>q->expo)
           {
               nw->coef=p->coef;
               nw->expo=p->expo;
               p=p->next;
           }
           else if(p->expo<q->expo)
           {
               nw->coef=q->coef;
               nw->expo=q->expo;
               q=q->next;
           }
           else
           {
               nw->coef=p->coef+q->coef;
               nw->expo=p->expo;        //OR nw->expo=q->expo;
               p=p->next;
               q=q->next;
           }
           if(head3==NULL)
               head3=nw;
           else
               res->next=nw;
           res=nw;
      }
      if(p==NULL)
          res->next=q;
      else
          res->next=p;
      return head3;
}
Poly* sub_poly(Poly *head1,Poly *head2)
{
      Poly *nw,*res,*p=head1,*q=head2,*head3=NULL;
      while(p && q)
      {
           nw=(Poly*)malloc(sizeof(Poly));
           nw->next=NULL;
           if(p->expo>q->expo)
           {
               nw->coef=p->coef;
               nw->expo=p->expo;
               p=p->next;
           }
           else if(p->expo<q->expo)
           {
               nw->coef=-1*q->coef;
               nw->expo=q->expo;
               q=q->next;
           }
           else
           {
               nw->coef=p->coef-q->coef;
               nw->expo=p->expo;        //OR nw->expo=q->expo;
               p=p->next;
               q=q->next;
           }
           if(head3==NULL)
               head3=nw;
           else
               res->next=nw;
           res=nw;
      }
      while(p)
      {
           nw=(Poly*)malloc(sizeof(Poly));
           nw->coef=p->coef;
           nw->expo=p->expo;
           nw->next=NULL;
           res->next=nw;
           res=nw;
           p=p->next;
      }
      while(q)
      {
           nw=(Poly*)malloc(sizeof(Poly));
           nw->coef=-1*q->coef;
           nw->expo=q->expo;
           nw->next=NULL;
           res->next=nw;
           res=nw;
           q=q->next;
      }
      return head3;
}
void adjust_poly(Poly *head)
{
     Poly *p=head,*q,*prev;
     while(p)
     {
          prev=p;
          q=p->next;
          while(q)
          {
               if(p->expo==q->expo)
               {
                   p->coef+=q->coef;
                   prev->next=q->next;
                   q->coef=0;
                   q->expo=0;
                   q->next=NULL;
                   free(q);
                   q=prev->next;
               }
               else
               {
                   prev=prev->next;
                   q=q->next;
               }
          }
          p=p->next;
     }
}
Poly* mul_poly(Poly *head1,Poly *head2)
{
      Poly *nw,*res,*p=head1,*q,*head3=NULL;
      while(p)
      {
           q=head2;
           while(q)
           {
                   nw=(Poly*)malloc(sizeof(Poly));
                   nw->next=NULL;
                   nw->coef=p->coef*q->coef;
                   nw->expo=p->expo+q->expo;
                   if(head3==NULL)
                       head3=nw;
                   else
                       res->next=nw;
                   res=nw;
                   q=q->next;
           }
           p=p->next;
      }
      adjust_poly(head3);
      return head3;
}
void print_poly(Poly * head)
{
     Poly *p=head;
     if(head==NULL)
          printf("\nEmpty Polynomial (No terms)\n");
     else
     {
          while(p)
          {
               printf("%lfx^%d",p->coef,p->expo);
               if((p->next!=NULL)&&(p->next->coef>=0.0))
                   putchar('+');
               p=p->next;
          }
          putchar('\n');
     }
}
int main()
{
      Poly *poly1,*poly2,*poly3;
      int ch;
      poly1=poly2=poly3=NULL;
      do
      {
          printf("1.CREATION\n");
          printf("2.ADDITION\n");
          printf("3.SUBTRACTION\n");
          printf("4.MULTIPLICATION\n");
          printf("5.EXIT\n");
          printf("\n\n\t\t\tENTER U'R CHOICE:");
          scanf("%d",&ch);
          switch(ch)
          {
               case 1:
                    printf("\nFor First Polynomial\n");
                    poly1=create_poly(poly1);
                    printf("\nThe first polynomial is:\n");
                    print_poly(poly1);
                    printf("\nFor Second Polynomial\n");
                    poly2=create_poly(poly2);
                    printf("\nThe second polynomial is:\n");
                    print_poly(poly2);
                    break;
               case 2:
                    poly3=add_poly(poly1,poly2);
                    printf("\nAfter addition, third polynomial is:\n");
                    print_poly(poly3);
                    break;
               case 3:
                    poly3=sub_poly(poly1,poly2);
                    printf("\nAfter subtraction, third polynomial is:\n");
                    print_poly(poly3);
                    break;
               case 4:
                    poly3=mul_poly(poly1,poly2);
                    printf("\nAfter multiplication, third polynomial is:\n");
                    print_poly(poly3);
                    break;
               case 5:
                    exit(0);
          }
      }while(1);
      system("PAUSE");
      return 0;
}
