#include <stdio.h>

int main()
{
  int height;

  do{
  printf("Height: ");
  scanf("%d", &height);
}while(height < 1 || height > 9);

  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < height + i + 2; j++)
    {

      if(j == height)
      {
        printf(" ");
      }

      else if(i + j < height-1)
      {
        printf(" ");
      }

      else if(j - i > height + 1)
      {
        printf(" ");
      }

      else
      {
        printf("#");
      }
    }
    printf("\n");

  }

  return 0;

}








/*
   # #
  ## ##
 ### ###
#### ####

*/



//
