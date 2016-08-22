#include <stdio.h>

#define TRUE 1
#define FALSE 0

enum BlankState
{
	NOTBLANK, FIRSTBLANK, FOLLOWBLANK
};

int main()
{
	int c;
	long nCharacter = 0;
	double nLine = 0.0f;
	double nBlank = 0.0f;
	double nTab = 0.0f;

	BlankState state = NOTBLANK;

	while ((c = getchar()) != 'q')
	{
		switch (c)
		{
		case '\n':
			nLine++;
			state = NOTBLANK;
			putchar(c);
			break;
		case ' ':
			nBlank++;
			if (state == NOTBLANK)
			{
				state = FIRSTBLANK;
				putchar(c);
			}
			else
			{
				state = FOLLOWBLANK;
			}
			break;
		case '\\':
			nCharacter++;
			state = NOTBLANK;
			putchar('\\');
			putchar('\\');
			break;
		case '\t':
			nTab++;
			state = NOTBLANK;
			putchar('\\');
			putchar('t');
			break;
		case '\b':
			state = NOTBLANK;
			putchar('\\');
			putchar('b');
			break;
		default:
			nCharacter++;
			state = NOTBLANK;
			putchar(c);
			break;
		}
	}
	printf("Chars: %ld, Lines: %.0f\n", nCharacter, nLine);
	printf("Blanks: %.0f, Tabs: %.0f\n", nBlank, nTab);
}