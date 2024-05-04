#include <bits/stdc++.h>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define SIZE 3000
using namespace std;

// structs
struct Point
{
    // point 좌표
    long long x, y;
    bool operator<(const Point &other) const
    {
        if (x == other.x)
        {
            return y < other.y;
        }
        return x < other.x;
    }
};

// 선분의 두 끝점을 저장
struct Segment
{
    Point p1, p2;
};

// globals
int parent[SIZE] = {0};
Segment lines[SIZE];
// bool isCrossing[SIZE][SIZE] = {0};
int _count[SIZE] = {0};

// functions
int ccw(Segment s, Point p);
bool isCrossed(Segment s1, Segment s2);
int find(int x);
bool _union(int x1, int x2);
int compare(Point p1, Point p2);
Point _min(Point p1, Point p2);
Point _max(Point p1, Point p2);

int main()
{
    fastio;
    int n;
    cin >> n;

    vector<int> parent(n);
    vector<int> rank(n, 1); // 이건 1로 초기화
    vector<Segment> lines(n);
    vector<vector<bool>> isCrossing(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
    }

    // solving
    int groupNum = 0;
    int maxGroupSize = 0;
    // parent[] init
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    // 1. n*n의 교차하는지 표를 만듦 - O(N^2)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == j)
                isCrossing[i][j] = 1;
            else
                isCrossing[j][i] = isCrossing[i][j] = isCrossed(lines[i], lines[j]);
        }
    }

    cout << "isCrossed[] : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << isCrossing[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // 2. 유니온 파인드로 그룹을 지음 - O(N^2logN)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        { // 자기 자신은 포함 x
            if (isCrossing[i][j])
            {
                _union(i, j);
            }
        }
    }

    // cout << endl;
    cout << "parent[] : ";
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " ";
    }

    // 3. 각 그룹을 방문하면서 각 그룹의 크기와 개수를 셈
    for (int i = 0; i < n; i++)
    {
        if (rank[i] > 0)
        {
            groupNum++;
            maxGroupSize = max(maxGroupSize, rank[i]);
        }
    }

    // output
    cout << groupNum << "\n"
         << maxGroupSize;
    return 0;
}

int ccw(Segment s, Point p)
{
    Point v1 = {s.p2.x - s.p1.x, s.p2.y - s.p1.y};
    Point v2 = {p.x - s.p2.x, p.y - s.p2.y};
    int result = v1.x * v2.y - v1.y * v2.x;
    if (result == 0)
        return 0;
    else
        return result > 0 ? 1 : 0;
}

bool isCrossed(Segment s1, Segment s2)
{
    bool result;
    int ccwResult[4] = {0};
    ccwResult[0] = ccw(s1, s2.p1);
    ccwResult[1] = ccw(s1, s2.p2);
    ccwResult[2] = ccw(s2, s1.p1);
    ccwResult[3] = ccw(s2, s1.p2);
    cout << "s1 - (" << s1.p1.x << ", " << s1.p1.y << ") - (" << s1.p2.x << ", " << s1.p2.y << ")\n";
    cout << "s2 - (" << s2.p1.x << ", " << s2.p1.y << ") - (" << s2.p2.x << ", " << s2.p2.y << ")\n";
    for (int i = 0; i < 4; i++)
        cout << ccwResult[i] << " ";
    cout << endl;
    if (ccwResult[0] == 0 && ccwResult[1] == 0)
    {
        if (min(s1.p1.x, s1.p2.x) <= max(s2.p1.x, s2.p2.x) && min(s2.p1.x, s2.p2.x) <= max(s1.p1.x, s1.p2.x))
            result = true;
        else
            result = false;
    }
    else
    {
        result = ccwResult[0] * ccwResult[1] <= 0 && ccwResult[2] * ccwResult[3] <= 0;
    }
    cout << "result - " << result << endl
         << endl;
    return result;
}

int find(int x, vector<int> &parent)
{
    if (parent[x] == x)
        return x;
    // 경로 압축 사용
    return parent[x] = find(parent[x]);
}

bool _union(int x1, int x2, vector<int> &parent, vector<int> &rank)
{
    int r1 = find(x1, parent), r2 = find(x2, parent);
    if (r1 == r2)
        return false;
    // parent[x1] = parent[x2] = min(r1, r2);    // ?
    if (rank[r1] >= rank[r2])
    {
        parent[r2] = r1;
        rank[r1] += rank[r2];
        rank[r2] = 0;
    }
    else
    {
        parent[r1] = r2;
        rank[r2] += rank[r1];
        rank[r1] = 0;
    }
    return true;
}

int compare(Point p1, Point p2)
{
    if (p1.x == p2.x)
    {
        if (p1.y == p2.y)
            return 0;
        else if (p1.y > p2.y)
            return 1;
        return -1;
    }
    if (p1.x == p2.x)
        return 0;
    else if (p1.x > p2.x)
        return 1;
    return -1;
}
Point _min(Point p1, Point p2)
{
    int result = compare(p1, p2);
    if (result >= 0)
        return p2;
    else
        return p1;
}
Point _max(Point p1, Point p2)
{
    int result = compare(p1, p2);
    if (result <= 0)
        return p2;
    else
        return p1;
}