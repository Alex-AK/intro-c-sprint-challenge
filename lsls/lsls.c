#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_TOKENS 100
#define PROMPT "shell$ "
/**
 * Main
 */

// concat function from SO
char *concat(const char *s1, const char *s2)
{
  char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  // in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);
  return result;
}

int main(int argc, char **argv)
{
  // Parse command line to split each level
  char *args[MAX_TOKENS];
  char *token;

  int count = 0;

  token = strtok(argv[1], " \t\n\r");

  while (token != NULL)
  {
    // put the token in the args array
    args[count] = token;
    (count)++;
    token = strtok(NULL, " /");
  }

  // add a NULL to the end of the args array to indicate that there are no more args
  args[count] = NULL;

  // Open directory
  DIR *dir;
  struct dirent *d;
  struct stat buf;

  if (count == 0)
  {
    dir = opendir(".");
    while ((d = readdir(dir)) != NULL)
    {
      stat(d->d_name, &buf);
      printf("%lld", buf.st_size);
      printf("  %s\n", d->d_name);
    }
    // Close directory
    closedir(dir);
  }
  else
  {
    for (int i = 0; i < count; i++)
    {
      // for each directory in parsed, open dir
      if ((dir = opendir(args[i])) == NULL)
      {
        printf("Error occurred. Please enter a valid directory.\n");
        exit(1);
      }

      if (dir)
      {
        // prints everything in directory
        while ((d = readdir(dir)) != NULL)
        {
          char *full_path = concat(argv[1], d->d_name);
          // run concat function
          stat(full_path, &buf);
          printf("%lld", buf.st_size);
          printf("  %s\n", d->d_name);
        }
        // Close directory
        closedir(dir);
      }
    }
  }

  return 0;
}