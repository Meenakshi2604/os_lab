#include <stdio.h>
#include <stdlib.h>

struct frames {
	int num;
	int index;
};

struct pages {
	int num;
	int count;
};

void fifo(int frame_size, int number, int referenceStr[]) {
	struct frames *frame;
	int i,j, page_faults = 0, flag; 
	frame = (struct frames*)malloc(frame_size*sizeof(struct frames));
	for(i=0;i<frame_size;i++){
		frame[i].num = -1;
	}
	for(i = 0; i< number; i++)
      	{
            flag = 0;
            for(j = 0; j < frame_size; j++)
            {
                  if(referenceStr[i] == frame[j].num)
                  {
                        flag++;
                        page_faults--;
                  }
            }     
            page_faults++;
            if((page_faults <= frame_size) && (flag == 0))
            {
                  frame[i].num = referenceStr[i];
            }   
            else if(flag == 0)
            {
                  frame[(page_faults - 1) % frame_size].num = referenceStr[i];
            }
            printf("\n");
            for(j = 0; j < frame_size; j++)
            {     
                  printf("%d\t", frame[j].num);
            }
      } 
      printf("\nTotal Page Faults:\t%d\n", page_faults);
}

void lru(int frame_size, int number, int referenceStr[]) {
	struct frames frame[frame_size];
	int index = -1, free = 1, faults = 0, count = 0;
	for(int i=0;i<frame_size;i++){
		frame[i].num = -1;
	}
	for(int i = 0; i< number; i++){	
		int flag = 0;
		
		for (int j=0; j<frame_size; j++)
			//page is already present inside the frame
			if (frame[j].num == referenceStr[i]) {
				frame[j].index = count;
				count++;
				flag = 1;
			}
		//page is not present in the frame
		if (flag == 0) {
			//checking if frame has reached its capacity
			if (free) {
				index = (index + 1) % frame_size;
				
				if (index == (frame_size-1)) //when the frame is filled completely
					free = 0;
			}
			else {
				//finding the least index for LRU
				index = 0;
				for (int j=1; j<frame_size; j++)
					if (frame[j].index < frame[index].index)
						index = j;
			}
			
			frame[index].num = referenceStr[i];
			frame[index].index = count;
			count++;
			faults++;
		}
		printf("\n");
            for(int j = 0; j < frame_size; j++)
            {     
                  printf("%d\t", frame[j].num);
            }
	}
	printf("\nNo of page faults = %d\n", faults);
}

void lfu(int frame_size, int number, int referenceStr[]) {
	struct frames frame[frame_size];
	struct pages page[number];
	int index = -1, free = 1, faults = 0, count = 0, maplen = 0;
	for(int i=0;i<frame_size;i++){
		frame[i].num = -1;
	}
	for (int i=0; i<number; i++) {
		int flag = 0;
		for (int j=0; j<frame_size; j++)
			//checking whether the page is already present in the frame
			if (frame[j].num == referenceStr[i]) {
				for (int k=0; k<maplen; k++)
					if (page[k].num == frame[j].num) {
						page[k].count++; //increasing the frequency of that particular page
						break;
					}
				
				frame[j].index = count;
				count++;
				flag = 1;
			}
		
		if (flag == 0) {
			//checking whether frame has reached its capacity
			if (free) {
				index = (index + 1) % frame_size;
				
				if (index == (frame_size-1))
					free = 0;
			}
			else {
				index = 0;
				int index1 = 0, index2 = 0;
				
				for (int j=1; j<frame_size; j++) {
					for (int k=0; k<maplen; k++)
						if (page[k].num == frame[index].num) {
							index1 = k;
							continue;
						} else if (page[k].num == frame[j].num) {
							index2 = k;
							continue;
						}
					
					if (page[index2].count < page[index1].count) {
						index = j;
					} else if (page[index2].count == page[index1].count) {
						if (frame[j].index < frame[index].index)
							index = j;
					}
				}
			}
			
			frame[index].num = referenceStr[i];
			
			int present = 0;
			
			for (int k=0; k<maplen; k++)
				if (page[k].num == frame[index].num) {
					page[k].count++;
					present = 1;
					break;
				}
			
			if (present == 0) {
				page[maplen].num = referenceStr[i];
				page[maplen].count = 1;
				maplen++;
			}
							
			frame[index].index = count;
			count++;
			faults++;
		}
		printf("\n");
            for(int j = 0; j < frame_size; j++)
            {     
                  printf("%d\t", frame[j].num);
            }
		
	}
	
	printf("\nNo of page faults = %d\n", faults);
}

void main() {
	int frame_size, number, choice, *referenceStr;
	
	printf("Enter the frame size: ");
	scanf("%d", &frame_size);
	
	printf("Enter total number of pages: ");
	scanf("%d", &number);
	
	referenceStr = (int*)malloc(number*sizeof(int));
	
	printf("Enter the reference string:\n");
	for(int i=0; i<number; i++)
		scanf("%d", &referenceStr[i]);
		
		option: printf("\n1. FIFO\n2. LRU\n3. LFU\n4. Exit");
		printf("\nChoose option: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				fifo(frame_size, number, referenceStr);
				goto option;
			case 2:
				lru(frame_size, number, referenceStr);
				goto option;
			case 3:
				lfu(frame_size, number, referenceStr);
				goto option;
			case 4:
				printf("\nExit.\n");
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
}
