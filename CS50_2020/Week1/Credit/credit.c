#include <stdio.h>
#include <string.h>
#include <math.h>


long get_digits();
int get_length();
int get_sum();
int check_valid();
int check_visa();
int check_mastercard();
int check_amerix();


int main(void)
{
  long num;

  //num = 4003600000000014;
  //num = 5284973003233784;
  num = 5556744213896301;

  if(check_valid(num) == 1)
  {
    if(check_visa(num) == 1)
    {
      printf("VISA\n");
    }
    else if(check_mastercard(num) == 1)
    {
      printf("MASTERCARD\n");
    }
    else if(check_amerix(num) == 1)
    {
      printf("AMERICAN EXPRESS\n");
    }
  }else
  {
    printf("INVALID\n");
  }

  return 0;
}


int check_valid(long card_no)
{
  long power, counter, digits_odd, digits_even;
  int length, sum_odd, sum_even, sum_all;
  int valid = 0;

  //printf("NUMBER: %ld\n\n", card_no);
  length = get_length(card_no);
  digits_odd = get_digits(card_no, 1);
  digits_even = get_digits(card_no, 0);

  sum_odd = get_sum(digits_odd);
  sum_even = get_sum(digits_even);

  sum_all = sum_odd + sum_even;


  //printf("Digits odd: %ld\nDigits even: %ld\nlength: %d\n\n", digits_odd, digits_even, length);
  //printf("Sum odd: %d\nSum even: %d\n",sum_odd, sum_even);
  //printf("Sum all: %d\n", sum_all);

  if (sum_all % 10 == 0) {
    valid = 1;
  }

  return valid;
}


long get_digits(long in_num, int offset)
{
  int remainder;
  long output = 0;
  if(offset == 1)
  {
    in_num /= 10;
  }

  while (in_num > 1) {
    remainder = (in_num % 10)*(offset + 1);
    //printf("Num: %ld\n", in_num);
    //printf("Remainder: %d\n\n", remainder);
    in_num -= remainder / (offset + 1);
    in_num /= 100;

    if(remainder >= 10)
    {
      output *= 100;
    }else
    {
      output *= 10;
    }
    output += remainder;
    //printf("%d",remainder);
  }
  //printf("\nThe result is: %ld\n", output);
  return output;
}


int get_length(long in_num)
{
  int counter = 0;

  while(in_num > 1)
  {
    in_num /= 10;
    counter ++;
  }

  return counter;
}


int get_sum(long in_num)
{
  int remainder;
  int sum = 0;

  while (in_num >= 1) {
    remainder = in_num % 10;
    in_num -= remainder;
    in_num /= 10;

    sum += remainder;
  }

  return sum;

}


int check_visa(long card_no)
{
  int valid = 1;
  int length = get_length(card_no);
  long first_digit = card_no /= (pow(10, (length - 1)));

  if(first_digit != 4)
  {
    valid = 0;
  }
  if (length != 13 && length != 16) {
    valid = 0;
  }

  return valid;
}

int check_mastercard(long card_no)
{
  int valid = 1;
  int length = get_length(card_no);
  long first_digits = card_no /= (pow(10, (length - 2)));

  if(first_digits > 55 || first_digits < 51)
  {
    valid = 0;
  }
  if (length != 16) {
    valid = 0;
  }

  return valid;

}

int check_amerix(long card_no)
{
  int valid = 1;
  int length = get_length(card_no);
  long first_digits = card_no /= (pow(10, (length - 2)));

  if(first_digits != 34 && first_digits != 37)
  {
    valid = 0;
  }
  if (length != 15) {
    valid = 0;
  }

  return valid;

}
