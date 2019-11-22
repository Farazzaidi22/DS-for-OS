#include <iostream>
using namespace std;
#include "stack.h"
main()
{
  stack *top=NULL;
  stack a;
  char peak;
 char pre[7];//"a+b*c/e";
 char post[7];
 int priority,priority2;
int i,j=0;
for(i=0;i<7;i++)
{
  cin>>pre[i];
}
 for(i=0;i<7;i++)
 {
   priority=a.priority(pre[i]);
   if(priority==0)
   {
     post[j]=pre[i];
     j++;
   }
   else{
     peak=a.peak(top);
     if(peak==0)
     {
       a.push(pre[i],&top);

     }
     else{

       priority2=a.priority(a.peak(top));
       if(priority2>=priority)
       {
         while(a.priority(a.peak(top))>=priority)
         {
         post[j]=a.pop(&top);
         j++;
         }

       }
       a.push(pre[i],&top);

     }



   }
 }
 while(j<=i)
  {
    post[j]=a.pop(&top);
    j++;
  }

  for(i=0;i<7;i++)
  {
    cout<<post[i];
  }

  system("pause");
}
