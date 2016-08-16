#include <stdio.h>
#include <cs50.h>
#include <string.h>

string capital(string str);
int abblen;

int main()
{
  string name = GetString();
  abblen = strlen(name);
  int a = 0;

  for (int i = 0, sl = strlen(name); i < sl; i++)
    if (name[i-1] == ' ' || i == 0) a++;

  char abb[a];
  a = 0;

  for (int i = 0, sl = strlen(name); i < sl; i++) {
    if (name[i-1] == ' ' || i == 0)
    {
       abb[a] = name[i];
       a++;
    }

  }
  abblen = strlen(abb);
  printf("%s\n", capital(abb));
}

string capital(string str)
{

  for (int i = 0; i < abblen; i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] - ('a' - 'A');
  }

  return str;
}
