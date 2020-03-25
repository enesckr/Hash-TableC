#include<stdio.h>

struct act{
	int key,value;
};
int hashfunc(int x,int size1){
	return x%size1;
}
void display(struct act table[],int size1){
	int i;
	printf("\n");
	printf("Key\tValue\n");
	for(i=0;i<size1;i++){
		printf("%d\t%d\n",table[i].key,table[i].value);
	}
}
void main(){
	
	int i,size,temp,elementsize,stemp,f=0,ind,ntemp;
	printf("Enter size of the table:");
	scanf("%d",&size);
	
	struct act hashTable[size];
	
	for(i=0;i<size;i++){
		hashTable[i].value=-1;
		hashTable[i].key=-1;
	}
	printf("How much element do you want to enter:");
	scanf("%d",&elementsize);
	printf("Enter the elements:");
	for(i=0;i<elementsize;i++){
		scanf("%d",&temp);
		if(hashTable[hashfunc(temp,size)].value == -1){
			hashTable[hashfunc(temp,size)].value=hashfunc(temp,size);
			hashTable[hashfunc(temp,size)].key=temp;
		}
		else{
			int donus=0;
			ind=hashfunc(temp,size);
			while(hashTable[ind].value != -1){
				ind++;
				if(ind==size){
					if(donus==1){
						printf("Table is full");
					}
					ind=0;
					donus++;	
				}
			}
			hashTable[ind].value=hashfunc(temp,size);
			hashTable[ind].key=temp;
		}
	}
	display(hashTable,size);
	
	printf("\n\nEnter value for look element:");
	scanf("%d",&stemp);
	for(i=0;i<size;i++){
		if(stemp==hashTable[i].value){
			printf("Element=%d\n",hashTable[i].key);f++;
		}
	}
	if(f==0){
		printf("Element not found");
	}

	printf("\n\nDo you want add element:");
	scanf("%d",&ntemp);
	if(hashTable[hashfunc(ntemp,size)].value == -1){
			hashTable[hashfunc(ntemp,size)].value=hashfunc(ntemp,size);
			hashTable[hashfunc(ntemp,size)].key=ntemp;
		}
		else{
			int donus=0;
			ind=hashfunc(ntemp,size);
			while(hashTable[ind].value != -1){
				ind++;
				if(ind==size){
					if(donus==1){
						printf("Table is full");
					}
					ind=0;
					donus++;	
				}
			}
			hashTable[ind].value=hashfunc(ntemp,size);
			hashTable[ind].key=ntemp;
		}
		display(hashTable,size);
	}
	
