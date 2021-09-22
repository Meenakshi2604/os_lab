#include <stdio.h>
#include <stdlib.h>
int main()
{
      int *referenceString, pageFaults = 0, i, j, s, pages, frames;
      printf("\nEnter the number of Pages:\t");
      scanf("%d", &pages);
      referenceString = (int*)malloc(pages*sizeof(int*));
      printf("\nEnter reference string values:\n");
      int(i = 0; i < pages; i++)
      {
            scanf("%d", &referenceString[i]);
      }
      printf("\n What are the total number of frames:\t");
      {
            scanf("%d", &frames);
      }
      int temp[frames];
      for(i= 0; i< frames; i++)
      {
            temp[i] = -1;
      }
      for(i = 0; i< pages; i++)
      {
            s = 0;
            for(j = 0; j < frames; j++)
            {
                  if(referenceString[i] == temp[j])
                  {
                        s++;
                        pageFaults--;
                  }
            }     
            pageFaults++;
            if((pageFaults <= frames) && (s == 0))
            {
                  temp[i] = referenceString[i];
            }   
            else if(s == 0)
            {
                  temp[(pageFaults - 1) % frames] = referenceString[i];
            }
            printf("\n");
            for(j = 0; j < frames; j++)
            {     
                  printf("%d\t", temp[j]);
            }
      } 
      printf("\nTotal Page Faults:\t%d\n", pageFaults);
      return 0;
}

