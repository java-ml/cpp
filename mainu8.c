#include <stdio.h>
#include <string.h>
const char* user = "admin";
const char* pass = "admin";
int add(int* m) {
  int n = 0;
  printf("请输入存款金额：");
  scanf("%d", &n);
  *m += n;
  return *m;
}
int sub(int* m) {
  int n = 0;
  printf("请输入取款金额：");
  scanf("%d", &n);
  if (*m < n || n < 0) {
    printf("余额不足");

  } else {
    *m -= n;
  }

  return *m;
}
int login() {
  int k = 3;
  char u[20], p[20];
  char* find;
  while (k > 0) {
	
    printf("请输入用户名：");
    fgets(u, 15, stdin);
    printf("请输入密码：");
    fgets(p, 15, stdin);
     find= strchr(u, '\n');  //找出data中的"\n"
    if (find)
      *find = '\0'; 
	find = strchr(p, '\n');  //找出data中的"\n"
    if (find)
      *find = '\0'; 
    if (strcmp(user, u) || strcmp(pass, p)) {
      printf("用户名或密码错误！\n%s    %s",u,p);
    } else {
      return 1;
    }
    k--;
  }
  return 0;
}
int main() {
  if (login()) {
    int a = 0;
    printf("\t\t菜单：\n\t1、存款\n\t2、取款\n \t输入-1退出\n******************************************\n");
    int k = 1;
    while (k) {
      printf("请输入指令【1、2】：");
      scanf("%d", &k);
      if (k == 1)
        printf("余额： %d\n", add(&a));

      else if (k == 2) {
        printf("余额： %d\n", sub(&a));
      } else if(k==-1) {
        return 0;
      }
      else {
        printf("错误指令\n");
      }
    }
  }
  return 0;
}
