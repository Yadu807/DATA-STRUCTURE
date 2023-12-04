#include<stdio.h>
#include<stdlib.h>	

struct node
{
 int data;
 struct node*next;
};

void main()
{
 struct node* sp=(struct node*)0; //empty stack
 struct node* push(struct node*,int);
 struct node* pop(struct node*,int*);
 int option,item,ans;
 int search(struct node*,int);
 do
 {
  printf("\n1.PUSH\n");
  printf("\n2.POP\n");
  printf("\n3.SEARCH\n");
  printf("\n4.EXIT\n");
  printf("\nOPTION\n");
  scanf("%d",&option);
  	
  switch(option)
  {
   case 1: printf("DATA");
          scanf("%d",&item);
          sp=push(sp,item);
          break;
   case 2: if(sp==(struct node*)0)
	    printf("empty stack\n");
	   else{
	    sp=pop(sp,&item);
            printf("poped item=%d\n",item);}
           break;
   case 3: printf("item to search");
           scanf("%d",&item);
           ans=search(sp,item);
           if(ans!=0)
            printf("%d found  \n",item);
           else
{
            printf("%d not found \n",item);
}
           break;
   case 4: exit(0);
  }
 }
 while(1);
} 

//PUSH
struct node* push(struct node* sp,int data)
{
 struct node*t;
 t=(struct node*)malloc(sizeof(struct node));
 t->data=data;
 t->next=sp;
 return t;
}

//POP
struct node* pop(struct node* sp,int *data)
{
 struct node* t=sp;
 if(sp!=(struct node*)0)//checking stack is free
 {
  *data=sp->data;
  sp=sp->next;
  free(t);
 }
 return sp;
}

//search
int search(struct node* sp,int data)
{
 while(sp!=(struct node*)0 && sp->data!=data)
 sp=sp->next;
 if(sp==(struct node*)0)
  return 0;
 else
  return 1;
}
