#include <stdio.h>
#include <stdlib.h>


int main()
{
    int t_len,vt_len,vt = 0,num_vt = 0;
    char choice;
A:
    printf("Enter the length of ABC: ");
    scanf("%d", &t_len);
    printf("Enter the length of valid triangles: ");
    scanf("%d", &vt_len);

    if(t_len % 2 == 0){
        vt = t_len / 2;
    }
    if(vt_len == vt){
        num_vt = 4;
    }else if(vt_len == t_len){
        num_vt = 1;
    }else{
        num_vt = 3;
    }

    printf("There are %d valid triangles in ABC.\n",num_vt);

    printf("\n\nCount more triangle?[y/n]\n>");
    scanf("%s", &choice);
    if(choice == 'Y' || choice == 'y'){
        printf("\n\n\n");
        goto A;
    }
    return 0;
}
