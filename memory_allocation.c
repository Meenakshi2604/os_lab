#include<stdio.h>
#include<stdlib.h>

void initializeZero(int arr[][3],int proc[][2],int size,int number){
    for(int i=0;i<size;i++){
        arr[i][0]=0;
        arr[i][2]=0;
    }
    for(int j=0;j<number;j++){
        proc[0][1]=0;
    }
}

void firstfit(int arr[][3], int proc[][2], int size, int number){
  for(int i=0;i<number;i++){
  	for(int j=0;j<size;j++){
  		if(arr[j][1]>=proc[i][0]&& arr[j][2]==0){
  			printf("Process %d allocated in memory of size %d with internal fragmentation as %d \n",i+1, arr[j][1],arr[j][1]-proc[i][0]);
  			arr[j][0]=proc[i][0];
  			arr[j][2]=1;
  			proc[i][1]=1;
  			break;	
  		}
  	}
  	if(proc[i][1]==0){
  		printf("Process P%d cannot be allocated \n",i+1);
  	}	
  }
  printf("The memory alocation of various processes ofthe size are as shown: \n");
  for(int k=0;k<size;k++){
  	if(arr[k][0]!=0)
  		printf("\t %d \t ",arr[k][0]);
  }
}

void bestfit(int arr[][3], int proc[][2], int size, int number){
  for(int i=0;i<number;i++){
  	int min = -1;
  	for(int j=0;j<size;j++){
  		if(arr[j][1]>=proc[i][0]&& arr[j][2]==0){
  		    proc[i][1]=1;
  			if(min == -1 || arr[min][1]>arr[j][1]){
  				min=j;
  			}
  		}
  	}
  	if(proc[i][1]==0){
  		printf("Process P%d cannot be allocated \n",i+1);
  	}
  	else{
  		printf("Process P%d allocated in memory of size %d with internal fragmentation as %d \n",i+1, arr[min][1],arr[min][1]-proc[i][0]);
  			arr[min][0]=proc[i][0];
  			arr[min][2]=1;
  	}
  }
  printf("The memory alocation of various processes ofthe size are as shown: \n");
  for(int k=0;k<size;k++){
  	if(arr[k][0]!=0)
  		printf("\t %d \t",arr[k][0]);
  }
}

void worstfit(int arr[][3], int proc[][2], int size, int number){
  for(int i=0;i<number;i++){
  	int max = -1;
  	for(int j=0;j<size;j++){
  		if(arr[j][1]>=proc[i][0]&& arr[j][2]==0){
  		    proc[i][1]=1;
  			if(max == -1 || arr[max][1]<arr[j][1]){
  				max=j;
  			}
  		}
  	}
  	if(proc[i][1]==0 || arr[max][1]<proc[i][0]){
  		printf("Process P%d cannot be allocated \n",i+1);
  	}
  	else{
  		printf("Process %d allocated in memory of size %d with internal fragmentation as %d \n",i+1, arr[max][1],arr[max][1]-proc[i][0]);
  			arr[max][0]=proc[i][0];
  			arr[max][2]=1;
  	}	
  }
  printf("The memory alocation of various processes ofthe size are as shown: \n");
  for(int k=0;k<size;k++){
  	if(arr[k][0]!=0)
  		printf("\t %d \t",arr[k][0]);
  }
}


void main(){
  int size, number;
  printf("Enter the total number of memory blocks: ");
  scanf("%d",&size);
  int arr[size][3];
  printf("Enter the size of each block: \n");
  for(int i=0;i<size;i++){
  	printf("For block %d : ",i+1);
  	scanf("%d",&arr[i][1]);
  	arr[i][2]=0;
  	arr[i][0]=0;
  }
  printf("Number of processes to be allocated with memory:  ");
  scanf("%d",&number);
  int proc[number][2];
  printf("Enter the size of each process: \n");
  for(int i=0;i<number;i++){
  	printf("For process P%d : ",i+1);
  	scanf("%d",&proc[i][0]);
  	proc[i][1]=0;
  }
  printf("\n FIRST FIT MEMORY ALLOCATION STRATEGY: \n");
  firstfit(arr, proc, size, number);
  initializeZero(arr, proc, size, number);
  printf("\n BEST FIT MEMORY ALLOCATION STRATEGY: \n");
  bestfit(arr, proc, size, number);
  initializeZero(arr, proc, size, number);
  printf("\n WORST FIT MEMORY ALLOCATION STRATEGY: \n");
  worstfit(arr, proc, size, number);

}
