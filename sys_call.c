#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void main(){
	int a,b,c;
	int d,e,f;
	int g,h,i;
	printf("A is the parent of all processes: %d\n", getpid());
	b=fork();
	if(b==0){
	//child of b
		d=fork();
		if(d==0){
			printf("Process D with id: %d and parent B of id: %d \n", getpid(), getppid());
			h=fork();
			if(h==0){
				printf("Process H with id: %d and parent D of id: %d \n", getpid(), getppid());
				i=fork();
				if(i==0){
					printf("Process I with id: %d and parent H of id: %d \n", getpid(), getppid());	
				}
				else{
					wait(NULL);
				}
			}
			else{
				wait(NULL);
		}
		}
		else{
			printf("Process B with id: %d and parent A of id: %d \n", getpid(), getppid());
			//child of B
			e=fork();
			if(e==0){
				printf("Process E with id: %d and parent B of id: %d \n", getpid(), getppid());	
			}
			else{
				f=fork();
				if(f==0){
					printf("Process F with id: %d and parent B of id: %d \n", getpid(), getppid());	
				}
				else{
					wait(NULL);
				}
			}
		}
	}
	else{
		c=fork();
		if(c==0){
			printf("Process C with id: %d and parent A of id: %d \n", getpid(), getppid());
			g=fork();
			if(g==0){
				printf("Process G with id: %d and parent C of id: %d \n", getpid(), getppid());	
			}
			else{
				wait(NULL);	
			}
		} else {
			wait(NULL);
		}
	}
}
