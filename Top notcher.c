#include <stdio.h>
#include <stdlib.h>

int main()
{
    // subject[#student][subject]
    int number_of_student = 3;
    int subject[number_of_student][5];
    int getgrade[number_of_student];
    int topstud[3]; // fixed 3
    int temp;

    char subject_name[5][50] = {"Math","English","Filipino","Science","PE"}; // subject name
    char student_fname[number_of_student][100];
    char student_lname[number_of_student][100];

    for(int i = 0 ; i < number_of_student ; i++){
        printf("Student #%d first name:", i+1);
        scanf("%s", &student_fname[i]);
        printf("Student #%d last name:", i+1);
        scanf("%s", &student_lnames[i]);
        printf("\n");
    }

    // entering grade
    printf("\n\nEntering grade per subject: \n");
    for(int i = 0; i < number_of_student ; i++){
        printf("%s, %s\n", student_lname[i],student_fname[i]);
        for(int j = 0; j < 5 ; j++){
            printf("\t%s: ",subject_name[j]);
            scanf("%d",&subject[i][j]);
        }
        printf("\n");
    }
    // Top 3 in each subject
    for(int i = 0,sub = 0; i < 5; i++,sub++){
        // get student grade
        for(int k = 0; k < number_of_student; k++){
            getgrade[k] = subject[k][i];
        }
        // Sort descending order
        for (int z = 0 ; z < number_of_student; z++){
    		for (int x= 0 ; x < number_of_student - z - 1; x++){
      			if(getgrade[x] < getgrade[x+1]){
        			temp=getgrade[x];
        			getgrade[x]   = getgrade[x+1];
        			getgrade[x+1] = temp;
      			}
    		}
        }
        // Top
        printf("\n%s", subject_name[sub]);
        printf("\n");
        for(int g = 0; g < 3 ; g++){
            for(int y = 0; y < number_of_student; y++){
                if(subject[y][i] == getgrade[g]){
                    if(g != 0){
                        if(topstud[g-1] == y){
                            break;
                        }else{
                            topstud[g] = y;
                        }
                    }else{
                        topstud[g] = y;
                    }
                }
            }
        }

        for(int n = 0 ; n < 3 ; n++){
            printf("%d. %s, %s\n", n+1, student_lname[topstud[n]],student_fname[topstud[n]]);
        }
        // refresh for the new top student in the next subject
        for(int p = 0 ; p < 3 ; p++){
            topstud[p] = 0;
        }
        printf("\n");
    }

    // Average
    int sum = 0, ave[number_of_student],t_ave[number_of_student];
    for(int i = 0; i < number_of_student ; i++){
        for(int x = 0; x < 5; x++){
            sum += subject[i][x];
        }
        ave[i] = sum/5;
        t_ave[i] = ave[i];
        sum = 0;
    }
    for (int z = 0 ; z < number_of_student; z++){
    		for (int x= 0 ; x < number_of_student - z - 1; x++){
      			if(t_ave[x] < t_ave[x+1]){
        			temp=t_ave[x];
        			t_ave[x]   = t_ave[x+1];
        			t_ave[x+1] = temp;
      			}
    		}
        }
     for(int g = 0; g < 3 ; g++){
            for(int y = 0; y < number_of_student; y++){
                if(ave[y] == t_ave[g]){
                    if(g != 0){
                        if(topstud[g-1] == y){
                            break;
                        }else{
                            topstud[g] = y;
                        }
                    }else{
                        topstud[g] = y;
                    }
                }
            }
        }
    printf("\n\nTop student:");
    for(int i = 0; i < 3 ; i++){
        printf("\n\t%s, %s : Average : %d",student_lname[topstud[i]],student_fname[topstud[i]],t_ave[i]);
    }


    return 0;
}
