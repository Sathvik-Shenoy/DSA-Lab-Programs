#include<stdio.h>
#define max 100
int hash_key(int loc)
{
    return(loc%max);
}
int collision(int loc)
{
    return((loc<max)?loc+1:0);
}
void main()
{
    int n,id,loc,cntcoli,ch;
    printf("Enter number of employees:-");
    scanf("%d",&n);
    int hash_table[max];
    for(int i=0;i<max;i++)
        hash_table[i]=-1;
    for(int i=0;i<n;i++)
    {
        printf("Enter employee ID:-");
        scanf("%d",&id);
        loc=hash_key(id);
        if(hash_table[loc]!=-1)
        {
            cntcoli=0;
            while(hash_table[loc]!=-1 && cntcoli++<=max-1)
            {
                printf("Collision detected\n");
                loc=collision(loc);
            }
            if(hash_table[loc]!=-1)
            {
                printf("Overflow");
                exit(0);
            }    
        }
        hash_table[loc]=id;
    }
    printf("Enter 1 for partial display, 2 to complete display:-");
    scanf("%d",&ch);
    if(ch==1)
    {
        for(int i=0;i<max;i++)
        {
            if(hash_table[i]!=-1)
                printf("%d  %d\n",i,hash_table[i]);
        }
    }
    else
    {
        for(int i=0;i<max;i++)
            printf("%d  %d\n",i,hash_table[i]);
    }
}