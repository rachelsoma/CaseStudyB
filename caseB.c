#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<errno.h>

#define MAX_CHAR_LINE 4096 /* max characters per line */
#define MAX_WORDS MAX_CHAR_LINE/2
/* smallest word is 1 char so if entire line is 1 char words with spaces max words is half MAX_CHAR_LINE */

void tokenize(char *line, char **words, int *nwords);
/* break line into words separated by whitespace, placing them in the 
array words, and setting the count to nwords */

int findAndExecute(char** words);

int main()
{
	char line[MAX_CHAR_LINE], *words[MAX_WORDS], message[MAX_CHAR_LINE];
	int stop=0,nwords=0;

	while(1)
	{
		printf("\nOSP CLI $ ");
		
		/* read a line of text here */
		fgets(line,MAX_CHAR_LINE,stdin);
		
		//printf("%s ", line);
		
		tokenize(line,words,&nwords);
		
		
		printf("Num words: %i \t\n",nwords);
		/* More to do here */
		
		if (strcmp(words[0],"exit") == 0&&nwords==1){
			printf("exiting \n");
			exit(0);
		} else {
			printf("else...");
			findAndExecute(words);
			
		}

	}
	return 0;
}

/* this function works, it is up to you to work out why! */
void tokenize(char *line, char **words, int *nwords)
{
	*nwords=1;


	for(words[0]=strtok(line," \t\n");
	(*nwords<MAX_WORDS)&&(words[*nwords]=strtok(NULL, " \t\n"));
	*nwords=*nwords+1); 
	
	/* empty body */
	
	
	/* uh oh, the sample code returns nwords of 1 even when there's no words */
	
	return;
}

int findAndExecute(char** words){
	
	pid_t child;
	
	//if (strcmp(words[0],"ls") == 0){
		switch(child=fork())
		{
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("CASE 0: I am the child my pid is: %d\n",getpid());
			execlp(words[0],words[0],NULL);
			
			break;
		default:
			printf("DEFAULT: I am the parent, my pid is %d,",getpid());
			printf("and my child is %d\n",child);
		/* 	exit(0); */
			/* return 1; */
			break;
		}
	/* }
	else {
		switch(child=fork())
		{
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("I am the child my pid is: %d\n",getpid());
			return 1;
			break;
		default:
			printf("I am the parent, my pid is %d,",getpid());
			printf("and my childs is %d\n",child);
			return 1;
			break;
		}
	} */
	return 1;
}
