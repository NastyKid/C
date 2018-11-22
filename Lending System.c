#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    // Variable Declaration
    int amount,periods,tor,tor_lim,x,y;
    double monthly_rate,interest_rate,principal_amount = 0,interest_amount = 0,remaining_balance,total_payment = 0;
    char repeat,rep;
    // Intro
intro:
    system("cls");
    printf("\t\t **********************************\n");
    printf("\t\t *                                *\n");
    printf("\t\t * Welcome to JFQ Lending Company *\n");
    printf("\t\t *                                *\n");
    printf("\t\t **********************************\n");

    printf("*************************** Amount Matrix *******************************\n");
    printf("*       Amount        **                    Interest                   **\n");
    printf("*     to borrow       ** Monthly ** Quarterly ** Semi-Annual ** Annual **\n");
    printf("*************************************************************************\n");
    printf("* P1,000 below        **   5%%    **    -      **     -       **   -    **\n");
    printf("* P1,001-P10,000      **   5%%    **   16%%     **     -       **   -    **\n");
    printf("* P10,001-P50,000     **   5%%    **   16%%     **    19%%      **   -    **\n");
    printf("* P50,001-P100,000    **   6%%    **   17%%     **    19%%      **  27%%   **\n");
    printf("* P100,001-P500,000   **   6%%    **   17%%     **    20%%      **  29%%   **\n");
    printf("* P500,001-P1,000,000 **   7%%    **   18%%     **    21%%      **  30%%   **\n");
    printf("*************************************************************************\n");
    printf("\n");

input_amount:
    printf("Enter the amount of money to be borrowed: P ");
    scanf("%d",&amount);

    // Error 1: Invalid amount
    if(amount > 1000000){
        printf("\n*************************** Invalid Input *******************************\n");
        printf("**               Amount should not exceed P1,000,000                   **\n");
        printf("*************************************************************************\n");
        goto input_amount;
    }

input_tor:
    printf("\nTerms of Payment(TOR) **************\n");

    // TOR selection
    if(amount >= 1 && amount <= 1000){
        printf("1 -> Monthly");
        tor_lim = 1;
        x = 1;
    }else if(amount >= 1001 && amount <= 10000){
        printf("1 -> Monthly\n2 -> Quarterly");
        tor_lim = 2;
        x = 2;
    }else if(amount >= 10001 && amount <= 50000){
        printf("1 -> Monthly\n2 -> Quarterly\n3 -> Semi-Annual");
        tor_lim = 3;
        x = 3;
    }else if(amount >= 50001 && amount <= 100000){
        printf("1 -> Monthly\n2 -> Quarterly\n3 -> Semi-Annual\n4 -> Annual");
        tor_lim = 4;
        x = 4;
    }else if(amount >= 100001 && amount <= 500000){
        printf("1 -> Monthly\n2 -> Quarterly\n3 -> Semi-Annual\n4 -> Annual");
        tor_lim = 4;
        x = 5;
    }else if(amount >= 500001 && amount <= 1000000){
        printf("1 -> Monthly\n2 -> Quarterly\n3 -> Semi-Annual\n4 -> Annual");
        tor_lim = 4;
        x = 6;
    }

    printf("\nSelect Terms of Payment(TOR) : ");
    scanf("%d",&tor);

    if(tor > tor_lim){
        printf("\n*************************** Invalid Input *******************************\n");
        printf("**                No #%d stated in the following choices                **\n",tor);
        printf("*************************************************************************\n");
        goto input_tor;
    }

    input_month:
    switch(tor){
    case 1: // Monthly
        printf("\nEnter the number of periods that the borrowed money will be fully paid: ");
        scanf("%d",&periods);

        if(periods > 24){
            printf("\n*************************** Invalid Input *******************************\n");
            printf("**                Number of months should not exceed to 24             **\n");
            printf("*************************************************************************\n");
            goto input_month;
        }
        break;
    case 2: // Quarterly
        printf("\nEnter the number of periods that the borrowed money will be fully paid (1 quarter = 3 months): ");
        scanf("%d",&periods);

        if(periods*3 > 24){
            printf("\n*************************** Invalid Input *******************************\n");
            printf("**                Number of months should not exceed to 24             **\n");
            printf("*************************************************************************\n");
            goto input_month;
        }
        break;
    case 3: // Semi-annual
        printf("\nEnter the number of periods that the borrowed money will be fully paid (1 semi-annual = 6 months): ");
        scanf("%d",&periods);

        if(periods*6 > 24){
            printf("\n*************************** Invalid Input *******************************\n");
            printf("**                Number of months should not exceed to 24             **\n");
            printf("*************************************************************************\n");
            goto input_month;
        }
        break;
    case 4: // Annual
        printf("\nEnter the number of periods that the borrowed money will be fully paid (1 annual = 12 months): ");
        scanf("%d",&periods);

        if(periods*12 > 24){
            printf("\n*************************** Invalid Input *******************************\n");
            printf("**                Number of months should not exceed to 24             **\n");
            printf("*************************************************************************\n");
            goto input_month;
        }
        break;
    default:
        break;
    }

    // Computations
    // Monthly_rate = ( 1 + i )^nt
    // Payment = ( ammount x monthly_rate )/( 1 - (1 + monthly_rate)^-periods)
    // interest payment = payment x monthly rate
    // principal = payment - interest payment
    if(x == 1){
        // Monthly
        monthly_rate = 0.00407412; // ( 1 + 5% )^(1/12) - 1
        printf("\n************************************ Amortization Table *****************************************\n");
        printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
        remaining_balance = amount;
        for(y = 0; y <= periods; y++){
            if(remaining_balance < 0){
                remaining_balance = 0;
            }
            printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);;
            total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
            interest_amount = remaining_balance * monthly_rate;
            principal_amount = total_payment - interest_amount;
            remaining_balance = remaining_balance - total_payment;
        }
    }else if(x == 2){
        if(tor == 1){
            // Monthly
            monthly_rate = 0.00407412; // ( 1 + 5% )^(1/12) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
            if(remaining_balance < 0){
                remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);;
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 2){
            // Quarterly
            monthly_rate = 0.03780198; // ( 1 + 16% )^(1/4) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);;
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }
    }else if(x == 3){
        if(tor == 1){
            // Monthly
            monthly_rate = 0.00407412; // ( 1 + 5% )^(1/12)
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 2){
            // Quarterly
            monthly_rate = 0.03780198; // ( 1 + 16% )^(1/4)
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 3){
            // Semi-Annual
            monthly_rate = 0.09087121; // ( 1 + 19% )^(1/2)
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }
    }else if(x == 4){
        if(tor == 1){
            // Monthly
            monthly_rate = 0.00486755; // ( 1 + 6% )^(1/12)
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                if(remaining_balance == 0){
                    break;
                }
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 2){
            // Quarterly
            monthly_rate = 0.04003143; // ( 1 + 17% )^(1/4)
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 3){
            // Semi-Annual
            monthly_rate = 0.09087121; // ( 1 + 19% )^(1/2)
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 4){
            // Annual
            monthly_rate = 0.27; // ( 1 + 27% )^1 - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }
    }else if(x == 5){
        if(tor == 1){
            // Monthly
            monthly_rate = 0.00486755; // ( 1 + 6% )^(1/12) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 2){
            // Quarterly
            monthly_rate = 0.04003143; // ( 1 + 17% )^(1/4) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 3){
            // Semi-Annual
            monthly_rate = 0.09544511; // ( 1 + 20% )^(1/2) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 4){
            // Annual
            monthly_rate = 0.29; // ( 1 + 29% )^1 - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);

                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }
    }else if(x == 6){
        if(tor == 1){
            // Monthly
            monthly_rate = 0.00565414; // ( 1 + 6% )^(1/12) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 2){
             // Quarterly
            monthly_rate = 0.04224663; // ( 1 + 18% )^(1/4) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 3){
            // Semi-Annual
            monthly_rate = 0.1; // ( 1 + 21% )^(1/2) - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }else if(tor == 4){
            // Annual
            monthly_rate = 0.30; // ( 1 + 30% )^1 - 1
            printf("\n************************************ Amortization Table *****************************************\n");
            printf("\nNo. Periods\t-\tPayment\t-\tPrincipal\t-\tInterest\t-\tRemaining Balance\n");
            remaining_balance = amount;
            for(y = 0; y <= periods; y++){
                if(remaining_balance < 0){
                    remaining_balance = 0;
                }
                printf("%d\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\t-\t%.2lf\n",y,total_payment,principal_amount,interest_amount,remaining_balance);
                total_payment = (amount * monthly_rate)/(1 - (pow(monthly_rate+1,-periods)));
                interest_amount = remaining_balance * monthly_rate;
                principal_amount = total_payment - interest_amount;
                remaining_balance = remaining_balance - total_payment;
            }
        }
    }

    printf("\n Would you like to lend again? [Y/N] : ");
    scanf("%c",&rep);
    scanf("%c",&repeat);
    switch(repeat){
    case 'Y':
    case 'y':
        goto intro;
        break;
    default:
        break;
    }
    return 0;
}
