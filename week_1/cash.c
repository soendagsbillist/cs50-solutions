#include <stdio.h>
#include <cs50.h>
#include <math.h>

int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;
int dollar;

int owed_money(void)
{
  float owed_money;
  do
  {
    owed_money = get_float("Owed: ");
  }
  while(owed_money < 0);
  return (owed_money * 100);
}


/*int get_number_of_coins(int initial_sum, int change, int coin_type)
{
  return dollar;
}
*/

int calculate_change(int initial_amount, int type_of_coin)
{
  int change = initial_amount % type_of_coin;
  return change;
}

int main(void)
{
  int money = owed_money();
  dollar = calculate_change(money, quarter);
  printf("%i\n", dollar);
}




