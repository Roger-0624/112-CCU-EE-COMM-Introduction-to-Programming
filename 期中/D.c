#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int len;

void dfs(char *word, int n, char *ans){
  if(n == len){
    printf("%s\n", ans);
    return;
  }
  for(int i = 0; i < len; i++){
    if(word[i] != '.'){
      char temp = word[i];
      ans[n] = temp;
      word[i] = '.';
      dfs(word, n + 1, ans);
      word[i] = temp;
    }
  }
  return;
}

int main(){

  char *word = (char*)calloc(11, sizeof(char));
  char *ans = (char*)calloc(11, sizeof(char));

  scanf("%s", word);
  len = strlen(word);


  dfs(word, 0, ans);

  return 0;
}


//這題跟作業的 SAO 那題很像，皆是一路遞迴到長度限制，做法是每次從題目給定的字串由前往後挑出第一個還未被使用過的字符串接上答案，字符 '.' 為標記該字元是否使用過，因此遞迴前要先將該字元標記為 '.'，在遞迴完使用完後則要改回去。