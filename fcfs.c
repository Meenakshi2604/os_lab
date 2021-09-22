#include <stdio.h>
#include <stdlib.h>
# define max 25
int queue[max],front=-1,rear=-1;
static int total=0;
void enqueue(int key)
{
	if(rear==max-1)
	{
		printf("Overflow");
	}
	else
	{
		rear++;
		queue[rear]=key;
	}
}

  
void selectionSort(int arr[], int n) 
{ 
    int i, j, min,temp; 

    for (i = 0; i < n-1; i++) 
    { 
        min = i; 
        for (j = i+1; j < n; j++) {
          if (arr[j] < arr[min]) {
            min = j; 
           }
         }
         
         if(min!=i){
         	temp = arr[i];
         	arr[i] = arr[min];
         	arr[min] = temp;
         }
    } 
} 
void process_queue(int queue[],int ct[],int bt[],int at[],int size){
	for(int i=0;i<size;i++){
		int j = queue[i];
		if((i==0 && at[j-1]!=0)||(i!=0 && at[j-1]>total)){
			printf("\ninvalid input given!!\n");
			exit(0);
		}

		ct[j-1]=total+bt[j-1];
		total=ct[j-1];
	}
}
int search_queue(int value,int size){
	if(size==0)
		return size;
	for(int i=0;i<size;i++)
		if(value==queue[i] && queue[i]!=0)
			return 1;
	return 0;
}
void main(){
	int k,count=0;
	int n,prev;
	int *process;	//process id
	int *wait;	//waiting time
	int *bt;	//burst time
	int *arrival;	//arrival time
	int *arrival_dummy;	
	int *completion;	//completion time
	int *tat;	//turn around time
	int totaltat=0,totalwt=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	
	process = (int*)malloc(n * sizeof(int));  
	wait = (int*)malloc(n * sizeof(int));		
	bt = (int*)malloc(n * sizeof(int));		
	arrival = (int*)malloc(n * sizeof(int));		
	arrival_dummy = (int*)malloc(n * sizeof(int));	
	completion = (int*)malloc(n * sizeof(int));	
	tat = (int*)malloc(n * sizeof(int));	


	for(int i=0;i<n;i++){
		process[i]=i+1;
		printf("Enter the arrival time for the process %d:",i+1);
		scanf("%d",&arrival[i]);
		arrival_dummy[i]=arrival[i];
		printf("Enter the burst time for the process %d:",i+1);
		scanf("%d",&bt[i]);
	}
	selectionSort(arrival_dummy,n);	
	k=0;
	
	//gangtt chart
	while(k<n){
	for(int i=0;i<n;i++){
		if(arrival[i]==arrival_dummy[k]){
			if(!search_queue(process[i],n)){ //to avoid same process to be enqueued again
				enqueue(process[i]);
				k++;						
			}
			else{
				printf("Value is already there:%d\n",process[i]);				
				if(++count>max){
					k=n-1;  //getting out of loop
					break;
				}
			}
		}
	}
	
}
	//displaying gangtt chart
	for(int i=0;i<n;i++){
		printf("%d\t",queue[i]);
	}
	
	process_queue(queue,completion,bt,arrival,n);
	printf("\n");
	for(int i=0;i<n;i++){
		tat[i]=completion[i]-arrival[i];
		wait[i]=tat[i]-bt[i];
		printf("Waiting time : %d and turnaround time :%d of process %d\n",wait[i],tat[i],i+1);
		totaltat+=tat[i];
		totalwt+=wait[i];
	}
	//avg waiting and turnaround time
	printf("\n");
	printf("avg waiting time:%.2f",(float)totalwt/n);
	printf("\n");
	printf("avg turnaround time:%.2f\n",(float)totaltat/n);

}
