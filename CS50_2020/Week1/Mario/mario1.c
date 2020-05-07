#include <stdio.h>

int main()
{
  int height;

  while (1==1) {

    do{
    printf("Enter the height of Mario's shabeen: ");
    scanf("%d", &height);
    }while(height < 1);
    printf("The height is: %d\n\n", height);

    for(int i = 0; i < height; i++)
    {
      for(int j = 0; j < height; j++)
      {
        if(i + j < height-1)
        {
          printf("  ");
        }else
        {
          printf("# ");
        }
      }
      printf("\n");

    }
  }

  return 0;

}
