//2026.09.27 success
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct p {
    int number = 0;
    vector<int> seq; 
};

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, p> m;
    for (int i=0; i<want.size(); i++) {
        m[want[i]].number = number[i];
    }
    
    for (int i=0; i<discount.size(); i++) {
        m[discount[i]].seq.push_back(i);
    }
    
    for (int i=0; i+10<=discount.size(); i++) {
        bool b = false;
        for (auto x : want) {
            int count = 0;
            for (auto y : m[x].seq) {
                if (y > i+9) break;
                count++;
            }
            
            while (!m[x].seq.empty() && m[x].seq[0] <= i) m[x].seq.erase(m[x].seq.begin());
            
            if (count < m[x].number) {
                b = true;
            }
        }
        if (b) continue;
        answer++;
    }
    
    return answer;
}