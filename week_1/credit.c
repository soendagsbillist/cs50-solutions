/*
  Implementation of the Luhn's algorithm for cs50 pset1
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int get_sum_of_every_second_digit(long number, bool start_from_the_end);
long check_last_digit(long number, int digit);
void check_validity(long card_number, int odd, int even);

int main(int argc, string argv[])
{
	long number = get_long("Credit Card Number: ");
	int sum_of_every_other = get_sum_of_every_second_digit(number, false);
	int sum_of_every_second = get_sum_of_every_second_digit(number, true);
	check_validity(number, sum_of_every_second, sum_of_every_other);
}

/*
  CreditCardNumber StartFromTheEnd -> Sum of every second digit multiplied
  Takes every other digit, multiplies by two and returns sum.
  If one of the integers contains more than one digits it gets
  divided in two.
  It starts with number's last digit if starts_from_the_end == true;
*/
int get_sum_of_every_second_digit(long number, bool start_from_the_end)
{
	long card_number;
	//gets rid of the last digit in order to iterate over the number’s second-to-last digit
	start_from_the_end ? (card_number = number) : (card_number = number / 10);
	int counter = 0;
	int sum = 0;

	while(card_number > 0)
	{
		int last_digit;
		start_from_the_end ? (last_digit = card_number % 10) : (last_digit = (card_number % 10) * 2);
		card_number = card_number / 100;
		counter++;
		if(last_digit / 10 > 0)
		{
			int first = last_digit / 10;
			int last = last_digit % 10;
			sum = sum + first + last;
		}
		else
		{
			sum = sum + last_digit;
		}
	}
	//printf("%i\n", sum);
	return sum;
}

void check_validity(long card_number, int odd, int even)
{
	int counter = 0;
	int first_digit;
	while(card_number > 0)
	{
		card_number = card_number / 10;
		counter ++;
		if(counter == 15)
		{
			first_digit = card_number;
		}
	}
	
	int sum = odd + even;
	if(sum % 10 == 0 && counter == 15)
	{
		printf("AMERICAN EXPRESS\n");
	}
	else if(sum % 10 == 0 && counter == 16 && first_digit == 4)
	{
		printf("VISA\n");
	}
	else if(sum % 10 == 0 && counter == 13)
	{
		printf("VISA\n");
	}
	else if(sum % 10 == 0 && counter == 16 && first_digit != 4)
	{
		printf("MASTERCARD\n");
	}
	else
	{
		printf("Invalid\n");
	}
}
