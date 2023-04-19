#include <stdio.h>
#include <stdlib.h>
typedef struct n {
    int data;
    struct n* next;
} node;

node* eklesirali(node* root,int a){
    if(root==NULL){
        root=(node*)malloc(sizeof(node));
        root->next=root;
        root->data=a;
        return root;
    }
    if(root->data >a){
        node* temp;
        node* iter=root;
        temp=(node*)malloc(sizeof(node));
        temp->data=a;
        temp->next=root;
        while(iter->next!=root)
            iter=iter->next;
        iter->next=temp;
        return temp;
    }
     node* iter;
     iter=root;
     while(iter->next!=root && iter->next->data<a){
        iter=iter->next;}
     node* temp=(node*)malloc(sizeof(node));
     temp->next=iter->next;
     iter->next=temp;
     temp->data=a;
     return root;
}

node* sil(node* root,int x){
    node* iter=root;
    if(x==root->data){ //bastan silme
        root=root->next;
        free(iter);
        node* temp=root;
        while(temp->next!=root)
            temp=temp->next;
        temp->next=root;
        return root;
    }
    while(iter->next!=root && iter->next->data!=x){
        iter=iter->next;
    }
    if(iter->next==root){
            printf("Sayi bulunamadi \n");
            return root;
    }
    node* temp=iter->next;
    iter->next=iter->next->next;
    return root;
}




void bastir(node* a){
    node* temp;
    temp=a;
    printf("%d ",temp->data);
    temp=temp->next;
    while(temp->next!=a){
        printf("%d  ",temp->data);
        temp=temp->next;
        }
        printf("\n");
}



int main()
{
    node* root;
    root=NULL;
    root=eklesirali(root,400);
    root=eklesirali(root,40);
    root=eklesirali(root,4);
    root=eklesirali(root,450);
    root=eklesirali(root,50);
    bastir(root);
    root=sil(root,4);
    bastir(root);
    root=sil(root,450);
    bastir(root);
    root=sil(root,456);
    bastir(root);
    root=sil(root,50);
    bastir(root);

    return 0;
}
