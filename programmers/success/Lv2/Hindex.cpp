//2026.05.28 success
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    for (int i=0; i<citations.size(); i++)  {
        int h = citations.size()-i;
        if  (citations[i] >= h) return h;
    }
    
    return 0;
}