#include<stdio.h>
#include<string.h>
void checkPalindrome(char[],int);
int main()
{
    char word[15];
    printf("Enter a word to check if it is a palindrome: ");
    scanf("%s",word);
    checkPalindrome(word,0);
    return 0;
}
void checkPalindrome(char word[],int index)
{
    int len;
    len=strlen(word)-(index+1);
    if(word[index]==word[len])
    {
        if(index+1==len || index==len)
        {
            printf("The entered word is a palindrome\n");
            return;
        }
        checkPalindrome(word,index+1);
    }
}