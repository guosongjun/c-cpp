#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i;

	int *p=NULL;
	p=malloc(sizeof(int));
	if(p==NULL)
	{
		return -1;
	}



	printf ("hello world!\n");

	return 0;

}
