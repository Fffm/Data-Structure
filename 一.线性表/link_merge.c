#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}*LinkList,LinkNode;

LinkList create()
{
    LinkList tmp=(LinkList)malloc(sizeof(LinkNode));
    tmp->next=NULL;
    return tmp;
}

void merge_list(LinkList ha,LinkList hb)
{
    LinkList pa,pb,pre_a,waste,tmp;
    pa=ha,pb=hb;
    pre_a=create();
    waste=pre_a;
    pre_a->next=pa;
    while(pa&&pb)
    {
        if(pb->data > pa->data)
        {
            pa=pa->next;
            pre_a=pre_a->next;
        }
        else if(pa->data>pb->data)
        {
            tmp=create();
            tmp->data=pb->data;
            tmp->next=pa;
            pre_a->next=tmp;
            pre_a=tmp;
            pb=pb->next;
        }
        else
        {
            pa=pa->next;
            pb=pb->next;
        }
    }
    if(!pa&&pb)
    {
        pa=pre_a;
        while(pb)
        {
            tmp=create();
            tmp->data=pb->data;
            pa->next=tmp;
            pa=tmp;
            pb=pb->next;
        }
    }
    free(waste);
}


int main()
{
    LinkList ha,hb,pa,pb,tmp;
    int n,v,i;
    ha=create();
    hb=create();
    pa=ha;
    pb=hb;
    scanf("%d",&n);
    scanf("%d",&v);
    pa->data=v;
    for(i=1;i<n;i++)
    {
        scanf("%d",&v);
        tmp=create();
        tmp->data=v;
        pa->next=tmp;
        pa=tmp;
    }
    scanf("%d",&n);
    scanf("%d",&v);
    pb->data=v;
    for(i=1;i<n;i++)
    {
        scanf("%d",&v);
        tmp=create();
        tmp->data=v;
        pb->next=tmp;
        pb=tmp;
    }
    merge_list(ha,hb);
    pa=ha;
    while(pa)
    {
        printf("%d ",pa->data);
        pa=pa->next;
    }
    printf("END !\n");
    return 0;
}


        
        
        
        
