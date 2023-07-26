#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

// struct for holding original terminal settings
struct termios orig_termios;

// function to turn on "no buffor" mode
void enableRawMode()
{
    struct termios raw;

    tcgetattr(STDIN_FILENO, &orig_termios);
    raw = orig_termios;

    // turn of classical keyboard mode
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    // set minimal delay time and min char number
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;

    // set my setting in terminal
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// function to turn off "no buffor" mode
void disableRawMode()
{
    tcsetattr(STDIN_FILENO, TCIFLUSH, &orig_termios);
}