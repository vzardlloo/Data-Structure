#include<stdio.h>
#include<stdlib.h>
void scanfNum();

int main(){
	
  scanfNum();	
	
	

	
	
	
	
} 

	void  scanfNum(){
		int max;
		int * Num;
		printf("��������������Ԥ�������������ĸ�����");
		scanf("%d",&max);
		Num = (int *) malloc (max * sizeof(int)); 
		if(Num == NULL){
			printf("Something error!");
			exit(EXIT_FAILURE);
		}
		
	}
