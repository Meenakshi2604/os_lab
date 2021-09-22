#include<stdio.h>
#include <unistd.h>

void fibonacci(int n){    
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         fibonacci(n-1);    
    } 
}

void primeRange(int n){
  int flag;
  for(int num = 2;num<=n;num++)
       {
         flag = 0;

         for(int i=2;i<=num/2;i++)
            {
             if(num%i==0){
                 flag++;
                 break;
             }
        }
        
         if(flag==0)
             printf("%d ",num);
    }
printf("\n");  

} 

   
void main(){
  int n;
  printf("Enter the value of N: ");
  scanf("%d",&n);
  if (fork() == 0){
	printf("Fibonacci Series upto %d terms: ", n);    
    	printf("%d %d ",0,1);    
    	fibonacci(n-2);
    	printf("\n");
  }
  else{
  	primeRange(n);
  }

}
