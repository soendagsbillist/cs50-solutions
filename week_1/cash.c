/*
   Write a greedy algorithm in order to minimize the number of coins
   that is getting dispensed for a customer. Program asks for a number
   of dollars is owed and prints the minumum amount of coins that can
   be used.
*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int quarter = 25;
int dime = 10;
int nickel = 5;
int penny = 1;

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


int get_number_of_coins(int initial_sum, int change, int coin_type)
{
  return (initial_sum - change) / coin_type;
}

int calculate_change(int initial_amount, int type_of_coin)
{
  int change = initial_amount % type_of_coin;
  return change;
}

int cash(int amount_owed)
{
  int number_of_coins = 0;
  int quarter_change = calculate_change(amount_owed, quarter);

  if (quarter_change == 0)
  {
    number_of_coins = get_number_of_coins(amount_owed, calculate_change(amount_owed, quarter),
					  quarter);
  }
  if (quarter_change != 0)
  {
    int quarters = get_number_of_coins(amount_owed, calculate_change(amount_owed, quarter),
				       quarter);
    int dimes = get_number_of_coins(quarter_change, calculate_change(amount_owed, dime), dime);
    number_of_coins = (quarters + dimes);
  }

  int dime_change = calculate_change(quarter_change, dime);
  if (dime_change != 0)
  {
    int quarters = get_number_of_coins(amount_owed, calculate_change(amount_owed, quarter),
				       quarter);
    int dimes = get_number_of_coins(quarter_change, calculate_change(amount_owed, dime), dime);
    int nickels = get_number_of_coins(dime_change, calculate_change(dime_change, nickel), nickel);
    number_of_coins = (quarters + dimes + nickels);
  }

  int nickel_change = calculate_change(dime_change, nickel);

  if (nickel_change != 0)
  {
    int quarters = get_number_of_coins(amount_owed, calculate_change(amount_owed, quarter),
				       quarter);
    int dimes = get_number_of_coins(quarter_change, calculate_change(amount_owed, dime), dime);
    int nickels = get_number_of_coins(dime_change, calculate_change(dime_change, nickel), nickel);
    int pennies = get_number_of_coins(nickel_change, calculate_change(nickel_change, penny), penny);
    number_of_coins = (quarters + dimes + nickels + pennies);
  }
  return number_of_coins;
}

int main(void)
{
  int amount = owed_money();
  int money = cash(amount);
  printf("%i\n", money);
}
