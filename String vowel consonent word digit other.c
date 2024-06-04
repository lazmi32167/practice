#include<stdio.h>
int main()
{
    char str[50],ch;
    int i,vowel,cons,word,digit,other;
    i=vowel=cons=word=digit=other=0;
    printf("Enter the string: ");
    gets(str);
    while(ch= str[i]!='\0')
    {
 if(ch=='a' ||ch=='e'||ch=='i'||ch=='o'||ch=='u' || ch=='A' ||ch=='E'||ch=='I'||ch=='O'||ch=='U')
{
    vowel++;
}
 else if(ch!='a' ||ch!='e'||ch!='i'||ch!='o'||ch!='u' || ch!='A' ||ch!='E'||ch!='I'|| ch!='O'|| ch!='U')
    {
        cons++;
    }
    else if(ch>='0' && ch<='9'){
       digit++;
    }
      else if(ch = ' ')
      {
          word++;
      }
      else {
        other++;
      }

      i++;
    }
    word++;
    printf("Numer of vowels are : %d\n",vowel);
    printf("Numer of consonant are : %d\n",cons);
    printf("Numer of words are : %d\n",word);
    printf("Numer of digits are : %d\n",digit);
    printf("Numer of others are : %d\n",other);
}
