#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAXSIZE 100

typedef int DataType;

typedef struct SeqList {
	DataType array[MAXSIZE];
	int size; 		//��Ч����Ԫ�صĸ���
} SeqList;

//----����������--------
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

//������������������ 
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
	printf("λ��Ϊ��%d\n",index_1);
	index_2 = BinarySearch(&L,8);
	printf("λ��Ϊ��%d\n",index_2);
	BubbleSort(&L);
	PrintSeqList(&L);
	SelectSort(&L);
	PrintSeqList(&L);
	Remove(&L,8);
	PrintSeqList(&L);
	RemoveAll(&L,7);
	PrintSeqList(&L);
} 

//��ӡ˳��� 
void PrintSeqList(SeqList *seq){
	assert(seq);
	int i = 0;
	for(i = 0;i < seq->size;i++){
		printf("%d ",seq->array[i]);
	}
	printf("\n");
}


//��ʼ��˳���
void InitSeqList(SeqList *seq){
	assert(seq);
	int i = 0;
	for(i = 0;i < MAXSIZE; i++){
		seq -> array[i] = 0;
	}
	seq -> size = 0;
	 
} 


//��˳����β������ֵΪdata��Ԫ��
void PushBack(SeqList *pSeq,DataType data){
	
	assert(pSeq);
	if(pSeq -> size == MAXSIZE){
		printf("���������޷����룡");
		return  ;
	}
	int i = pSeq -> size;
	pSeq->array[i] = data; 
	pSeq -> size++; 
} 


//ɾ��˳�������һ��Ԫ��
void PopBack(SeqList *pSeq){
	assert(pSeq);
	if(pSeq->size == 0){
		printf("���Կգ�");
		return ; 
	}
	
	pSeq->size--;	
} 

//��˳����ͷ������ֵΪdata��Ԫ��
void PushFront(SeqList *pSeq,DataType data){
	assert(pSeq);
	
	if(pSeq -> size == MAXSIZE){
		printf("��������");
		return ; 
	}
	int i = 0;
	//����Ԫ�غ��� 
	for(i = pSeq->size;i>0;i--){
		pSeq->array[i] = pSeq->array[i - 1]; 
	}
	pSeq ->array[i] = data;
	pSeq->size++; 
} 

//ɾ��˳���Ԫ�ص�ͷ��Ԫ��
void PopFront(SeqList *pSeq){
	assert(pSeq);
	if(pSeq->size == 0){
		printf("���Կգ�"); 
		return ;
	} 
	
	int i = 0;
	//array[1]��ʼȫ��ǰ�� 
	for(i = 0;i < pSeq->size;i++){
		pSeq->array[i] = pSeq->array[i + 1]; 
	}
	pSeq->size--; 
} 

//��˳�����posλ���ϲ���ֵΪdata��Ԫ��
void Insert(SeqList *pSeq,int pos,DataType data){
	assert(pSeq);
	if(pSeq->size == MAXSIZE || pos > pSeq->size){
		printf("��������λ�ò��Ϸ���");
		return ; 
	}
	int i = 0;
	for(i = pSeq->size;i > pos;i--){
		pSeq->array[i] = pSeq->array[i-1];
	}
	
	pSeq->array[i] = data;
	pSeq->size++;  
	
} 
 
//ɾ��˳�����posλ���ϵ�Ԫ��
void Erase(SeqList *pSeq,int pos){
	assert(pSeq);
	if(pSeq->size == 0 || pos >= pSeq->size){
		printf("��Ϊ�ջ�λ�ò��Ϸ���");
		return ; 
	}
	int i = 0;
	for(i = pos;i < pSeq->size;i++){
		pSeq->array[i] = pSeq->array[i + 1];
	}
	pSeq->size--; 
	
} 

//��˳����в���ֵΪdata��Ԫ�أ��ҵ����ظ�Ԫ�ص�λ�ã����򷵻�-1
int Find(SeqList *pSeq ,DataType data){
	assert(pSeq);
	int i ;
	//���� 
	for(i = 0;i<pSeq->size;i++){
		if(pSeq->array[i] == data){
			
		 return i;
	}
	
  }
  return -1;
}


//ɾ��˳����е�һ��ֵΪdata��Ԫ��
void Remove(SeqList *pSeq,DataType data){
	int pos = BinarySearch(pSeq,data);
	if(pos >= 0){
		Erase(pSeq,pos);
	}else{
		printf("error\n");
	}
} 

//ɾ��˳���������ֵΪdata��Ԫ��
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


//ʹ��ð�������˳����е�Ԫ������
void BubbleSort(SeqList *pSeq){
	
	assert(pSeq);
	int j,flag;
	int i = 0;
	int count = 0;
	for(i = 0;i < pSeq->size - 1;i++){
		for(j = 0;j < pSeq->size - 1 - i;j++){
			if(pSeq->array[j]>pSeq->array[j+1]){
				//Ԫ�ػ��� 
				int temp = pSeq->array[j];
				pSeq->array[j] = pSeq->array[j + 1];
				pSeq->array[j + 1] = temp;
				flag = 1;	
			}
		}
		if(!flag) return;
	}
} 


//ʹ��ѡ�������˳�����Ԫ������
void SelectSort(SeqList *pSeq){
	
	assert(pSeq);
	
	int i = 0, j = 0;
	//����̨ 
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

//�ö��ַ�����˳����е�Ԫ�� 
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





 

