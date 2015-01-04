/****************************************
  > File Name:     z1.c
  > Author:        guqiang
  > Mail:          544104926@qq.com
  > Created Time:  2014年10月01日 星期三 17时03分57秒
  > Function:      统计1～中的9
*****************************************/

#include<stdio.h>

int sum_9(int);
int count(int);

int main()
{
	int end_nu;

	printf("please Enter the end number:\n");
	scanf("%d",&end_nu);

    printf("%d\n",sum_9(end_nu));      //统计结果并显示

	return 0;
}


/**************************************
 * Name:           int sum_9(int end_nu)
 * Description:    统计9的个数
 * calls:          int count(int nu)
 * called by:      main
 * input:          end_nu
 * output:         i
 * return:         result
**************************************/
int sum_9(int end_nu)
{
	int i;
    int result;                        //结果

    result = 0;

	for(i = end_nu; i >= 1; i--)
	{   
		result += count(i);            
	}

	return result;
}

/**************************************
 * Name:           int count(int nu)
 * Description:    统计m中的9
 * calls:          no
 * called by:      int sum_9(int end_nu)
 * input:          nu
 * output:         no
 * return:         result
**************************************/
int count(int nu)
{
	int i;
    int result;

    result = 0;

	for(i = 0; i <= 10; i++)           //ep:99中有两个9
	{
		if(nu % 10 == 9 || nu == 9)
		{
			result++;
		}

		if(nu == 0)
		{
			break;
		}

		nu = nu / 10;
	}

	return result;
}
