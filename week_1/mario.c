/*
	CS50 Assignment 1.
	Create pyramids like following:
	   #  #
	  ##  ##
	 ###  ###
	####  ####	
	User should be able to give desired height of the pyramid.
*/

#include <stdio.h>
#include <cs50.h>

void add_space(int times)
{
	for(int i = 0; i < times; i++)
	{
		printf(" ");
	}	
}

void add_hash(int times)
{
	for(int i = 0; i < times; i++)
	{
		printf("#");
	}	
}

int main(void)
{
	int height;
	do
	{
		height = get_int("Height: ");
	}
	while(height < 1);
	
	for(int i = 0; i < height; i++)
	{
		add_space(height-i+1);
		add_hash(i+1);
		add_space(2);
		add_hash(i+1);
		printf("\n");
	}
}

