
#include<stdio.h>
typedef struct
{
 unsigned char x:1;
}bit;

int uset[]={1,2,3,4,5,6,7,8,9},size=9;       //Global declaration

void main()
{
 void readset(bit[],int n);
 void printset(bit[]);
 void unionset(bit[],bit[],bit[]);
 void intersect(bit[],bit[],bit[]);
 void difference(bit[],bit[],bit[]);
	
 bit a[10]={0},b[10]={0},c[10]={0};   //Array initialization
 int n;
 
 printf("\nNumber of elements in set A : ");
 scanf("%d",&n);
 readset(a,n);
 printf("\nNumber of elements of set B : ");
 scanf("%d",&n);
 readset(b,n);
 printf( "\nSet A : ");
 printset(a);
 printf("\nSet B : ");
 printset(b);
 printf("\n1.Union Operation : ");
 printf("\nA U B = ");
 unionset(a,b,c);
 printset(c);
 printf("\n2.Intersection Operation : ");
 printf( "\nA ∩ B = ");
 intersect(a,b,c);
 printset(c);
 printf("\n3.Difference Operation : ");
 difference(a,b,c);
 printf("\nA - B = ");
 printset(c);
}
	
	
//To read a set and store as bit string

void readset(bit a[],int n)
{
 int i,x,k;
 printf("Enter %d elements : ",n);
 for(i=0;i<n;++i)
 {
  scanf("%d",&x);
  for(k=0;k<size;k++)
  {
   if(uset[k]==x)
   {
    a[k].x=1;
    break;
   }
  }
 }
 return;
}

//To print a set from bit string representation

void printset(bit a[])
{
 int k;
 printf(" {");
 for(k=0;k<size;k++)
 {
 if(a[k].x==1)
  printf(" %d ",uset[k]);
		
 }
 printf("}");
 printf("\n");
 return;
}

//To find union of two sets using bit string

void unionset(bit a[],bit b[],bit c[])
{
 int k;
 for(k=0;k<size;++k)
  c[k].x=a[k].x | b[k].x;	
 return;
}

//To find intersection of two sets

void intersect(bit a[],bit b[],bit c[])
{
 int k;
 for(k=0;k<size;++k)
  c[k].x=a[k].x & b[k].x;
return;
}

//To find difference of two sets

void difference(bit a[],bit b[],bit c[])
{
 int k;
 for(k=0;k<size;++k)
 {
	
  if(a[k].x==1)
   c[k].x=a[k].x ^ b[k].x;
 }
 return;
}
			
 	
