#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d,y,n,a,s,t,c,h; /** Number of index in array **/

    printf("Enter the size of array: ");
    scanf("%d", &d);
    h = d;
    int arr[d];

    for(y = 0 ; y < d ; y++){ /** INSERTING VALUE IN ARRAY **/

        printf("\nEnter element %d: ",y);
        scanf("%d", &arr[y]);

    }

    printf("\nArray values: "); /** DISPLAY THE VALUES IN ARRAY **/

    for( n = 0 ; n < d ; n++){

        printf("%d ",arr[n]);

    }

    printf("\nReversed values: ");

    s = d - 1;
    d = 0;

    while ( d < s){ /** REVERSING THE VALUES IN ARRAY **/

        t = arr[d];
        arr[d] = arr[s];
        arr[s] = t;
        d++;
        s--;

    }

    for(c = 0 ; c < h ; c++){

        printf(" %d ", arr[c]);

    }


    return 0;
}
