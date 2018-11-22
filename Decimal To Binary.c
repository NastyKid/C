
#include<stdio.h>



int main(void)
{
 int dec, maxpower2, counter;

 printf("Enter a  decimal number to convert into a binary number: ");
 scanf("%d", &dec);

 counter=0;
 maxpower2=1;
 while(dec>maxpower2)
 {
     counter=counter+1;
     maxpower2=maxpower2*2;
 }

 counter=counter-1;
 maxpower2=maxpower2;

 while(maxpower2>0)
 {
  if(dec-maxpower2>=0)
  {
    printf("1");
    dec=dec-maxpower2;
  }

  else
      printf("0");

    maxpower2=maxpower2/2;
    counter=counter-1;
 }


return 0;
}
