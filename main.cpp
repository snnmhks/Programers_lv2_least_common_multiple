#include <string>
#include <vector>

using namespace std;

// 2개의 숫자에 대한 최소공배수를 구해주는 함수를 만들고 순차적으로 이 함수를 적용시켜 문제를 풀었다.
// 최소공배수를 구해주는 함수는 큰 값에 1 2 3 4 5..... 점점 늘어나는 수를 곱해주고 곱할 때 마다
// 작은 값으로 나머지를 구하여 0이 된다면 그 때가 최소 공배수 이므로 이 수를 리턴해준다.
// 여러개의 수에 의한 최소공배수는 순차적으로 2개씩 비교하면서 최소공배수를 구해도 결과가 같다.
// 예로 1 2 3 4 5 6이 있다면 1과 2의 최소공배수 = 2 이후 구해진 2와 3의 최소 공배수 6 이후 구해진
// 6과 4의 최소 공배수 12 .... 이런식으로 하면 된다.

int MinimumNum(int x, int y)
{
    int maxNum = 0;
    int minNum = 0;
    if (x > y)
    {
        maxNum = x;
        minNum = y;
    }
    else if (y > x)
    {
        maxNum = y;
        minNum = x;
    }
    else if (x == y)
    {
        return x;
    }
    
    int tmp = maxNum;
    for (int i = 1; tmp%minNum != 0; i++)
    {
        tmp = maxNum*i;
    }
    return tmp;
}

int solution(vector<int> arr) {
    int answer = 0;
    
    for (int i = 1; i < arr.size(); i++)
    {
        arr[i] = MinimumNum(arr[i-1], arr[i]);
    }
    answer = arr[arr.size()-1];
    
    return answer;
}
