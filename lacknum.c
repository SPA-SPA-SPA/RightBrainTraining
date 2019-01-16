/*寻找幸运数字训练：数字随机排列*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_STAGE 10            // 挑战次数
#define swap(type, x, y) do{type t = x; x = y; y = t;}while(0)          // 函数宏！！！

int main(int argc, char const *argv[])
{
    int i, j, stage, dd;
    int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a[8];
    double jikan;                       // 时间
    clock_t start, end;                 // 开始时钟数和结束时钟数

    srand(time(NULL));                  // 设定随机数种子

    printf("请输入1~9中缺少的数字。输入错误就不会出现下一题，但计时仍继续。一共10题。\n");
    do
    {
        printf("开始？（Yes...1/No...0）");
        scanf("%d", &dd);
        if(dd == 0)
            return 0;
    } while (dd != 1);

    start = clock();
    
    for( stage = 0; stage < MAX_STAGE; stage++)
    {
        int x = rand() % 9;             // 生成随机数0~8
        int no;                         // 读取的数值

        i = j = 0;
        
        while(i < 9){                   // 复制时跳过dgt[x]
            if(i != x)
                a[j++] = dgt[i];
            i++;
        }
        
        for( i = 7; i > 0; i--)         // 重新排列数组a
        {
            int j = rand() % (i + 1);
            if(i != j)
                swap(int, a[i], a[j]);
        }
        for(i = 0; i < 8; i++)          // 显示所有元素
            printf("%d", a[i]);
        printf(":");
        
        do
        {
            scanf("%d", &no);
        } while (no != dgt[x]);         // 循环到玩家输入正确答案为止
    }
    end = clock();

    jikan = (double)(end - start) / CLOCKS_PER_SEC;

    printf("用时%.1f秒。\n", jikan);
    if(jikan > 25.0)
        printf("反应太慢了。\n");
    else if(jikan > 20.0)
        printf("反应有点慢呀。\n");
    else if(jikan > 17.0)
        printf("反应还行吧。\n");
    else
        printf("反应真快啊。\n");
    return 0;
}
