#include <stdio.h>
#include <string.h>

int main()
{
    char name_of_the_day[50],choice;
    int num_days,day_identifier,days_n_week,x,one_week;
start:
    // RESET
    days_n_week = 7;
back:
    printf("First day of the month? ");
    scanf("%s", &name_of_the_day);

    /** strcmp - is use to compare two strings.. it returns 0 if true and 1 if false **/
    if(strcmp(name_of_the_day,"Sunday") == 0 || strcmp(name_of_the_day,"sunday") == 0){
        day_identifier = 0;
    }else if(strcmp(name_of_the_day,"Monday" ) == 0 || strcmp(name_of_the_day,"monday") == 0){
        day_identifier = 1;
    }else if(strcmp(name_of_the_day,"Tuesday") == 0 || strcmp(name_of_the_day,"tuesday") == 0){
        day_identifier = 2;
    }else if(strcmp(name_of_the_day,"Wednesday") == 0 || strcmp(name_of_the_day,"wednesday") == 0){
        day_identifier = 3;
    }else if(strcmp(name_of_the_day,"Thursday") == 0 || strcmp(name_of_the_day,"thursday") == 0){
        day_identifier = 4;
    }else if(strcmp(name_of_the_day,"Friday") == 0 || strcmp(name_of_the_day,"friday") == 0){
        day_identifier = 5;
    }else if(strcmp(name_of_the_day,"Saturday") == 0 || strcmp(name_of_the_day,"saturday") == 0){
        day_identifier = 6;
    }else{
        printf("\nERROR! Incorrect spelling\n\n");
        goto back;
    }

    printf("How many days in the month? ");
    scanf("%d", &num_days);

    printf("\n\nSun.\tMon.\tTue.\tWed.\tThurs.\tFri.\tSat.\n");

    for(int i = 0; i <= 53 ; i++){
        printf("-");
    }

    printf("\n");

    if( num_days <= days_n_week){
        days_n_week = days_n_week - day_identifier;
        for(int d = 1; d <= day_identifier; d++){
            // variable "day_identifier" is the identifier where the number of the day start.
            printf("\t");
        }
        for(int y = 1; y <= num_days; y++){
            printf("%d\t",y);
            one_week = y;
        }
        printf("\n");
        one_week = one_week + 1;
        for( one_week; one_week <= num_days ; one_week++,x++){
            if(x == 7){
                printf("\n");
                x = 0;
            }
                printf("%d\t",one_week);
            }
    }else{

        days_n_week = days_n_week - day_identifier;
        for(int d = 1; d <= day_identifier; d++){
            // variable "day_identifier" is the identifier where the number of the day start.
            printf("\t");
        }

        for(int y = 1; y <= days_n_week; y++){
        // First week of the month.
            printf("%d\t",y);
            one_week = y;
        }
        printf("\n");
        one_week = one_week + 1;
        for( one_week,x = 0; one_week <= num_days ; one_week++,x++){

            if(x == 7){
                printf("\n");
                x = 0;
            }
            printf("%d\t",one_week);
        }
        }


    printf("\n\nAnother Calendar? [Y/N] ");
    scanf("%s", &choice);
    printf("\n\n\n");

    if(choice == 'Y' || choice == 'y'){
        goto start;
    }else{
        return 0;
    }

}
