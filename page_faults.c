#include <stdio.h>
#include <stdlib.h>

void fifo(int pages,int frame_size,int *referenceStr, int *frame){
	int i,j, page_faults = 0, flag, *frames; 
	frames = (int*)malloc(frame_size*sizeof(int));
	for(i=0;i<frame_size;i++){
		frames[i] = frame[i];
	}
	for(i = 0; i< pages; i++)
      	{
            flag = 0;
            for(j = 0; j < frame_size; j++)
            {
                  if(referenceStr[i] == frames[j])
                  {
                        flag++;
                        page_faults--;
                  }
            }     
            page_faults++;
            if((page_faults <= frame_size) && (flag == 0))
            {
                  frames[i] = referenceStr[i];
            }   
            else if(flag == 0)
            {
                  frames[(page_faults - 1) % frame_size] = referenceStr[i];
            }
            printf("\n");
            for(j = 0; j < frame_size; j++)
            {     
                  printf("%d\t", frames[j]);
            }
      } 
      printf("\nTotal Page Faults:\t%d\n", page_faults);
}
int searchLRU(int *time, int frame_size){
	int min=time[0], pos = 0, i;
 	for(i=0;i<frame_size;i++){
 		if(min > time[i]){
 			min = time[i];
 			pos = i;
 		}
 	}
 return pos;
}
 
void lru(int pages, int frame_size, int *frame, int *referenceStr){
	int flag1,flag2,i,j, pos =0, counter =0, page_faults=0, *time, *frames;
	frames = (int*)malloc(frame_size*sizeof(int));
	for(i=0;i<frame_size;i++){
		frames[i] = frame[i];
	}
time = (int*)malloc(frame_size*sizeof(int));
for(i=0;i<pages;i++){
	flag1=0;
	flag2=0;
for(j=0;j<frame_size;j++){
//checking whether the frame already has that page
if(frames[j] == referenceStr[i]){
	flag1=1;
	flag2=1;
	counter++;
	time[j]=counter;
	break;
}
}
if(flag1 == 0){
	for(j=0;j<frame_size;j++){
		//checking whether frame is completely filled or not
		if(frames[j] == -1){
				frames[j]=referenceStr[i];
				counter++;
				page_faults++;
				time[j]=counter;
				flag2=1;
				break;					
			}
		}
	}
	//the page is not present in the frame
	if(flag2==0){
		pos = searchLRU(time, frame_size);
		frames[pos] = referenceStr[i];
		counter++;
		page_faults++;
		time[pos] = counter;
		break;
	}
	printf("\n");
            for(j = 0; j < frame_size; j++)
            {     
                  printf("%d\t", frames[j]);
            }
	}
	printf("\nTotal Page Faults:\t%d\n", page_faults);
}

void main()
{
      int *referenceStr, *frames, i, j, s, pages, frame_size, option;
      printf("\nEnter the number of Pages: ");
      scanf("%d", &pages);
      referenceStr = (int*)malloc(pages*sizeof(int*));
      printf("\nEnter reference string values: ");
      for(i = 0; i < pages; i++)
      {
            scanf("%d", &referenceStr[i]);
      }
      printf("\n What are the total number of frames: ");
      {
            scanf("%d", &frame_size);
      }
      frames = (int*)malloc(frame_size*sizeof(int));
      for(i= 0; i< frame_size; i++)
      {
            frames[i] = -1;
      }
      choose: printf("Which page replacement algorithm to be implemented? \n 1. FIFO \n 2. LRU \n 3. LFU \n \n 4. Exit \n");
      printf("Choose an option: ");
      scanf("%d", &option);
      switch(option){
      				case 1:  fifo(pages,frame_size, referenceStr, frames);
      					goto choose;
      				case 2: lru(pages, frame_size, frames,referenceStr);
      					goto choose;
      				case 3: printf("Not yet implemented \n");
      					goto choose;
      				case 4: printf("Exiting the program \n");
      					exit(0);
      				default: printf("Incorrect option");
      					goto choose;
      }    
}
