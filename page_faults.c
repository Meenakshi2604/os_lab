#include<stdio.h>
#include<stdlib.h>

void main(){
  int frame_size, n, page_faults=0, i, j, front=-1,rear=-1;
  int *ref_str, *frame;
  printf("Enter the frame size: ");
  scanf("%d",&frame_size);
  frame = (int*)malloc(frame_size*sizeof(int));
  printf("Enter the total number of pages: ");
  scanf("%d",&n);
  ref_str = (int*)malloc(n*sizeof(int));
  printf("Enter the page numbers one by one: \n");
  for(i=0;i<n;i++){
  	scanf("%d",&ref_str[i]);
  }
  for(j=0;j<frame_size;j++){
  	frame[i]= -1;
  }
   //traversing from frame
   for(i=0;i<n;i++){
   	//when the frame is not yet filled
   	if(front== -1){
   		front=0;
   		rear=0;
   		frame[rear]=ref_str[i];
   		page_faults++;
   	}
   	else if(rear < frame_size-1 && frame[rear]== -1){
   		rear= (rear+1)% frame_size;
   		frame[rear]=ref_str[i];
   		page_faults++;
   	}
   	
   	//when the frame is full but page is already present 
   	else{
	   	for(j=0;j<frame_size;j++){
	   		if(frame[j]==ref_str[i]){
	   			break;
	   		}
	   		else{
	   			frame[front]=ref_str[i];
	   			front=(front+1)% frame_size;
	   			page_faults++;
	   		}
	   	}
   	}
   }
   
   printf("\n Page faults= %d \n", page_faults);
}
