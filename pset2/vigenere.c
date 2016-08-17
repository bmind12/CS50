#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

string capital(string str);
int nextchar(int count, int max);

int main(int argc, string argv[])
{

  if (argc != 2)
  {
    printf("Usage: ~/workspace/pset2/caesar <word key>\n");
    return 1;
  }
  string s = capital(argv[1]);
  for (int i = 0, n = strlen(s); i < n; i++)
  {
      if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z'))
      {
        printf("A string should contain only characters\n");
        return 1;
      }
  }

  string ss = GetString();
  int count = 0;
  int max = strlen(s) - 1;
  int chng;

  for (int i = 0, l = strlen(ss); i < l; i++)
    {
        chng = s[count] - 'A';
        if (ss[i] >= 'a' && ss[i] <= 'z')
        {
          if (ss[i] + chng > 'z')
          {
            ss[i] = ss[i] + chng - 26;
            count = nextchar(count, max);
          }
          else
          {
            ss[i] = ss[i] + chng;
            count = nextchar(count, max);
          }
        }
        else if (ss[i] >= 'A' && ss[i] <= 'Z')
        {
          if (ss[i] + chng > 'Z')
          {
            ss[i] = ss[i] + chng - 26;
            count = nextchar(count, max);
          }
          else
          {
            ss[i] = ss[i] + chng;
            count = nextchar(count, max);
          }
        }
    }

  printf("%s\n", ss);
  return 0;

}

string capital(string str)
{

  for (int i = 0; i < strlen(str); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] + ('A' - 'a');
  }

  return str;
}

int nextchar(int count, int max)
{
    if (count == max) count = 0;
    else count++;

    return count;
}
