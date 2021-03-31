/*������Ҫ�������������!!!
 *������Ҫ�������������!!!
 *������Ҫ�������������!!!*/

/*��������
 *1.ͼ�ν���
 *2.�˻���ս����*/

/*verson 1.0.3�����������ظ���⹦��
 *time:2021-3-21 12:36:47*/

/*verson 1.0.4,�޸������ظ���⹦���е�bug
 *time:2021-3-27 10:11:45*/

/*verson 1.0.5,������幦�����жϷǷ���������
 *time:2021-3-30 16:27:22*/

#include <iostream>
using namespace std;

char block[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int i = 0,                                                      //���ڼ�������λ��
    num = 0,                                                    //���ڼ������ӵ���������num>=9������ֹѭ��
    index = 1;                                                  //�����ж����һ�����������1�������2��index=-1��Ϊ���1��index=1��Ϊ���2
bool flag = false;                                              // �����Ϸ�Ƿ�jieshu
int positionOccupied[9] = {10, 10, 10, 10, 10, 10, 10, 10, 10}; //�洢�Ѿ����ӵ�����λ��
string result = "Player1 and Player2 draw!";

int main()
{ //������
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
{ //�����ʾ����
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
{ //���Ӻ���
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
        if (i >= 1 && i <= 9)       //�ж������Ƿ�Ϸ�������bug:�޷��ж��ַ�������
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
{ //�ж���Ӯ����
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
{ //�ж��Ƿ��ظ�����
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
{ // ���庯��
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
        num -= 1;       //��num��index���õ�����ǰ��״̬
        index = -index;
        putChess();     //���µ���putChess()����������������
    }
}