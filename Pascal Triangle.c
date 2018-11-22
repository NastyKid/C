#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,number_of_lines,y,number = 1;

    printf("Enter number of lines : ");
    scanf("%d",&number_of_lines);

    for(x = 0;x < number_of_lines;x++){
        // Lines generation
        for(y = 0;y <= x;y++){
            // Number generation
            if(y == x || y == 0){
                // Turn the 1st and last digit into 1
                number = 1;
            }else{
                number = number*(x-y+1)/y;
            }
            printf("%d",number);
        }

        printf("\n");
    }
    return 0;
}
