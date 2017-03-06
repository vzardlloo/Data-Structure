#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXSIZE 100


typedef struct node{
	int data[MAXSIZE];
	int length; 
	
} SeqList, * PSeqList; 


//��������
PSeqList Init_SeqList();
int Length_SeqList(PSeqList L);
int Location_SeqList(PSeqList L,int data);
int Insert_SeqList(PSeqList L,int x,int i);
int Delete_SeqList(PSeqList L,int i); 
void Print_SeqList(PSeqList L);


//��������� 
int main(){
	PSeqList L = Init_SeqList();
	int x =Length_SeqList(L);
	printf("��ǰ˳�����Ϊ��%d\n",x);
	Print_SeqList(L); 
	
}

/*
  ��ʼ��˳��� 
  ����һ��˳�����ڲ����ޣ�����һ��ָ��˳����ָ�룬ָ��ֵΪ���ʾ����ʧ�� 
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
	
	//��ȡ˳���ĳ��� 
	int Length_SeqList(PSeqList L){
		return(L->length-1);
	} 
	
	//�������ݱ�,����Ŀ�������ڱ��е�λ�� 
	int Location_SeqList(PSeqList L,int data){
		int i = 0;
		while (i<L->length && L->data[i] != data) i++;
		if(i>=L->length) printf("���ݲ��ڱ��У�"); 
		else return (i+1); 
		
	} 
	
	//���ݱ������� 
	//parm:L Ŀ��˳��� 
	//parm:i ����λ�ã�ǰ�壩 
	//parm:x ��������� 
	int Insert_SeqList(PSeqList L,int x,int i) {
		int j;
		if(!L){
			printf("�����ڣ�");
			return(-2); 
		}	
		if(L->length > MAXSIZE){
			printf("�������");
			return(-1); 
		}
		if(i < 1 || i > L->length+1){
			printf("����λ�ò��Ϸ���");
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
			printf("�����ڣ�");
			return (-1); 
		}
		if(i<1||i >L->length){
			printf("ɾ��λ�ò��Ϸ���");
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
