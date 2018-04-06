#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

#define MAX_LINE 4096
#define MAX_WORDS MAX_LINE/2
/* a line can have at most MAX_LINE/2 words, why? */

void tokenize(char *line, char **words, int *nwords);
/* break line into words separated by whitespace, placing them in the 
   array words, and setting the count to nwords */

int main()
{
        char line[MAX_LINE], *words[MAX_WORDS], message[MAX_LINE];
        int stop=0,nwords=0;

        while(1)
        {
                printf("OSP CLI $ ");
			
                /* read a line of text here */
			
                tokenize(line,words,&nwords);

                /* More to do here */

        }
        return 0;
}

/* this function works, it is up to you to work out why! */
void tokenize(char *line, char **words, int *nwords)
{
        *nwords=1;

        for(words[0]=strtok(line," \t\n");
            (*nwords<MAX_WORDS)&&(words[*nwords]=strtok(NULL, " \t\n"));
            *nwords=*nwords+1
           ); /* empty body */
        return;
}
