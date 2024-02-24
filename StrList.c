
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "StrList.h"



typedef struct _node {
    char* _s;
    struct _node * _next;
} Node;


struct _StrList {
    Node* _head;
    int _size;
};

typedef struct _StrList StrList;


Node* Node_alloc(const char* s, Node* next) {
Node* p= (Node*)malloc(sizeof(Node));
p->_s= strdup(s);
p->_next= next;
return p;
}


StrList* StrList_alloc() {
StrList* p= (StrList*)malloc(sizeof(StrList));
p->_head= NULL;
p->_size= 0;
return p;
}

void StrList_free(StrList* StrList) {
    if (StrList==NULL){ return; }
Node* p1= StrList->_head;
Node* p2;
while(p1) {
p2= p1;
p1= p1->_next;
free(p2);
}
free(StrList);
}

size_t StrList_size(const StrList* StrList) {
    return StrList->_size;
}

void StrList_insertLast(StrList* StrList, const char* data) {
    if (StrList->_head==NULL) {
        StrList->_head = Node_alloc(data,NULL);
        }
    else {
    Node* p= StrList->_head;
    while ((p->_next)!=NULL) {
        p=p->_next;
    }
    p->_next = Node_alloc(data,NULL);
}
        StrList->_size++;
}

void StrList_insertAt(StrList* StrList, const char* data,int index) {
    if (StrList->_head==NULL || StrList->_size < index ) {
        return;
        }
    else if (index==0) {
        StrList->_head= Node_alloc(data, StrList->_head);
        StrList->_size++;
    }
    else if (index==StrList->_size){
        StrList_insertLast(StrList,data);
    }
    else {
        Node* p= StrList->_head;
        Node* prev= StrList->_head;
            int count=0;
            while ((p->_next)!=NULL) {
                prev=p;
                p= p->_next;
                count++;
                if (count==index) {
                    break;
                   
                }
            }
            p= Node_alloc(data, p);
            prev->_next= p;
           StrList->_size++;
        }
    }
   



char* StrList_firstData(const StrList* StrList) {
    return StrList->_head->_s;
}


void StrList_print(const StrList* StrList) {
    Node* p= StrList->_head;
while(p->_next) {
printf("%s ",p->_s);
p= p->_next;
}
printf("%s",p->_s);
printf("\n");
}

void StrList_printAt(const StrList* Strlist,int index) {
     if (Strlist->_head==NULL || Strlist->_size -1 < index ) {
        return;
        }
    else if (index==0) {
        printf("%s\n", Strlist->_head->_s);
    }
    else {
        Node* p= Strlist->_head;
            int count=0;
            while (p) {
                p= p->_next;
                count++;
                if (count==index) {
                  printf("%s\n", p->_s);
                   
                }
        }
}
}

int StrList_printLen(const StrList* Strlist){
     Node* p= Strlist->_head;
       int count=0;
            while (p) {
                count= count+ strlen(p->_s);
                p= p->_next;
            }
            return count;
   
}

int StrList_count(StrList* StrList, const char* data) {
     Node* p= StrList->_head;
     int count=0;
     while (p) {
         if (strcmp(p->_s, data)==0){
             count++;
             }
             p= p->_next;
     }
     return count;
}

void StrList_remove(StrList* StrList, const char* data){
    if ( strcmp(StrList->_head->_s, data)==0) {
         Node* p= StrList->_head-> _next;
         free(StrList->_head);
         StrList->_head= p;
         StrList->_size--;
    }
    Node* prev= StrList->_head;
    Node* p= prev->_next;
    Node* temp= p->_next;
    while ((p->_next)!=NULL) {
        if (strcmp(p->_s, data)==0){
            free(p);
            prev->_next=temp;
            p=temp;
            temp=p->_next;
            StrList->_size--;
        }
        else{
        prev=prev->_next;
        p=p->_next;
        temp=temp->_next;
        }
    }
    if ( strcmp(p->_s, data)==0) {
        free(p);
        prev->_next=NULL;
        StrList->_size--;

    }
       
}

void StrList_removeAt(StrList* StrList, int index){
     if (StrList->_head==NULL || StrList->_size-1 < index ) {
        return;
        }
    else if (index==0) {
         Node* p= StrList->_head-> _next;
         free(StrList->_head);
         StrList->_head= p;
         StrList->_size--;
    }
    else{
    int count=1;
    Node* prev= StrList->_head;
    Node* p= prev->_next;
    Node* temp= p->_next;
    while ((p->_next) !=NULL) {
        if ( index==count){
           break;
        }
        else{
        prev=prev->_next;
        p=p->_next;
        temp=temp->_next;
        count++;
        }
    }
        if (index== StrList->_size-1) {
            free(p);
            prev->_next=NULL;
            StrList->_size--;
        }
        else {
            free(p);
            prev->_next=temp;
            p=temp;
            temp=p->_next;
            StrList->_size--;
        }
    }
}


int StrList_isEqual(const StrList* StrList1, const StrList* StrList2){
    if (StrList1->_size!=StrList2->_size) {
        return 0;
    }
    else {
        Node* p1= StrList1->_head;
        Node* p2= StrList2->_head;
        while (p1){
            if (strcmp(p1->_s,p2->_s)==1) {
                return 0;
            }
            p1=p1->_next;
            p2=p2->_next;
        }
        return 1;
        }
    }
   
   
StrList* StrList_clone(const StrList* StrList) {
   
  struct _StrList *cloneList= NULL;
  cloneList = StrList_alloc();
  Node* p1= StrList->_head;
  while(p1){
        StrList_insertLast(cloneList,p1->_s);
        p1=p1->_next;
   }
   
   return cloneList;
}




void StrList_reverse( StrList* StrList){
    int count=1;
    Node* p= StrList->_head;
    while(count<=StrList->_size){
        StrList_insertAt(StrList,p->_s,0);
        p=p->_next;
        StrList_removeAt(StrList,count);
        count++;
    }
}

void swapNodes(Node* p,Node* p1 ){
     char* temp=p->_s;
     p->_s=p1->_s;      
     p1->_s=temp;
   
}

void StrList_sort( StrList* StrList){
    Node* p= StrList->_head;
    Node* p1= StrList->_head->_next;
    int i;
    int length=StrList->_size;
    for(i=0; i<length ;i++){
         p= StrList->_head;
         p1= StrList->_head->_next;
        while(p1){
            if(strcmp(p->_s,p1->_s)>0){
               swapNodes(p,p1);
            }  
            p=p->_next;
            p1=p1->_next;
        }
    }
   
   
}

int StrList_isSorted(StrList* StrList){
    Node* p= StrList->_head;
    Node* p1= StrList->_head->_next;
   
    if(p==NULL){
        return 1;
    }
    else{
       
        while(p1){
            if(strcmp(p->_s,p1->_s)>0){
                return 0;
            }
            p=p->_next;
            p1=p1->_next;
        }
    }

   return 1;

   
}

	

int liStrList_size (StrList* StrList){
    return StrList->_size;
}

