#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include"Sorting.h"
#define Size 1000000

int main(){
	int data1[Size], i, j, flag;
	char data2[Size][101];
	FILE *fp, *fp2;//, *fp3, *fp4;
	fp = fopen("database1.txt", "w");
	fp2 = fopen("database2.txt", "w");
	//fp3 = fopen("output1.txt", "w");
	//fp4 = fopen("output2.txt", "w");
	struct timeval start;
	struct timeval end;
	unsigned long diff;//diff用微秒表示

	printf("generate  random intger array and  random string array...\n");
	srand(1);
	for (i = 0; i < Size; i++)
	{
		data1[i] = rand();
		fprintf(fp, "%d\n", data1[i]);
	}//產生整數的亂數
	for(i = 0; i < Size; i++){
		for(j = 0; j < 100; j++){
			flag = rand()%2;
			if(flag)
				data2[i][j] = 'A' + rand()%26;
			else
				data2[i][j] = 'a' + rand()%26;
		}
		data2[i][j] = '\0';
		fprintf(fp2, "%s\n", data2[i]);
	}//產生大小為100的隨機字串

	gettimeofday(&start, NULL);
	quicksort_num(data1, 0, Size -1);
	gettimeofday(&end, NULL);
	diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
	printf("quicksort_num  perform %f s\n", (float)diff/1000000);

	gettimeofday(&start, NULL);
        quicksort_string(data2, 0, Size -1);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
        printf("quicksort_string  perform %f s\n", (float)diff/1000000);
	
	printf("initialize the sorted array to unsorted array....\n");
	srand(1);
	for (i = 0; i < Size; i++){
                data1[i] = rand();
        }//把剛剛排序過的再初始為原本
        for(i = 0; i < Size; i++){
                for(j = 0; j < 100; j++){
                        flag = rand()%2;
                        if(flag)
                                data2[i][j] = 'A' + rand()%26;
                        else
                                data2[i][j] = 'a' + rand()%26;
                }
                data2[i][j] = '\0';
        }//把剛剛排序過的再初始為原本

	gettimeofday(&start, NULL);
        mergeSort_num(data1, 0, Size -1);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
        printf("mergeSort_num  perform %f s\n", (float)diff/1000000);

	gettimeofday(&start, NULL);
        mergeSort_string(data2, 0, Size -1);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
        printf("mergeSort_string  perform %f s\n", (float)diff/1000000);

	printf("initialize the sorted array to unsorted array....\n");
        srand(1);
        for (i = 0; i < Size; i++){
                data1[i] = rand();
        }//把剛剛排序過的再初始為原本
        for(i = 0; i < Size; i++){
                for(j = 0; j < 100; j++){
                        flag = rand()%2;
                        if(flag)
                                data2[i][j] = 'A' + rand()%26;
                        else
                                data2[i][j] = 'a' + rand()%26;
                }
                data2[i][j] = '\0';
        }//把剛剛排序過的再初始為原本

	gettimeofday(&start, NULL);
        heapSort_num(data1, Size);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
        printf("heapSort_num  perform %f s\n", (float)diff/1000000);

	gettimeofday(&start, NULL);
        heapSort_string(data2, Size);
        gettimeofday(&end, NULL);
        diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;//tv_sec :秒, tv_usec:微秒
        printf("heapSort_string  perform %f s\n", (float)diff/1000000);
	
	/*
	for (i = 0; i < Size; i++)
                fprintf(fp3, "%d\n", data1[i]);
        
	for (i = 0; i < Size; i++)
                fprintf(fp4, "%s\n", data2[i]);
	*/
	
	fclose(fp);
	fclose(fp2);
	//fclose(fp3);
	//fclose(fp4);
	return 0;
}
