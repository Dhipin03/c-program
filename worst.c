#include<stdio.h>

void main(){
    
    int n,m,psize[10],bsize[10],i,j,max;
    int alloc[10],frag[10],flag[10];
    printf("no of process:");
    scanf("%d",&n);
    printf("size of process:");
    for(i=0;i<n;i++){
        scanf("%d",&psize[i]);
    }
    printf("no of block:");
    scanf("%d",&m);
    printf("size of block:");
    for(i=0;i<m;i++){
        scanf("%d",&bsize[i]);
        flag[i]=-1;
    }
    for(i=0;i<n;i++){
        alloc[i]=-1;
    }
    
    for(i=0;i<n;i++){
       max=-1;
        for(j=0;j<m;j++)
            if(bsize[j]>=psize[i] && flag[j]!=1){
                if(max==-1)
                    max=j;
                else if(bsize[max]<bsize[j])
                    max=j;
            }
       if(max!=-1){
            alloc[i]=max;
            flag[max] =1;
            frag[i]=bsize[max]-psize[i];
    } 
}
     printf("p\tpsize\tb\tbsize\tfrag\n");
     for(i=0;i<n;i++){
            printf("\n%d\t%d\t",i+1,psize[i]);
            if(alloc[i]!=-1){
                printf("%d\t%d\t%d\n",alloc[i]+1,bsize[alloc[i]],frag[i]);
            }
            else{
            printf("not");
            }
        }
    }
