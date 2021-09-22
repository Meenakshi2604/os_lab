#include <stdio.h>
#include <stdlib.h>

struct priority{
 int at;
 int bt;
 int pno;
 int tat;
 int wt;
 int priority;
};
struct priority *s1;

void selectionSort(int n) 
{ 
  int i, j, min; 

  for (i = 0; i < n; i++) 
  { 
    min = i; 
    for (j = i+1; j < n; j++) {
       if (s1[min].at >s1[j].at) {
         min = j; 
        }
     }
         
     if(min!=i){
        struct priority temp= s1[min];
        s1[min]=s1[i];
        s1[i]=temp;
       
      }
  } 
} 

void sortByPriority(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(s1[i].at!=s1[j].at){
				break;
			}
			else if(s1[i].at==s1[i].at && s1[i].priority>s1[j].priority){
				struct priority temp=s1[i];
				s1[i]=s1[j];
				s1[j]=temp;
			}		
		}
	}
}



void display(int num){
	printf("Process | AT \t | BT \t | Priority");
	printf("\n");
	for(int i=0;i<num;i++){
		printf("%d \t | %d \t | %d \t | %d",s1[i].pno,s1[i].at,s1[i].bt,s1[i].priority);
		printf("\n");
	}
	printf("Gantt chart is \n");
	for(int i=0;i<num;i++){
		printf("%d\t",s1[i].pno);
	}
	
	float total_time=0,avg_wt=0,avg_tat=0;
	
	for(int i=0;i<num;i++){
		if(total_time<s1[i].at){
			total_time=s1[i].at;
		}
		total_time+=s1[i].bt;
		s1[i].tat=total_time-s1[i].at;
		s1[i].wt=s1[i].tat-s1[i].bt;
	}
	//for calculating the average waiting time and turn arounf time
	for(int i=0;i<num;i++){
		avg_wt+=s1[i].wt;
		avg_tat+=s1[i].tat;
	}
	printf("Average waiting time: %.2f ms\n",avg_wt/num);
	printf("Average turn around time: %.2f ms \n",avg_tat/num);
	
}

void priority(int n){
	int i,j,total=0;
	//processes with higher priority coming later
	for(i=1;i<n;i++){
		if(total<s1[i-1].at)
			total=s1[i-1].at;
		total+=s1[i-1].bt;
		for(j=i+1;j<n;j++){
			if(total>=s1[j].at){
				if(s1[j].priority < s1[i].priority){
					struct priority temp = s1[i];
					s1[i] = s1[j];
					s1[j] = temp;
				}
				else if (s1[j].priority == s1[i].priority && s1[i].pno > s1[j].pno) {
					struct priority temp = s1[i];
					s1[i] = s1[j];
					s1[j] = temp;
				}
			}
			else
				break;
			}
		}	
	}

void main(){
 static int total = 0;
 int num;
 
 printf("Enter the total number of process: ");
 scanf("%d",&num);
 
 s1 = (struct priority*)malloc(num * sizeof(struct priority));
 //asking for arrival time and burst time
 for(int i=0 ; i<num ; i++)
 {
    s1[i].pno = i+1;
    printf("What is the arrival time of process %d: ",i+1);
    scanf("%d",&s1[i].at);
    printf("What is the burst time of process %d: ",i+1);
    scanf("%d",&s1[i].bt);
    printf("What is the priority of process %d: ",i+1);
    scanf("%d",&s1[i].priority);
 }
 
 selectionSort(num);
 sortByPriority(num);
 priority(num);
 display(num);
 }
