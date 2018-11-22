#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file;
    char line[255];
    int choice,choice_1;
    int counter = 0;
    int del_counter = 0;
    int srch_counter = 0;

    int costumer_age[100];
    int costumer_contactNumber[100];
    int costumer_ammountBorrow[100];
    int costumer_no[100];

    char costumer_fname[100][100];
    char costumer_lname[100][100];
    char costumer_address[100][100];
    char costumer_TOP[100][100];

    char del_costumer[1][100];
    char srch_costumer[1][100];
    char file_path [500];

    strcpy(file_path,getenv("USERPROFILE")) ;
    strcat(file_path,"\\Desktop\\JJFQ Lending Company Costumer's Record.txt");

    menu:
    printf("***** JFQ Lending Company Costumer's Record *****\n");
    printf("1 - Add Costumer\n2 - Delete Costumer\n3 - Search Customer\n4 - Display All\n5 - Save File\n6 - Load File\n7 - Exit\nEnter your choice: ");

    scanf("%d", &choice);

    switch(choice){
        case 1:
            add_costu:
            system("cls");
            printf("***** ADD COSTUMER *****");
            printf("\nCostumer First Name: ");
            scanf("%s", &costumer_fname[counter]);
            printf("\nCostumer Family Name: ");
            scanf("%s", &costumer_lname[counter]);
            printf("\nCostumer Age: ");
            scanf("%d", &costumer_age[counter]);
            printf("\nCostumer Address: ");
            scanf("%s", &costumer_address[counter]);
            printf("\nCostumer Contact Number: ");
            scanf("%d", &costumer_contactNumber[counter]);
            printf("\nCostumer Amount Borrowed: ");
            scanf("%d", &costumer_ammountBorrow[counter]);
            printf("\nCostumer Terms of Payment [ Monthly, Quarterly, Semi-Annual, or Annual ]: ");
            scanf("%s", &costumer_TOP[counter]);

            add_costu_sel:
            printf("\nAdd?\n1 - Yes\t2 - No\nAnswer: ");
            scanf("%d", &choice_1);
            if(choice_1 == 1){
                // Assigning Unique Number from 0 to 1 000 000 000
                costumer_no[counter] = rand() % 1000000000;
                for(int x = 0; x < counter;x++){
                    // Identifying either the number is already taken or not
                    if(costumer_no[x] == costumer_no[counter]){
                        // Generate other random number and restart the process
                        costumer_no[counter] = rand() % 1000000000;
                        x = 0;
                    }
                }
                counter++;
                system("cls");
                printf("\n*** SUCCESSFULLY ADDED ***\n\n");
                goto menu;
            }else if(choice_1 == 2){
                goto add_costu;
            }else{
                printf("\n!!! Invalid Selection !!!\n");
                goto add_costu_sel;
            }
            break;
        case 2:
            del_costumer:
            system("cls");
            printf("***** DELETE COSTUMER *****");
            printf("\nEnter the costumer name: ");
            scanf("%s", &del_costumer);

            for(int x = 0;x < counter; x++){
                if(strcmp(costumer_fname[x],del_costumer) == 0){
                    goto fetch;
                    break;
                }
                del_counter++;
            }
            printf("\n\nName not found!\n");
            printf("Try again?\n1 - Yes\t2 - No\nAnswer: ");
            scanf("%d",&choice);
            if(choice == 1){
                goto del_costumer;
            }else{
                system("cls");
                goto menu;
            }
            fetch:
                printf("\n***** Costumer Data *****");
                printf("\nNo: %d",costumer_no[del_counter]);
                printf("\nName: %s %s",costumer_fname[del_counter],costumer_lname[del_counter]);
                printf("\nAge: %d",costumer_age[del_counter]);
                printf("\nAddress: %s",costumer_address[del_counter]);
                printf("\nContact Number: %d",costumer_contactNumber[del_counter]);
                printf("\nAmount Borrowed: %d", costumer_ammountBorrow[del_counter]);
                printf("\nTerms of Payment: %s", costumer_TOP[del_counter]);

                printf("\n\nDELETE?\n1 - Yes\t2 - No\nAnswer: ");
                scanf("%d", &choice_1);
                if(choice_1 == 1){
                    counter--;
                    system("cls");
                    printf("\n*** SUCCESSFULLY DELETED ***\n\n");
                    goto menu;
                }
            break;
        case 3:
            srch_costumer:
            system("cls");
            printf("***** DELETE COSTUMER *****");
            printf("\nEnter the costumer name: ");
            scanf("%s", &srch_costumer);

            for(int x = 0;x < counter; x++){
                if(strcmp(costumer_fname[x],srch_costumer) == 0){
                    goto src_fetch;
                    break;
                }
                srch_counter++;
            }
            printf("\n\nName not found!\n");
            printf("Try again?\n1 - Yes\t2 - No\nAnswer: ");
            scanf("%d",&choice);
            if(choice == 1){
                goto srch_costumer;
            }else{
                system("cls");
                goto menu;
            }
            src_fetch:
                printf("\n***** Costumer Data *****");
                printf("\nNo: %d",costumer_no[srch_counter]);
                printf("\nName: %s %s",costumer_fname[srch_counter],costumer_lname[srch_counter]);
                printf("\nAge: %d",costumer_age[srch_counter]);
                printf("\nAddress: %s",costumer_address[srch_counter]);
                printf("\nContact Number: %d",costumer_contactNumber[srch_counter]);
                printf("\nAmount Borrowed: %d", costumer_ammountBorrow[srch_counter]);
                printf("\nTerms of Payment: %s", costumer_TOP[srch_counter]);

                printf("\n\nSEARCH AGAIN?\n1 - Yes\t2 - No\nAnswer: ");
                scanf("%d", &choice_1);
                if(choice_1 == 1){
                    system("cls");
                    goto srch_costumer;
                }else{
                    system("cls");
                    goto menu;
                }
            break;
        case 4:
            disp_list:
            system("cls");
            printf("No.\tFirst Name\tFamily Name\tAge\tAddress\t\tContact No.\tAmount Borrowed");
            for(int x = 0;x < counter;x++){
                printf("\n%d\t%s\t\t%s\t\t%d\t%s\t\t%d\t\t%d",costumer_no[x],costumer_fname[x],costumer_lname[x],costumer_age[x],costumer_address[x],costumer_contactNumber[x],costumer_ammountBorrow[x]);
            }
            printf("\n\nBack to Main Menu?\n1 - Yes\t2 - No\nAnswer: ");
            scanf("%d", &choice);
            if(choice == 1){
                system("cls");
                goto menu;
            }else{
                goto disp_list;
            }
            break;
        case 5:
            file = fopen(file_path, "w+");
            fprintf(file, "No.\tFirst Name\tFamily Name\tAge\tAddress\t\tContact No.\tAmount Borrowed");
            for(int x = 0; x < counter; x++){
                fprintf(file,"\n%d\t%s\t\t%s\t\t%d\t%s\t\t%d\t\t%d",costumer_no[x],costumer_fname[x],costumer_lname[x],costumer_age[x],costumer_address[x],costumer_contactNumber[x],costumer_ammountBorrow[x]);
            }
            fclose(file);
            system("cls");
            printf("\n*** SUCCESSFULLY SAVE ***\n\n");
            goto menu;
            break;
        case 6:
            system("cls");
            printf("Loading...");
            delay(3);
            load:
            system("cls");
            file = fopen(file_path, "r");
            while(fgets(line, 255, file) != NULL){
                printf("%s\n", line );
            }


            printf("\n\nBack to Menu?\n1 - Yes\t2 - No\nAnswer: ");
            scanf("%d", &choice);
            if(choice == 1){
                system("cls");
                goto menu;
            }else{
                goto load;
            }
            fclose(file);
            break;
        case 7:
            return 0;
            break;
        default:
            printf("\n\n!!! Invalid Selection !!!\n\n");
            goto menu;
    }
    return 0;
}

void delay(int sec){
    int c,d;
    sec = sec * 10000;
    for(c = 1;c <= sec; c++){
        for(d = 1; d <= sec; d++){

        }
    }

}
