#include <stdio.h>

int main (){
    int choice, end = 0;
    while(end == 0){
        printf("Enter 1 for an insult, 2 for a compliment, 3 for a fact, 4 for a greeting, and 5 for a farewell: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1: printf("You are ugly.\n");
            end = 1;
            break;
            case 2: printf("You are beautiful.\n");
            end = 1;
            break;
            case 3: printf("A is the first letter of the alphabet.\n");
            end = 1;
            break;
            case 4: printf("Hello!\n");
            end = 1;
            break;
            case 5: printf("Goodbye!\n");
            end = 1;
            break;
            default: printf("Invalid input. ");
     }
    }
    return 0;
}