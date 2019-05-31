#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

#define PROMPT "shell$ "
/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // Open directory
  DIR *dir;
  struct dirent *d;

  char user_input[20];

  // default to open current dir if no input provided
  if (argv[1] == NULL)
  {
    dir = opendir(".");
  }
  else if ((dir = opendir(argv[1])) == NULL)
  {
    printf("Error occurred.");
    exit(1);
  }

  // prints everything in directory
  while ((d = readdir(dir)) != NULL)
  {
    printf("  %s\n", d->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}