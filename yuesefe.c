/****************************************
  > File Name:    t2.c
  > Author:       guqiang
  > Mail:         544104926@qq.com
  > Created Time: 2014年10月28日 星期二 14时25分42秒
  > Function:     求出最后留下来的学生学号
  > 注意：        此程序有断错误  是从网上荡回来的  自己做的是死循环
*****************************************/

#include <stdio.h>

#define MAX_LEN 1000

/**************************************
 * name:           void out_stu(int *a)
 * Description:    不停的报数然后去掉3
 * called by:      main
 * calls:          no
 * input:          int *a
 * output:         no
 * return:         no
**************************************/
void out_stu(int *a, int num)
{
    int out;
    int i;
    int temp;

    while(out != (num - 1))
    {
        if(1 == a[i])
        {
            temp++;
        }

        if(num == 3)
        {
            a[i] = 0;
            temp = 0;
            out++;                     //检测被排除的人数
        }

        i++;

        if(i == num)
        {
            i = 0;
        }
    }

    for(i = 0; i < num; i++)
    {
        if(1 == a[i])
        {
            printf("the last is:%s\n",i+1);
            break;
        }
    }
}

int main()
{
    int i;
    int num;
    int a[MAX_LEN] = {0};

    printf("please input number:\n");
    scanf("%d",&num);

    for(i = 0; i < num; i++)
    {
        a[i] = 1;
    }

    out_stu(a,num);

    return 0;
}
