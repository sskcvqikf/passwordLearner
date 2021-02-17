#include <string.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void ctrl_c_handle(sig_atomic_t sig){
    printf("Got signal 2. Exiting...\n", sig);
    exit(1);

}

int main(int argc, char* argv[])
{
    if (argc % 2 == 0 || argc == 0){
        printf("Usage: password_learner id pwd ...\n"
               "Quantity of parameters must be even.\n");
        return EXIT_FAILURE;
    }
    signal(SIGINT, &ctrl_c_handle);
    initscr();
    clear();
    srand(time(0));
    auto halfed = argc / 2;
    char* ids[halfed];
    char* pwds[halfed];
    for(auto i = 1ul; i < argc; i += 2){
        ids[i-1] = argv[i];
        pwds[i-1] = argv[i + 1];
    }

    auto idx = 0;
    char buff[256];
    for(;;){
        idx = rand() % halfed;
        printw("Password for %s: ", ids[idx]);
        noecho();  // disable character echoing
        getnstr(buff,sizeof(buff));
        echo(); // enable character echoing again
        if (strcmp(buff, pwds[idx]) != 0)
            printf("Wrong!\n");
        else
            printf("Correct!\n");
        sleep(2);
        clear();
    }


    return EXIT_SUCCESS;
}
