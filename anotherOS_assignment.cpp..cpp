#include<stdio.h>
struct process{
	int AT,BT,TAT,WT;
	char name;
}Q1[10],Q2[10];

int n;

void sortByBurst(){
	struct process temp;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(Q2[i].BT>Q2[j].BT){
				temp=Q2[i];
				Q2[i]=Q2[j];
				Q2[j]=temp;
			}
		}
	}	
}

void sortByArrival(){
	struct process temp;
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(Q1[i].AT>Q1[j].AT){
				temp=Q1[i];
				Q1[i]=Q1[j];
				Q1[j]=temp;
			}
		}
	}	
}

int main(){
	printf("enter the no of processes\t");
	scanf("%d",&n);
	int i;
	char c;
	for(i=0,c='A';i<n;i++,c++){
		Q1[i].name=c;
		printf("enter the AT and BT for process %c",c);
		scanf("%d %d",&Q1[i].AT,&Q1[i].BT);	
	}
	sortByArrival();
	printf("The order of the processes given to the primary memory\n");
	printf("name\tAT\tBT\n");
	for(i=0;i<n;i++){
		printf("%c\t%d\t%d\t\n",Q1[i].name,Q1[i].AT,Q1[i].BT);
	}
	for(i=0;i<n;i++){
		Q2[i]=Q1[i];
	}
	sortByBurst();
	for(i=1;i<n;i++){
		Q2[i].WT=Q2[i-1].BT + Q2[i-1].WT;
	}
	for(i=1;i<n;i++){
		Q2[i].TAT=Q2[i].BT + Q2[i].WT;
	}
	printf("The order of the processes for allocation of CPU\n");
	printf("name\tAT\tBT\tTAT\tWT\n");
	for(i=0;i<n;i++){
		printf("%c\t%d\t%d\t%d\t%d\n",Q2[i].name,Q2[i].AT,Q2[i].BT,Q2[i].TAT,Q2[i].WT);
	}
	
}

