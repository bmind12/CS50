#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

  if (argc != 2) return 1;
  int k = atoi(argv[1]);
  if (k < 0) return 1;

  string s = GetString();

  for (int i = 0, l = strlen(s); i < l; i++)
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
    {
      s[i] = s[i] + (k % 26);
    }

  printf("%s\n", s);
  return 0;
}
