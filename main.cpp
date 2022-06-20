#include "highLow.h"
#include <iostream>
#include <random> // for std::mt19937 and std::uniform_int_distribution


int main(void)
{
	/*
	start
	set random number
	set lives
	display intro
	get guess
	check guess
	*/
	start();
	return 0;
}

void start()
{
	bool playing{ true };
	while (playing)
	{
		int correct_answer{ set_random_number() };
		int lives{ 6 };
		int guess_count{ 1 };
		welcome_msg(lives);
		bool turn{ true };
		while (turn)
		{
			if (lives == 0)
			{
				std::cout << "Sorry, you lose. The correct number was " << correct_answer << "\n\n";
				bool playAgain{ play_again() };
				if (!playAgain)
					playing = false;
				break;
			}
			
			int guess{ get_guess(guess_count) };

			if (check_guess(correct_answer, guess))
			{
				std::cout << "Correct! You Win!\n\n";
				bool playAgain{ play_again() };
				if (!playAgain)
					playing = false;
				break;
			}

			if (guess > correct_answer)
				std::cout << "Your guess is too high.\n\n";
			else
				std::cout << "Your guess is too low.\n\n";
			
			guess_count++;
			lives--;
		}	
	}
}

int set_random_number()
{
	std::random_device rd;
	std::seed_seq ss{ rd(), rd(),rd(),rd(),rd(),rd(),rd(),rd(), };
	std::mt19937 mer_twister {ss};
	std::uniform_int_distribution uniform_1_to_100{ 1,100 };

	int x = uniform_1_to_100(mer_twister);

	return x;

}

void welcome_msg(int lives)
{
	std::cout << "\n\nLet's play a game. I'm thinking of a number. You have " << lives << " tries to guess what it is.\n\n";
}

int get_guess(int guess_count)
{
	while (true)
	{
		std::cout << "Guess #" << guess_count << ": ";
		int guess{};
		std::cin >> guess;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return guess;
	}
}

bool check_guess(int answer, int guess)
{
	return (answer == guess);
}

bool win_play_again(void)
{
	std::cout << "Correct! You win!\n";
	std::cout << "Want to play again (y/n)?";
	char play_again{};
	std::cin >> play_again;
	if (play_again == 'y')
		return true;
	
	return false;
}

bool play_again()
{
	std::cout << "Would you like to play again? (y/n) ";
	char c{};
	std::cin >> c;
	return (c == 'y');
}

