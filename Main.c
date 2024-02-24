#include <stdio.h>
#include "StrList.h"
#define maxStrLength 100

int main(){

StrList *list= StrList_alloc();
int choose;
int index;  
char s[maxStrLength];

while(1){

    scanf("%d",&choose);

    if(choose==1){

        
        int numOfWords;
        scanf("%d",&numOfWords);
            int i;
            for ( i = 0; i < numOfWords; i++)
            {
               scanf("%s", s);
       
                StrList_insertLast(list, s);
            }

      
    }

    else if(choose==2){

        scanf( "%d  %99s",&index,s);
        StrList_insertAt(list,s,index);

    }

    else if(choose==3){
        StrList_print(list);
    }

    else if(choose==4){
       int i=  liStrList_size (list);
       printf("%d\n",i);
    }

    else if(choose==5){
        scanf("%d",&index);
        StrList_printAt(list, index);
    }

    else if(choose==6){
        int i= StrList_printLen(list);
        printf("%d\n",i);
    }

    else if(choose==7){
        scanf( "%99s",s);
        int i=StrList_count(list,s);
        printf("%d\n",i);
    }

    else if(choose==8){
        scanf( "%99s",s);
        StrList_remove(list,s);
    }

    else if(choose==9){
        scanf("%d",&index);
        StrList_removeAt(list, index);
    }

    else if(choose==10){
        StrList_reverse(list);
    }

    else if(choose==11){
    StrList_free(list);

    }

    else if(choose==12){
        StrList_sort(list);
    }

    else if(choose==13){
       int i= StrList_isSorted(list);
       if(i==1){
        printf("true\n");
       }
       else{
        printf("false\n");
       }
    }

    else if(choose==0){
        break;
    }
}

StrList_free(list);


}
