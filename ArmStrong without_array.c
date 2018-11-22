#include <stdio.h>


int main()
{
    int num,get_num, y = 10,sum = 0,total_digit = 0,get_org_num,x,multiplier,armstrong_num;
    char choice;
start:
    printf("Enter a number: ");
    scanf("%d", &num);
    get_org_num = num;
    armstrong_num = num;
    while(num != 0){
    // Identifying total digits inputted number by the user.
        get_num = num % y;
        num = num - get_num;
        y = y * 10;
        total_digit++;
    }

    y = 10;
    get_num = 0;

    while(get_org_num != 0){

        get_num = get_org_num % y;

        get_org_num = get_org_num - get_num;

        get_num = get_num/(y/10); // EXTRACTING INTO SINGLE DIGIT e.g( 40 / 10 = 4 or 100 / 100 = 1)

        y = y * 10;

        multiplier = get_num;

        for(x = 2; x <= total_digit ; x++){
                // Exponential
            get_num = get_num * multiplier;
        }

        sum = sum + get_num;
    }
    /** DETERMINING IF IT IS AN ARMSTRONG NUM or NOT **/
    if(armstrong_num == sum){
        printf("\n%d is an Armstrong number.", armstrong_num);
    }else{
        printf("\n%d is not an Armstrong number.", armstrong_num);
    }

    back:
    printf("\n\nEnter new number? [Y/N]");
    scanf("%s", &choice);

    if(choice == 'Y' || choice == 'y'){
        multiplier = 0;
        total_digit = 0;
        get_num = 0;
        get_org_num = 0;
        armstrong_num = 0;
        sum = 0;
        y = 10;
        goto start;
    }else if(choice == 'N' || choice == 'n'){
        goto end;
    }else{
        printf("\n\nIncorrect character inputted.\n\t'Y' = Yes\n\t'N' = No");
        goto back;
        }
end:
    return 0;
}
