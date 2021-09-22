#include <stdio.h>
#include <stdlib.h>

struct rr{
 int at;
 int bt;
 int pno;
 int tat;
 int wt;
 int remain;
};
struct rr *s1;

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
        struct rr temp= s1[min];
        s1[min]=s1[i];
        s1[i]=temp;
       
      }
  } 
} 



void roundrobin(int num,float q){
	int i,j,count=0;
	printf("Round Robin sorted chart on the basis of AT is given. \n");
	printf("Process | AT \t | BT \t");
	printf("\n");
	for(i=0;i<num;i++){
		printf("%d \t | %d \t | %d",s1[i].pno,s1[i].at,s1[i].bt);
		printf("\n");
	}
	
	for(i=0;i<num;i++){
		s1[i].remain=s1[i].bt;
	}
	
	count=0;
	printf("\n");
	printf("Gantt chart is \n");
	for(i=0;count!=num;i=(i+1)%num){
		if(s1[i].remain!=0){
			printf("%d \t",s1[i].pno);
			if(q<s1[i].remain){
				s1[i].remain-=q;
			}
			else{
				s1[i].remain=0;
				count++;
				if(count==num)
				    break;
			}
		}
	}
	
	for(i=0;i<num;i++)
		s1[i].remain=s1[i].bt;
	
	float total_time=0,avg_wt=0,avg_tat=0;
	
	//calculations
	for(i=0,count=0;count!=num;i=(i+1)%num){
		if(s1[i].remain<=q){
			if(total_time<s1[i].at){
				total_time=s1[i].at;
			}
			total_time+=s1[i].remain;
			s1[i].tat=total_time-s1[i].at;
			s1[i].wt=s1[i].tat-s1[i].bt;
			s1[i].remain=0;
			count++;
		}
		else{
			if(total_time<s1[i].at){
				total_time=s1[i].at;
			}
			total_time+=q;
			s1[i].remain-=q;
		}
	}
	//for calculating the average waiting time and turn around time
	for(i=0;i<num;i++){
		avg_wt+=s1[i].wt;
		avg_tat+=s1[i].tat;
	}
	printf("\n");
	printf("Average waiting time: %.2f ms\n",avg_wt/num);
	printf("Average turn around time: %.2f ms \n",avg_tat/num);
	
}


void main(){
 static int total = 0;
 int num;
 float slice;
 
 printf("Enter the total number of process: ");
 scanf("%d",&num);
 
 s1 = (struct rr*)malloc(num * sizeof(struct rr));
 printf("What is the timeslice of processes");
    scanf("%f",&slice);
 //asking for arrival time and burst time
 for(int i=0 ; i<num ; i++)
 {
    s1[i].pno = i+1;
    printf("What is the arrival time of process %d: ",i+1);
    scanf("%d",&s1[i].at);
    printf("What is the burst time of process %d: ",i+1);
    scanf("%d",&s1[i].bt);
 }
 
 selectionSort(num); //sort by arrival time
 roundrobin(num,slice);
 }
