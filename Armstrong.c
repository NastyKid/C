#include <stdio.h>
int main()
{
    int num, store[10],x = 0,y = 10, sum = 0,get,org_num;
    char choice;
start:
    printf("Enter a number: ");
    scanf("%d", &num);
    org_num = num;
    while(num != 0){
        store[x] = num % y;
        num = num - store[x];
        store[x] = store[x]/(y/10);
        y = y * 10;
        x++;
    }
    x = x - 1;
    for(int d = 0; d <= x; d++){
        get = store[d];
        for( int c = 0; c <= x-1; c++){
            store[d] = store[d] * get;
        }
        sum = sum + store[d];
    }
    if(org_num == sum){
        printf("\n%d is an Armstrong number.", sum);
    }else{
        printf("\n%d is not an Armstrong number.", sum);
    }
back:
    printf("\n\nEnter new number? [Y/N]");
    scanf("%s", &choice);

    if(choice == 'Y' || choice == 'y'){
        system("cls");
        x = 0;
        num = 0;
        y = 10;
        sum = 0;
        get = 0;
        org_num = 0;
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
