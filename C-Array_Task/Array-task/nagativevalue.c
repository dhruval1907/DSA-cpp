    // find the all the nagative values in this array
    
    #include<stdio.h>
    
    int main(){
        
        int n,i;
        
        int num[] = {10,-10,20,-20,-30,-40,40,-50,50,-60};   
        
        for(i=0;i<10;i++){
            if(num[i]<0){
                n = num[i];
                printf(" %d,",n);
            }
            
        }
    
    }
