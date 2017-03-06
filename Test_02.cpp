#include<stdio.h>
#include<stdlib.h>
void scanfNum();

int main(){
	
  scanfNum();	
	
	

	
	
	
	
} 

	void  scanfNum(){
		int max;
		int * Num;
		printf("请输入这组数的预期最多包含的数的个数：");
		scanf("%d",&max);
		Num = (int *) malloc (max * sizeof(int)); 
		if(Num == NULL){
			printf("Something error!");
			exit(EXIT_FAILURE);
		}
		
	}
