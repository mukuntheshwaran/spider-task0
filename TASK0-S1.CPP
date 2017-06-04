#include<iostream.h>
#include<conio.h>

sol1(int arr[50],int size,int len)
{
   int pos=0;
   for(int i=0;i<size;i++)
   {
      if(arr[i]>=len)
      {
	arr[i]-=len;
	pos=i;
	break;
      }
   }
   cout<<"\n\t\t";
   for(i=0;i<size;i++)
   {
     if(arr[i]!=0)
       cout<<arr[i]<<' ';
   }
   arr[pos]+=len;

}

sol2(int arr[50],int size,int len)
{
   int temp=arr[0],pos=0;
   for(int i=1;i<size;i++)
   {
     if(arr[i]>=len&&temp>=len)
     {
       if(arr[i]<temp)
       {
	 temp=arr[i];
	 pos=i;
       }
     }
     else if(temp<len&&arr[i]>=len)
     {
       temp=arr[i];
       pos=i;
     }
   }


   arr[pos]-=len;
   cout<<"\n\t\t";
   for(i=0;i<size;i++)
   {
     if(arr[i]!=0)
       cout<<arr[i]<<' ';
   }
   arr[pos]+=len;
}

sol3(int arr[50],int size,int len)
{
   int temp=arr[0],pos=0;
   for(int i=1;i<size;i++)
   {
      if(temp<arr[i])
      {
	temp=arr[i];
	pos=i;
      }
   }
   arr[pos]-=len;
   cout<<"\n\t\t";
   for(i=0;i<size;i++)
   {
     if(arr[i]!=0)
       cout<<arr[i]<<' ';
   }
   arr[pos]+=len;
}

void main()
{
  clrscr();
  int size=0;
  while(size<=0)
  {
    cout<<"\nenter the number of curtains(greater than 0) : ";
    cin>>size;
  }
  int arr[50],query=1,len=0,max;
  cout<<"\nenter the lenght of the curtain (from top to bottom)\n";
  for(int i=0;i<size;i++)
  {
    cin>>arr[i];
    if(arr[i]<=0)
    {
      cout<<"invalid value... re enter";
      i--;
    }
  }
  max=arr[0];
  for(i=1;i<size;i++)
  {
     if(max<arr[i])
	max=arr[i];
  }
  char ch='y';
  while(ch=='y')
  {
    cout<<"\nquery number : "<<query;
    while(len<=0 || len >max)
    {
      cout<<"\nenter the length of the cloth needed(greater than 0 and less than "<<max<<") : ";
      cin>>len;
    }
    cout<<"\nsimulation 1 : ";
    sol1(arr,size,len);
    cout<<"\nsimulation 2 : ";
    sol2(arr,size,len);
    cout<<"\nsimulation 3 : ";
    sol3(arr,size,len);
    cout<<"\ndo you want enter another query <y/n>";
    cin>>ch;
    query++;
  }
}