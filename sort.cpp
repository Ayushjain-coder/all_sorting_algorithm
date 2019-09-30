#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<iostream>
using namespace std;
int i,j,n;
int maximum(int[]);
void bubble_sort(int[]);
void selection_sort(int[]);
void insertion_sort(int[]);
void counting_sort(int[]);
void radix_sort(int[]);
void merge_sort(int[],int);
void merge(int[],int[],int[],int,int);
void quick_sort(int[],int,int);
int partition(int[],int,int);
//here main function starts
int main()
{
   int ch;
   printf("*********Sorting Algorithm***********\n");
   printf("1. Bubble Sort\n");
   printf("2. Selection Sort\n");
   printf("3. Insertion Sort\n");
   printf("4. Merge Sort\n");
   printf("5. Quick Sort\n");
   printf("6. Counting Sort\n");
   printf("7. Radix Sort\n");
   printf("8. Exit\n");
   printf("\nEnter the no of elements: ");
   scanf("%d",&n);
   int a[n];
   
   for(i=0;i<n;i++)
   {
       printf("Enter the element: ");
       scanf("%d",&a[i]);
   }
   do{
   printf("\nChoose anyone sorting technique: ");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1: bubble_sort(a);
               break;
       case 2: selection_sort(a);
               break;
       case 3: insertion_sort(a);
               break;
       case 4: merge_sort(a,n);
               printf("Sorted elements list: ");
               for(i=0;i<n;i++)
                 printf("%d " ,a[i]);
               break;
       case 5: quick_sort(a,0,n-1);
               printf("Sorted elements list: ");
               for(i=0;i<n;i++)
                  printf("%d ",a[i]);
               break;
       case 6: counting_sort(a);
               break;
       case 7: radix_sort(a);
               break;
       case 8: printf("\nThanks for using this amazing program!");
                exit(0);
                break;
       default: printf("\nThanks for using this amazing program!");
                exit(0);
                break;
   }
   }while(1);
}
int maximum(int a[])
{
    int m=0;
    for(i=0;i<n;i++)
    {
       if(m<a[i])
          m=a[i];
    }
    return m;
}
void bubble_sort(int a[])
{
    int temp;
   for(i=0;i<n;i++)
     for(j=0;j<n-i-1;j++)
        if(a[j]>a[j+1])
        {
         temp=a[j+1];
         a[j+1]=a[j];
         a[j]=temp;
        }
   printf("Sorted elements list: ");
   for(i=0;i<n;i++)
       printf("%d " ,a[i]);
   free(a);
}

void selection_sort(int a[])
{
    int imin,temp;
    for(i=0;i<=n-2;i++)
    {
        imin=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[imin])
                imin=j;
        }
        temp=a[imin];
        a[imin]=a[i];
        a[i]=temp;
    }
   printf("Sorted elements list: ");
   for(i=0;i<n;i++)
       printf("%d " ,a[i]);
   free(a);
}

void insertion_sort(int a[])
{
    int hole,value;
    for(i=1;i<n;i++)
    {
        hole=i;
        value=a[i];
        while(a[hole-1]>value && hole>0)
        {
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=value;
    }
   printf("Sorted elements list: ");
   for(i=0;i<n;i++)
       printf("%d " ,a[i]);
   free(a);
}

void counting_sort(int a[])
{
    int sa[n];
    int m=maximum(a);
    int aux[m+1];
    for(i=0;i<=m;i++)
        aux[i]=0;
    for(i=0;i<n;i++)
        aux[a[i]]=aux[a[i]]+1;
    for(i=1;i<=m;i++)
        aux[i]=aux[i]+aux[i-1];
    for(i=n-1;i>=0;i--)
    {
        aux[a[i]]=aux[a[i]]-1;
        sa[aux[a[i]]]=a[i];
    }
   printf("Sorted elements list: ");
   for(i=0;i<n;i++)
       printf("%d " ,sa[i]);
   free(a);
}

void radix_sort(int a[])
{
    int place=1,aux[n][9],d,col,count=0,rem;
    int max=maximum(a);
    while(max!=0)
    {
        rem=max%10;
        count++;
        max=max/10;
    }
    for(d=1;d<=count;d++)
    {
        for (i=0;i<n;i++)
            for(j=0;j<=9;j++)
               aux[i][j]=-999;

        for(i=0;i<n;i++)
        {
            col=(a[i]/place)%10;
            aux[i][col]=a[i];
        }

        int ctr=0;
        for(j=0;j<=9;j++)
            for(i=0;i<n;i++)
               if(aux[i][j]!=-999)
                {
                    a[ctr]=aux[i][j];
                    ctr++;
                }
        place=place*10;
    }
   printf("Sorted elements list: ");
   for(i=0;i<n;i++)
       printf("%d " ,a[i]);
   free(a);
}

void merge_sort(int a[],int n)
{
    if(n<2)
        return;
    int mid=n/2;
    int l[mid],r[n-mid];
    for(i=0;i<mid;i++)
        l[i]=a[i];
    for(i=mid;i<n;i++)
        r[i-mid]=a[i];
    merge_sort(l,mid);
    merge_sort(r,n-mid);
    merge(l,r,a,mid,n-mid);
    free(a);
    free(l);
    free(r);
}

void merge(int l[],int r[],int a[],int nl,int nr)
{
    int i=0,j=0,k=0;
    while(i<nl && j<nr)
    {
        if(l[i]<r[j])
        {
            a[k]=l[i];
            k++;
            i++;
        }
        else
        {
            a[k]=r[j];
            k++;
            j++;
        }
    }
    while(i<nl)
    {
        a[k]=l[i];
        k++;
        i++;
    }
    while(j<nr)
    {
        a[k]=r[j];
        k++;
        j++;
    }
}

void quick_sort(int a[],int start,int end)
{
    if(start>=end)
        return;
    int pindex=partition(a,start,end);
    quick_sort(a,start,pindex-1);
    quick_sort(a,pindex+1,end);
    free(a);
}

int partition(int a[],int start,int end)
{
    int pivot,pindex,temp;
    pivot=a[end];
    pindex=start;
    for(i=start;i<=end-1;i++)
        if(a[i]<=pivot)
        {
          temp=a[i];
          a[i]=a[pindex];
          a[pindex]=temp;
          pindex=pindex+1;
        }
    temp=a[pindex];
    a[pindex]=a[end];
    a[end]=temp;
    return pindex;
}



