#ifndef HIGH_LOW_H
#define HIGH_LOW_H


void start();
int set_random_number();
void welcome_msg(int lives);
int get_guess(int guess_count);
bool check_guess(int answer, int guess);
bool win_play_again(void);
bool play_again();

#endif
