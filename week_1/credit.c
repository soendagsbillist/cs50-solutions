#include <stdio.h>
#include <cs50.h>
#include <string.h>

int get_sum_of_every_second_digit(long number, bool start_from_the_end);
long check_last_digit(long number, int digit);

int main(int argc, string argv[])
{
	long number = get_long("Credit Card Number: ");
	int sum_of_every_other = get_sum_of_every_second_digit(number, false);
	int sum_of_every_second = get_sum_of_every_second_digit(number, true);
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
	printf("%i\n", sum);
	return sum;
}

