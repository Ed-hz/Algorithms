#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "5-6.h"
#include "5-12.h"
#include "5-1.h"
#include "5-7.h"
#include "5-8.h"
#include "5-9.h"
#include "5-10.h"
#include "5-13.h"
#include "5-14.h"
#include "5-15.h"

int main()
{
/* 1 */     int TableSize = 100; /* 散列表的估计大小，可以根据应用更改 */
	        int wordcount = 0, length;
            HashTable H;
            ElementType word;
	        FILE *fp;
/* 2 */     char document[30] = "HarryPotter.txt";
                              /* 要被统计词频的文件名 */

/* 3 */     H = InitializeTable( TableSize ); /* 建立散列表 */

/* 4 */     if(( fp = fopen(document, "r" )) == NULL)
                FatalError("无法打开文件！\n" );
                   	
           	while( !feof( fp ) ){
/* 5 */        length = GetAWord( fp, word );
/* 6 */        if(length > 3){     /* 只考虑长度大于3个字符的单词 */
/* 7 */	         wordcount++;      
/* 8 */	         InsertAndCount( word, H );
		       }
   	        }
   	        fclose( fp );

/* 9 */    printf("该文档共出现 %d 个有效单词", wordcount);
/* 10 */   Show( H, 10.0/100 );  /* 显示词频前10%的所有单词 */
/* 11 */   DestroyTable( H );    /* 销毁散列表 */
		   return 0;
}
