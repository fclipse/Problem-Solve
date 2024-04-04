#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);

using namespace std;

/**
 * @brief
 * 구슬판에 파랑, 빨강 구슬이 있다.
 * 10번 내로 기울여서 파랑 구슬을 빠뜨리지 않고 빨강 구슬을 구멍으로 빠뜨릴 수 있는지 판별하는 문제.
 * BFS 및 백트래킹 사용
 * @return int
 */

class Position
{
public:
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}

    // Getter for x
    // int x() const
    // {
    //     return x;
    // }

    // Setter for x
    void setX(int x)
    {
        this->x = x;
    }

    // Getter for y
    // int y() const
    // {
    //     return y;
    // }

    // Setter for y
    void setY(int y)
    {
        this->y = y;
    }
};

// functions
int step(vector<vector<char>>, int, Position, Position);
vector<vector<char>> move(vector<vector<char>>, char, Position &, Position &);

// global variables
bool isSuccess = false;

int main()
{
    fastio;
    int n, m;
    cin >> n >> m;
    Position red, blue;
    vector<vector<char>> board(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        string str;
        getline(cin, str);
        for (int j = 0; j < m; j++)
        {
            board[i][j] = str[m];
            // red, blue 위치 초기화
            if (str[m] == 'R')
                red = Position(j, i);
            if (str[m] == 'B')
                blue = Position(j, i);
        }
    }

    int answer = -1;
    bool isMoved = false, successWhileMoving = false;
    answer = step(board, 10, red, blue);
    cout << answer;

    return 0;
}

// step 재귀함수로 실행해서 백트래킹하는 함수
int step(vector<vector<char>> board, int cnt, Position red, Position blue)
{
    // 실패시
    if (cnt == 0)
        return false;
    bool isMoved = true;
    // 상
}

// 방향 받아서 해당 방향으로 map 움직이는 함수
vector<vector<char>> move(vector<vector<char>> board, char direction, bool &isMoved, Position &red, Position &blue)
{
    // 움직인 적이 없으면 더 이상 움직일 수 없다고 판단
    bool isMoved = false;
    // 방향별로 움직여야 할 x, y변화량 저장
    map<char, Position> delta = {
        {'L', Position(-1, 0)},
        {'R', Position(0, 1)},
        {'U', Position(0, 1)},
        {'D', Position(0, -1)},
    };

    while (true)
    {
    }
}

// target에 해당하는 문자의 위치를 찾아 반환하는 함수
// Position findTargetPosition(vector<vector<char>> board, char target)
// {
//     for (int i = 0; i < board.size(); i++)
//     {
//         for (int j = 0; j < board[i].size(); j++)
//         {
//             if (board[i][j] == target)
//             {
//                 return Position(j, i);
//             }
//         }
//     }
//     return Position(-1, -1);
// }