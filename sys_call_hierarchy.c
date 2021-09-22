#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h> 

void main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		if(fork()==0){
			printf("Level: %d , Child of id: %d is created out of the Parent of id: %d \n",i+1, getpid(),getppid());
		}
		else if(fork()==0){
			printf("Level: %d , Child of id: %d is created out of the Parent of id: %d \n",i+1, getpid(),getppid());
		}
		else{
			wait(NULL);
			i=n;
		}
	}

}
