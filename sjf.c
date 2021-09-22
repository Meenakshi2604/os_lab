#include <stdio.h>
#include <stdlib.h>

struct sjf{
 int at;
 int bt;
 int pno;
 int tat;
 int wt;
};
struct sjf *s1;

void display(int);

void selectionSort(int n) 
{ 
  int i, j;
  struct sjf temp;
  for (i = 1; i < n; i++) 
  { 
    temp=s1[i]; 
    for (j = i-1; j >= n; j--) {
       if (temp.at >s1[j].at) {
         s1[j+1]=s1[j];
        }
        else 
        	break;
     }
     s1[j+1]=temp;
  } 
  display(n);
} 


void selectBt(int num){		//sort on the basis on burst time with same arrival time
   int i,j;
   for(i=0;i<num;i++){
    	for(j=i+1;j<num;j++){
    		if(s1[i].at!=s1[j].at){
    			break;
    		}
    		else if((s1[i].at==s1[j].at)&&(s1[i].bt>s1[j].bt)){
    			struct sjf temp = s1[i];
    			s1[i]=s1[j];
    			s1[j]=temp;
    		}
    	}
    	
   }
}

void sortAll(int num){		//sort when the burst time is less but arrival time is more
				//sort on the basic of process that have less burst time but more arrival time
   int total=0;
   for(int i=1;i<num;i++){
   	if(total<s1[i-1].at)
   		total=s1[i-1].at;
   	total+=s1[i-1].bt;
   	for(int j=i+1;j<num;j++){
   		if(total>=s1[i].at){
   			if(s1[j].bt<s1[i].bt){
   				struct sjf temp= s1[i];
   				s1[i]=s1[j];
   				s1[j]=temp;
   			}
   			else if((s1[j].bt==s1[i].bt)&&(s1[i].pno>s1[j].pno)){
   				struct sjf temp= s1[i];
   				s1[i]=s1[j];
   				s1[j]=temp;
   			}
   		}
   		else
   			break;
   	}
   }

}

void display(int num){
	printf("Process | AT \t | BT");
	printf("\n");
	for(int i=0;i<num;i++){
		printf("%d \t | %d \t | %d",s1[i].pno,s1[i].at,s1[i].bt);
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


void main(){
 static int total = 0;
 int num;
 
 printf("Enter the total number of process: ");
 scanf("%d",&num);
 
 s1 = (struct sjf*)malloc(num * sizeof(struct sjf));
 //asking for arrival time and burst time
 for(int i=0 ; i<num ; i++)
 {
    s1[i].pno = i+1;
    printf("What is the arrival time of process %d: ",i+1);
    scanf("%d",&s1[i].at);
    printf("What is the burst time of process %d: ",i+1);
    scanf("%d",&s1[i].bt);
 }
 
 for(int i=0;i<num;i++){
 	printf("%d \t %d \t %d",s1[i].pno,s1[i].at,s1[i].bt);
 	printf("\n");
 }
 selectionSort(num); //sort on the basis of arrival time
 selectBt(num);      //sort on the basis on burst time with same arrival time
 sortAll(num);		//sort when the burst time is less but arrival time is more
 display(num);
 
}


