#include <stdio.h>

 void main()
    {
        int rs[25],m[10],flag[25],count[10]; //flag array for reference string
        int f,pf,k,i,j,min,n,next=0;         //count array for frame
        pf = 0;

        printf("Enter number of frames");
        scanf("%d",&f);

        printf("Enter number of reference string");
        scanf("%d",&n);

        printf("Enter reference string");
        for(i=0;i<n;i++)
        {
            scanf("%d",&rs[i]);
            flag[i]=0;         //initialize flag values to 1
        }



        for(int i=0;i<f;i++)  //initializing all array values to -1
        {
        m[i]=-1;
        count[i]=0;          //count values initialized to 0
        }

        for(i=0;i<n;i++) //main for loop
        {
            for(j=0;j<f;j++)
            {
                if(m[j]==rs[i]) //check if value in frame is equal to reference string
                {
                    flag[i]=1; //flag value updated
                    count[j]=next;
                    next++;
                }
            }

            if(flag[i]==0) //if value in frame no equal to reference string ie page fault occurs
            {
                if(i<f) //check the first few nums in reference string
                {
                    m[i]=rs[i];
                    count[i]=next;
                    next++;
                }

                else
                {
                   min=0;
                   for(j=0;j<f;j++) //for loop to find the page with minimum count
                   {
                       if(count[j]<count[min]) //min stores the value of the least recently used page
                       min=j;
                   }
                   m[min]=rs[i]; //least recently used page is replaced
                   count[min]=next;
                   next++;
                }
                pf++;
            }

             for(j=0;j<f;j++)
             printf("%d\t",m[j]);

        if(flag[i]==0) //ie if page fault occured...
        printf("PF no. -- %d",pf);

        printf("\n");
      }
       printf("\nThe number of page faults using LRU are %d",pf);
}

