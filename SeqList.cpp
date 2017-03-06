#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100


typedef struct node{
	int data[MAXSIZE];
	int length; 
	
} SeqList, * PSeqList; 


//函数声明
PSeqList Init_SeqList();
int Length_SeqList(PSeqList L);
int Location_SeqList(PSeqList L,int data);
int Insert_SeqList(PSeqList L,int x,int i);
int Delete_SeqList(PSeqList L,int i); 
void Print_SeqList(PSeqList L);


//主函数入口 
int main(){
	PSeqList L = Init_SeqList();
	int x =Length_SeqList(L);
	printf("当前顺序表长度为：%d\n",x);
	Print_SeqList(L); 
	
}

/*
  初始化顺序表 
  创建一个顺序表，入口参数无，返回一个指向顺序表的指针，指针值为零表示分配失败 
*/

	PSeqList Init_SeqList(){
		PSeqList PL;
		int i = 1;
		int t,j;
		PL = (PSeqList)malloc(MAXSIZE*sizeof(SeqList));
		while(PL && getchar() != '#'){
		
			scanf("%d",&t);
			
			Insert_SeqList(PL,t,i++);
			PL->length = i; 
	
		}
		
		return(PL);
	}
	
	//获取顺序表的长度 
	int Length_SeqList(PSeqList L){
		return(L->length-1);
	} 
	
	//检索数据表,返回目标数据在表中的位置 
	int Location_SeqList(PSeqList L,int data){
		int i = 0;
		while (i<L->length && L->data[i] != data) i++;
		if(i>=L->length) printf("数据不在表中！"); 
		else return (i+1); 
		
	} 
	
	//数据表插入操作 
	//parm:L 目标顺序表 
	//parm:i 插入位置（前插） 
	//parm:x 插入的数据 
	int Insert_SeqList(PSeqList L,int x,int i) {
		int j;
		if(!L){
			printf("表不存在！");
			return(-2); 
		}	
		if(L->length > MAXSIZE){
			printf("表溢出！");
			return(-1); 
		}
		if(i < 1 || i > L->length+1){
			printf("插入位置不合法！");
			return 0; 
		}
		for(j=L->length-1;j>i-1;j--){
			L->data[j+1] = L->data[j];
			L->data[i-1] = x;
			L->length++;
			return 1;
		}
		
	} 
	
	int Delete_SeqList(PSeqList L,int i){
		int j;
		if(!L){
			printf("表不存在！");
			return (-1); 
		}
		if(i<1||i >L->length){
			printf("删除位置不合法！");
			return 0; 
		}
		
		for(j=i-1;j<L->length;j++){
			L->data[j-1] = L->data[j];
			L->length --;
			return (1);
		}
	}
	
	
	void Print_SeqList(PSeqList L){
		assert(L);
		int i;
		for(i=0;i<L->length;i++){
			printf("%d",L->data[i]);
		}
		
		
	}
