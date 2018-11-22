#include<stdio.h>

char names_of_participants[50][100];
int survivor_container[50];
int number_of_participants,interval,counter, remove_participant = 0;
int y,x;

int main(void)
{
  printf("Participants: ");
  scanf("%i", &number_of_participants);
    x = number_of_participants;
  printf("\nNames:\n");
  for( y = 0 ; y < number_of_participants ; y++ )
    {
       survivor_container[y] = 1;
       printf("%i. ", y+1 );
       scanf("%s", &names_of_participants[y]);
    }
   printf("\nIntervals: ");scanf("%i",&interval);
    while(x!=1){
        counter = 1;
        while(counter <= interval){
            if( remove_participant == number_of_participants){
                remove_participant = 0;
                if(survivor_container[remove_participant] == 0 ){
                remove_participant++;
                }
            }
            if(survivor_container[remove_participant] == 0 ){
                remove_participant++;
                if( remove_participant == number_of_participants){
                    remove_participant = 0;
                    if(survivor_container[remove_participant] == 0 ){
                    remove_participant++;
                    }
                }
            }

            if(counter == interval){
                printf("%s ,", names_of_participants[remove_participant]);
                survivor_container[remove_participant] = 0;
            }
            counter++;
            remove_participant++;
        }
        x--;
    }
        printf("\n\n");
        for(y = 0 ; y <= number_of_participants - 1 ; y++){
            if(survivor_container[y] == 0){
                continue;
            }else{
                printf("\n>%s is the sole survivor.", names_of_participants[y]);
            }
        }
 return 0;
}
