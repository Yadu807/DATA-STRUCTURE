#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front=0, rear=0;

main()
{
 void enqueue(int);
 int dequeue();
 int search(int);
 int option,item,ans;

 do
 {
  printf("\n1.insert\n");
  printf("\n2.Delrte\n");
  printf("\n3.search\n");
  printf("\n4.exit\n");
  printf("\noption\n");
  scanf("%d",&option);
  
  switch(option)
  {
   case 1: printf("item");
          scanf("%d",&item);
          enqueue(item);
          break;
   case 2: item=dequeue();
          printf("item=%d\n",item);
          break;
   case 3: printf("item to search");
          scanf("%d",&item);
          ans=search(item);
          if(ans!=0)
          printf("%d found at %d \n",item,ans);
          else
           printf("%d notfound  \n",item);
          break;
   case 4: exit(0);
  }
 }
 while(1);
}

//insertion
void enqueue(int item)
{
 int t;
 t=(rear+1)%size;
 if(t==front)
 {
  printf("Queue is full");
  exit(1);
 }
 
  rear=t;
  queue[rear]=item;
 
}

// deletion
int dequeue()
{
 
 if(front==rear)
 {
  printf("Queue is empty" );
  exit(2);
 }
 front=(front+1)%size;
 return queue[front];
}

//searching
int search(int item)
{
 
 int t1=front,t2=rear;
 t1=(t1+1)%size;
 while(t1!=t2 && queue[t1]!=item){
 t1=(t1+1)%size;
}
 
  if(front==rear){
   front=0;rear=0;
   printf("queue is empty");
   return 0;
  }
if(queue[t1]==item)
{
 return t1;
}
else{
return 0;
}
}
