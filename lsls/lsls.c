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

  printf("%s\n", PROMPT);

  // Open directory
  DIR *dir;
  struct dirent *d;

  // default to open current dir if no input provided
  // not yet working
  if (!argv[1])
  {
    if ((dir = opendir(".")) == NULL)
    {
      printf("Error occurred.");
      exit(1);
    }
  }

  // opens specified dir
  if ((dir = opendir(argv[1])) == NULL)
  {
    printf("Error occurred.");
    exit(1);
  }

  // prints everything in directory
  while ((d = readdir(dir)) != NULL)
  {
    printf("  %s\n", d->d_name);
  }

  return 0;
}