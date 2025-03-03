// 函数：检查（行、列、斜线）、输出、回溯
// 变量：二维数组代表皇后位置、二维数组正确排序的存放、计数器、检查、


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define N 8
int array_line[N];     // 检查列
int first[2 * N - 1];  // 主对角线
int second[2 * N - 1]; // 副对角线
FILE *file;
int count = 0;
int board[N][N] = {0};



/*函数声明
void guideline();
void backqueen(int board[N][N], int row);
int issafe(int row, int line);
void Printboard(int board[N][N]);
void errornum();
void finish();
void serval();
int nqueen(int n);
void Printboard_n(int **board, int n);
void backqueen_n(int **board, int row, int *array_line, int *first, int *second, int n);
void menu();
void Return();

*/




// 输入数据有误
void errornum()
{
    printf("          数据错误\n");
    printf("          程序将在三秒后返回菜单\n");
    Sleep(3000);
}




/// @brief
void Return()
{
    printf("          摁下回车键返回菜单\n");
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); // 清空输入缓冲区
    getchar(); // 等待用户输入一个回车
}

void guideline()
{
    printf("\n\n              八皇后问题的规则是在一个8x8的棋盘上放置八个皇后\n              使得任何两个皇后不能处于同一行,同一列或同一斜线上\n\n\n");
    Return();
}




// 解决八皇后问题
int issafe(int row, int line)
{
    if (array_line[line] == 1) 
        return 0;
    if (first[row - line + N - 1] == 1)
        return 0;
    if (second[row + line] == 1)
        return 0;
    return 1;
}




void Printboard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(file, "%3d", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}



void backqueen(int board[N][N], int row)
{
    if (row == N)
    {
        Printboard(board);
        count++;
        return;
    }
    int line;
    for (line = 0; line < N; line++)
    {
        if (issafe(row, line) == 1)
        {
            board[row][line] = 1;
            array_line[line] = 1;
            first[row - line + N - 1] = 1;
            second[row + line] = 1;    // 成功则放置
            backqueen(board, row + 1); // 跳转下一行
            board[row][line] = 0;      // 下一行失败后返回上一行
            array_line[line] = 0;
            first[row - line + N - 1] = 0;
            second[row + line] = 0;
        }
    }
}



void finish()
{
    file = fopen("display.txt", "w+");
    if (file == NULL)
    {
        printf("          打开文件错误");
        Return();
        return;
    }
    backqueen(board, 0);
    fclose(file);
    printf("          共有%d种解法\n", count);
    printf("          已经将所有答案写入display.txt中\n");
    printf("          三秒后将自动返回菜单");
    count=0;
    Sleep(3000);
    return;
}




// 以下代码解决n皇后问题

int issafe_n(int row, int line, int *array_line, int *first, int *second, int n)
{
    if (array_line[line] == 1)
        return 0;
    if (first[row - line + n - 1] == 1)
        return 0;
    if (second[row + line] == 1)
        return 0;
    return 1;
}



void Printboard_n(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(file, "%3d", board[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "\n");
}




void backqueen_n(int **board, int row, int *array_line, int *first, int *second, int n)
{
    if (row == n)
    {
        Printboard_n(board, n);
        count++;
        return;
    }
    for (int line = 0; line < n; line++)
    {
        if (issafe_n(row, line, array_line, first, second, n))
        {
            board[row][line] = 1;
            array_line[line] = 1;
            first[row - line + n - 1] = 1;
            second[row + line] = 1;
            backqueen_n(board, row + 1, array_line, first, second, n);
            board[row][line] = 0;
            array_line[line] = 0;
            first[row - line + n - 1] = 0;
            second[row + line] = 0;
        }
    }
}



int nqueen(int n)
{
    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
        memset(board[i], 0, n * sizeof(int));
    }

    int *array_line = (int *)malloc(n * sizeof(int));
    int *first = (int *)malloc((2 * n - 1) * sizeof(int));
    int *second = (int *)malloc((2 * n - 1) * sizeof(int));
    memset(array_line, 0, n * sizeof(int));
    memset(first, 0, (2 * n - 1) * sizeof(int));
    memset(second, 0, (2 * n - 1) * sizeof(int));

    file = fopen("another_display.txt", "w+");
    if (file == NULL)
    {
        printf("          打开文件错误\n");
        return 0;
    }
    count = 0;
    backqueen_n(board, 0, array_line, first, second, n);
    fclose(file);

    for (int i = 0; i < n; i++)
        free(board[i]);
    free(board);
    free(array_line);
    free(first);
    free(second);

    printf("          共有%d种解法\n", count);
    if(count!=0)
        printf("          已经将所有答案写入 another_display.txt 中\n");
    else{
        printf("          该问题无解\n");
    }
    count=0;
    Return();
    return 0;
}



void serval()
{
    int n;
    printf("          请输入你要解决的N皇后问题,N的值为:");
    if (scanf("%d", &n) != 1)
    {
        errornum();
        return;
    }
    while (getchar() != '\n')
        ;
    if (n > 9 || n < 3)
    {
        errornum();
        return;
    }
    nqueen(n);
}

int quit()
{
    printf("          正在关闭程序\n");
    Sleep(1500);
    return 0;
}
          


// 主菜单
void menu()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("          ***************************************************************************************************          \n");
    printf("          *\033[1;31m                                        八 皇 后 问 题                                           \033[0m*          \n");
    printf("          *                                        1. 所有解决方案                                          *          \n");
    printf("          *                                        2. 多皇后问题 (3-9)                                      *          \n");
    printf("          *                                        3. 游戏规则                                              *          \n");
    printf("          *                                        0. 退出程序                                              *          \n");
    printf("          *                                                                                                 *          \n");
    printf("          *                             提示: 在本问题中, 1 代表皇后, 0 代表空格                            *          \n");
    printf("          ***************************************************************************************************          \n");
    printf("          请输入您的选择：");
}



int main()
{
    int choice;
    do
    {
        menu();
        if (scanf("%d", &choice) != 1)
        {
            errornum();
            while (getchar() != '\n')
                ;
            continue;
        }
        switch (choice)
        {
        case 1:
            finish();
            break;
        case 2:
            serval();
            break;
        case 3:
            guideline();
            break;
        case 0:
            quit();
            break;
        default:
            errornum();
            break;
        }
    } while (choice != 0);
    return 0;
}