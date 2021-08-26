#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 5;
    int m = 8;
    int k = 3;

    int src[] = { 2,4,5,4,6 };
 
    vector<int> v(src, src + sizeof(src) / sizeof(int));

    sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
    
    int first = v[n - 1]; // 가장 큰 수
    int second = v[n - 2]; // 두 번째로 큰 수

    // 가장 큰 수가 더해지는 횟수 계산
    int cnt = (m / (k + 1)) * k + m % (k + 1);

    int result = 0;
    result += cnt * first; // 가장 큰 수 더하기
    result += (m - cnt) * second; // 두 번째로 큰 수 더하기

    cout << result << '\n'; // 최종 답안 출력
}
