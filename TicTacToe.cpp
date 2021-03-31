/*变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!
 *变量名要用有意义的名字!!!*/

/*待开发：
 *1.图形界面
 *2.人机对战功能*/

/*verson 1.0.3，加入棋盘重复检测功能
 *time:2021-3-21 12:36:47*/

/*verson 1.0.4,修复棋盘重复检测功能中的bug
 *time:2021-3-27 10:11:45*/

/*verson 1.0.5,加入悔棋功能与判断非法输入问题
 *time:2021-3-30 16:27:22*/

#include <iostream>
using namespace std;

char block[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0,                                                      //用于计数落子位置
    num = 0,                                                    //用于计数落子的数量，若num>=9，则终止循环
    index = 1;                                                  //用于判断最近一次落子是玩家1还是玩家2，index=-1则为玩家1，index=1则为玩家2
bool flag = false;                                              // 标记游戏是否jieshu
int positionOccupied[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10}; //存储已经落子的棋盘位置
string result = "Player1 and Player2 draw!";

int main()
{ //主函数
    system("cls");
    void board(), putChess(), checkWin(), undo(int num, int index);
    board();
    while (true)
    {
        putChess();
        system("cls");
        board();
        // undo(num,index);
        // system("cls");
        // board();
        checkWin();
        if (flag)
        {
            cout << result << endl;
            break;
        }
    }

    system("pause");
    return 0;
}

void board()
{ //面板显示函数
    cout << "\tTic Tac Toe" << endl;
    cout << '\n'
         << endl;
    cout << "Player1 (X) - Player2 (O)" << endl;
    cout << '\n'
         << endl;
    string a = "_____|_____|_____",
           b = "     |     |     ";
    int i = 0;
    while (i < 6)
    {
        cout << "  " << block[i] << "  |  " << block[i + 1] << "  |  " << block[i + 2] << "  " << endl;
        cout << a << '\n'
             << b << endl;
        i += 3;
    }
    cout << "  " << block[6] << "  |  " << block[7] << "  |  " << block[8] << "  " << endl;
    cout << '\n'
         << endl;
}

void putChess()
{ //落子函数
    int ifOccupied(int i, char chess);
    void undo(int num, int index, int i), board();
    char chess = 'X';
    if (index == 1)
    {
        cout << "Player1 enter a number:";
        cin >> i;
        if (i >= 1 && i <= 9)
        {
            ifOccupied(i, chess);
            undo(num, index, i);
            system("cls");
            board();
        }
        else
        {
            cout << "Please enter a proper number!" << endl;
            i = 0;
            putChess();
        }
    }
    if (index == -1)
    {
        chess = 'O';
        cout << "Player2 enter a number:";
        cin >> i;
        if (i >= 1 && i <= 9)       //判断输入是否合法，存在bug:无法判断字符型输入
        {
            ifOccupied(i, chess);
            undo(num, index, i);
            system("cls");
            board();
        }
        else
        {
            cout << "Please enter a proper number!" << endl;
            i = 0;
            putChess();
        }
    }
    index = -index;
    num += 1;
}

void checkWin()
{ //判断输赢函数
    bool line_1 = block[0] == block[1] && block[1] == block[2],
         line_2 = block[3] == block[4] && block[4] == block[5],
         line_3 = block[6] == block[7] && block[7] == block[8],
         row_1 = block[0] == block[3] && block[3] == block[6],
         row_2 = block[1] == block[4] && block[4] == block[7],
         row_3 = block[2] == block[5] && block[5] == block[8],
         slope_1 = block[0] == block[4] && block[4] == block[8],
         slope_2 = block[2] == block[4] && block[4] == block[6];
    if (line_1 || line_2 || line_3 || row_1 || row_2 || row_3 || slope_1 || slope_2)
    {
        if (index == 1)
        {
            result = "Player2 win the game!";
            flag = true;
        }
        if (index == -1)
        {
            result = "Player1 win the game!";
            flag = true;
        }
    }
    if (num >= 9)
    {
        flag = true;
    }
}

int ifOccupied(int i, char chess)
{ //判断是否重复函数
    void putChess(),
        board();
    int k = 0;
    for (k = 0; k < 9; k++)
    {
        if (positionOccupied[k] == (i))
        {
            cout << "This position has been occupied!" << endl;
            putChess();
            system("cls");
            board();
            index = -index;
            return EXIT_SUCCESS;
        }
    }
    positionOccupied[i - 1] = i;
    block[i - 1] = chess;
    return EXIT_SUCCESS;
}

void undo(int num, int index, int i)
{ // 悔棋函数
    void putChess();
    char answer;
    cout << "do you want to undo what you just did?(y/n)";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        block[i - 1] = 48 + i;
        cout << num << endl
             << index << endl
             << block << endl;
        num -= 1;       //将num和index重置到下棋前的状态
        index = -index;
        putChess();     //重新调用putChess()函数进行重新落子
    }
}