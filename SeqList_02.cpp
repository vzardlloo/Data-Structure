#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXSIZE 100

typedef int DataType;

typedef struct SeqList {
	DataType array[MAXSIZE];
	int size; 		//有效数据元素的个数
} SeqList;

//----函数申明区--------
void PrintSeqList(SeqList *seq);
void InitSeqList(SeqList *seq);
void PushBack(SeqList *pSeq,DataType data);
void PopBack(SeqList *pSeq);
void PushFront(SeqList *pSeq,DataType data);
void PopFront(SeqList *pSeq);
void Insert(SeqList *pSeq,int pos,DataType data);
void Erase(SeqList *pSeq,int pos);
int Find(SeqList *pSeq ,DataType data);
void Remove(SeqList *pSeq,DataType data);
void RemoveAll(SeqList *pSeq,DataType data);
void BubbleSort(SeqList *pSeq);
void SelectSort(SeqList *pSeq);
int BinarySearch(SeqList *pSeq,DataType data);
//----------------------

//主函数（测试用例） 
int main(){
	int index_1,index_2; 
	
	SeqList L;
	InitSeqList(&L);
	PushFront(&L,8);
	PushFront(&L,7);
	PushFront(&L,6);
	PushFront(&L,5);
	PrintSeqList(&L);
	PushBack(&L,7);
	PushBack(&L,9);
	PushBack(&L,3);
	PrintSeqList(&L);
	PopBack(&L); 
	PrintSeqList(&L);
	PopFront(&L);
	PrintSeqList(&L);
	Insert(&L,2,2);
	PrintSeqList(&L);
	Erase(&L,2);
	PrintSeqList(&L);
	index_1 = Find(&L,9);
	printf("位置为：%d\n",index_1);
	index_2 = BinarySearch(&L,8);
	printf("位置为：%d\n",index_2);
	BubbleSort(&L);
	PrintSeqList(&L);
	SelectSort(&L);
	PrintSeqList(&L);
	Remove(&L,8);
	PrintSeqList(&L);
	RemoveAll(&L,7);
	PrintSeqList(&L);
} 

//打印顺序表 
void PrintSeqList(SeqList *seq){
	assert(seq);
	int i = 0;
	for(i = 0;i < seq->size;i++){
		printf("%d ",seq->array[i]);
	}
	printf("\n");
}


//初始化顺序表
void InitSeqList(SeqList *seq){
	assert(seq);
	int i = 0;
	for(i = 0;i < MAXSIZE; i++){
		seq -> array[i] = 0;
	}
	seq -> size = 0;
	 
} 


//在顺序表的尾部插入值为data的元素
void PushBack(SeqList *pSeq,DataType data){
	
	assert(pSeq);
	if(pSeq -> size == MAXSIZE){
		printf("表已满！无法插入！");
		return  ;
	}
	int i = pSeq -> size;
	pSeq->array[i] = data; 
	pSeq -> size++; 
} 


//删除顺序表的最后一个元素
void PopBack(SeqList *pSeq){
	assert(pSeq);
	if(pSeq->size == 0){
		printf("表以空！");
		return ; 
	}
	
	pSeq->size--;	
} 

//在顺序表的头部插入值为data的元素
void PushFront(SeqList *pSeq,DataType data){
	assert(pSeq);
	
	if(pSeq -> size == MAXSIZE){
		printf("表已满！");
		return ; 
	}
	int i = 0;
	//所有元素后移 
	for(i = pSeq->size;i>0;i--){
		pSeq->array[i] = pSeq->array[i - 1]; 
	}
	pSeq ->array[i] = data;
	pSeq->size++; 
} 

//删除顺序表元素的头部元素
void PopFront(SeqList *pSeq){
	assert(pSeq);
	if(pSeq->size == 0){
		printf("表以空！"); 
		return ;
	} 
	
	int i = 0;
	//array[1]开始全部前移 
	for(i = 0;i < pSeq->size;i++){
		pSeq->array[i] = pSeq->array[i + 1]; 
	}
	pSeq->size--; 
} 

//在顺序表中pos位置上插入值为data的元素
void Insert(SeqList *pSeq,int pos,DataType data){
	assert(pSeq);
	if(pSeq->size == MAXSIZE || pos > pSeq->size){
		printf("表以满或位置不合法！");
		return ; 
	}
	int i = 0;
	for(i = pSeq->size;i > pos;i--){
		pSeq->array[i] = pSeq->array[i-1];
	}
	
	pSeq->array[i] = data;
	pSeq->size++;  
	
} 
 
//删除顺序表中pos位置上的元素
void Erase(SeqList *pSeq,int pos){
	assert(pSeq);
	if(pSeq->size == 0 || pos >= pSeq->size){
		printf("表为空或位置不合法！");
		return ; 
	}
	int i = 0;
	for(i = pos;i < pSeq->size;i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--; 
	
} 

//在顺序表中查找值为data的元素，找到返回该元素的位置，否则返回-1
int Find(SeqList *pSeq ,DataType data){
	assert(pSeq);
	int i ;
	//遍历 
	for(i = 0;i<pSeq->size;i++){
		if(pSeq->array[i] == data){
			
		 return i;
	}
	
  }
  return -1;
}


//删除顺序表中第一个值为data的元素
void Remove(SeqList *pSeq,DataType data){
	int pos = BinarySearch(pSeq,data);
	if(pos >= 0){
		Erase(pSeq,pos);
	}else{
		printf("error\n");
	}
} 

//删除顺序表中所有值为data的元素
void RemoveAll(SeqList *pSeq,DataType data){
	assert(pSeq);
	int i = 0;
	int count = 0;
	for(i = 0;i < pSeq->size;i++){
		if(pSeq->array[i] == data) count ++;
		else pSeq->array[i - count] = pSeq->array[i]; 
	} 
	
	pSeq->size -= count;
} 


//使用冒泡排序给顺序表中的元素排序
void BubbleSort(SeqList *pSeq){
	
	assert(pSeq);
	int j,flag;
	int i = 0;
	int count = 0;
	for(i = 0;i < pSeq->size - 1;i++){
		for(j = 0;j < pSeq->size - 1 - i;j++){
			if(pSeq->array[j]>pSeq->array[j+1]){
				//元素互换 
				int temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j + 1];
				pSeq->array[j + 1] = temp;
				flag = 1;	
			}
		}
		if(!flag) return;
	}
} 


//使用选择排序给顺序表中元素排序
void SelectSort(SeqList *pSeq){
	
	assert(pSeq);
	
	int i = 0, j = 0;
	//打擂台 
	for(i = 0;i < pSeq->size - 1;i++){
		for(j = i+1;j < pSeq->size;j++){
			if(pSeq->array[i] > pSeq->array[j]){
				
				int temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[i];
				pSeq->array[i] = temp;
				
			}
		}
	}
} 

//用二分法查找顺序表中的元素 
int BinarySearch(SeqList *pSeq,DataType data){
	
	assert(pSeq);
	int left = 0;
	int right = pSeq->size - 1;
	int mid = left + ((right + left) >> 1);
	while(left <= right){
		
		if(pSeq->array[mid] == data){
			return mid;
		}
		else if(pSeq->array[mid] > data){
			right = mid - 1;
			mid = left + ((right - left) >> 1);
		}
		else{
			left = mid + 1;
			mid = left + ((right - left) >> 1);
		}
	} 
	return -1;
} 





 

