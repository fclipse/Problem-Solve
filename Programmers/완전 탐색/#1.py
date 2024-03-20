def solution(answers):
    answer = []    
    person = [[1, 2, 3, 4, 5], 
              [2, 1, 2, 3, 2, 4, 2, 5], 
              [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]]
    
    score = [0, 0, 0]
    for i in range(3):
        for j in range(len(answers)):
            if answers[j] == person[i][j % len(person[i])]:
                score[i] += 1
    
    high = max(score)
    
    if score.count(high) > 1:
        for i in range(3):
            if score[i] == high:
                answer.append(i+1)
    else:
        answer.append(score.index(high) + 1)
    return answer