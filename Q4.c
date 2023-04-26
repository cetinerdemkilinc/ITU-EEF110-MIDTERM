#include <stdio.h>

char commands[6][3] = {"abc", "cba", "def", "ghi", "jkl", "xyz"};
char buffer[3] = {0,0,0};
int comStatus = 0;

int isEqual(char *str1, char *str2){
    for(int i=0; i<3; i++){
        if(str1[i] != str2[i]) 
            return 0;
    }
    return 1;
}

int main(){

    while(1){
        do{
            buffer[0] = buffer[1];
            buffer[1] = buffer[2];
            scanf("%c", buffer+2);
        }while(buffer[0] == 0);
        
        if(isEqual(buffer, commands[0]) && comStatus == 0){
            printf("Started\n");
            comStatus = 1;
        }
        else if(isEqual(buffer, commands[1]) && comStatus == 1){
            printf("Ended\n");
            comStatus = 0;
        }
        else if(isEqual(buffer, commands[2]) && comStatus == 1) printf("Task 1\n");
        else if(isEqual(buffer, commands[3]) && comStatus == 1) printf("Task 2\n");
        else if(isEqual(buffer, commands[4]) && comStatus == 1) printf("Task 3\n");
        else if(isEqual(buffer, commands[5])){
            printf("Quitting\n");
            return 0;
        }

    }

    return 0;
}