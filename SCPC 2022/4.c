#include <stdio.h>
#include <string.h>
int Answer;

int checkContain(int *x, int *y){
    int xLength = length(x);
    int yLength = length(y);
    int trial = xLength - yLength;
    char temp[1000000];
    for(int i = 0; i < trial; i++){
        // temp 에 x 일부 담기
        for(int j = 0; j < yLength; j++)
            temp[j] = x[i + j];
        if(!strcmp(&temp, &y)){
            return 1;
        }
    }
    return 0;
}

int length(int *x){
    int i = 0;
    while (x[i] != '\0')
        i ++;
    return i;
}

int main(void)
{
	int T, test_case;
    // 나중에 지우기
	// freopen("input.txt", "r", stdin);

	// setbuf(stdout, NULL);

	scanf("%d", &T);
    int n, m;
    char x[1000000], y[1000000];
	for(test_case = 0; test_case < T; test_case++)
	{
        Answer = 0;
        scanf(" %d, %d", &n, &m);
        getchar();
        
        scanf("%s", &x);
        getchar();
        scanf("%s", &y);
        getchar();

        if(checkContain(&x, &y))
            Answer = 1;
        
		printf("Case #%d\n", test_case+1);
	    if(Answer)
            printf("YES");
        else
            printf("NO");
        // printf("%d\n", Answer);
        
	}

	return 0;//Your program should return 0 on normal termination.
}