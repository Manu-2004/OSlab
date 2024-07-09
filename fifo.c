#include <stdio.h>



 void main()
    {
        int rs[25],m[10];
        int f,pf,k,count,i,n;
        count = 0;pf = 0;

        printf("Enter number of frames");
        scanf("%d",&f);

        printf("Enter number of reference string");
        scanf("%d",&n);

        printf("Enter reference string");
        for(i=0;i<n;i++)
        scanf("%d",&rs[i]);


        for(int i=0;i<f;i++)//initializing all array values to -1
        m[i]=-1;


        for(i=0;i<n;i++)//main for loop
     {
       for(k=0;k<f;k++)
     {
      if(m[k]==rs[i]) //checking if page value and reference string is same
       break;
     }

     if(k==f)//all frames are checked
     {
      m[count++]=rs[i];//fifo implementation
      pf++;
     }

    for(int j=0;j<f;j++)
    printf("\t%d",m[j]);

    if(k==f)
    printf("\tPF No. %d",pf);

    printf("\n");
    if(count==f)
        count=0;
    }

 printf("\n The number of Page Faults using FIFO are %d",pf);
 }
