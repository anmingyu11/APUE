//this define opendir readdir origin
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

//chdir can change current working directory
//this is std of iso c style
int main(int argc, char *argv[])
{
	DIR *dp;
	struct dirent *dirp;

	if (argc != 2)
	{
		printf("usage : ls directory_name");
		exit(1);
	}

	//return struct dir	
	if ((dp = opendir(argv[1])) == NULL)
	{
		printf("can't open %s", argv[1]);
		exit(1);
	}

	//this readdir is read by auto
	while ((dirp = readdir(dp)) != NULL)
	{
		printf("%s\n", dirp->d_name);
	}

	closedir(dp);
	exit(0);
}
