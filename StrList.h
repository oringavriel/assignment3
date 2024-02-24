
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct _node Node;


struct _StrList ;

typedef struct _StrList StrList;


Node* Node_alloc(const char* s, Node* next) ;

StrList* StrList_alloc() ;

void StrList_free(StrList* StrList) ;

size_t StrList_size(const StrList* StrList) ;

void StrList_insertLast(StrList* StrList, const char* data);

void StrList_insertAt(StrList* StrList, const char* data,int index) ;

char* StrList_firstData(const StrList* StrList) ;

void StrList_print(const StrList* StrList) ;

void StrList_printAt(const StrList* Strlist,int index) ;

int StrList_printLen(const StrList* Strlist);

int StrList_count(StrList* StrList, const char* data) ;

void StrList_remove(StrList* StrList, const char* data);

void StrList_removeAt(StrList* StrList, int index);

int StrList_isEqual(const StrList* StrList1, const StrList* StrList2);
   
StrList* StrList_clone(const StrList* StrList);

void StrList_reverse( StrList* StrList);

void StrList_sort( StrList* StrList);

int StrList_isSorted(StrList* StrList);


int liStrList_size (StrList* StrList);