# 벽 부수고 이동하기
- 백준 2206

## 생각
1. 일단 bfs를 사용하고, breakCount를 1로 하고 breakCount가 남아있으면 board에서 1이 있는곳도 queue에 넣던지 해서 ㄱㄱ. 그리고 breakCount 0으로 하기.
-> visited[][] 만들려면 dfs가 나음
-> 이렇게 하니까 TLE남. bfs가 맞는듯.
2. bfs를 이용한 방법
- queue에 다음에 방문할 점과 현재까지의 거리, visited배열을 저장해야 함.
-> 근데 이렇게 하면 memory exeeded 뜰수도..
- 꼭 모든 경로를 다 가야하나? 1000*1000 이면 전체 다 bfs로 탐색하는거 자체가 부담인데..
- 게시판에 visited[] 저장 안해도 bfs는 어차피 최단경로 찾을거니까 상관없다는 말이 있었음 -> visited[] 저장 안 한다면??

## test case

5 5
01000
11010
01010
01010
00010
ans: 9