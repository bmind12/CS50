#include <stdio.h>
#include <cs50.h>
#include <string.h>

string capital(string abb);

int main()
{
  string name = GetString();
  int namelen = strlen(name);
  char abb[namelen];
  abb[0] = name[0];
  int a = 1;

  for (int i = 1; i < namelen; i++) {
    if (name[i-1] == ' ')
    {
       abb[a] = name[i];
       a++;
    }
  }
  printf("%s\n", capital(abb));
}

string capital(string str)
{
  int len = strlen(str);

  for (int i = 0; i < len; i++)
  {
    if ((int) str[i] < 97)
      str[i] = (char) (int) str[i] + 32;
  }
}
