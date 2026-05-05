//2026.05.05 fail
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isUnique(unordered_map<string, bool> m, unordered_map<int, bool> um, vector<vector<string>> relation, int size) {
    for (int i=0; i<size; i++) {
        string str;
        for (int j=1; j<relation[0].size(); j++) {
            if (!um[j]) continue;
            str += relation[i][j];
        }
        if (m[str]) return false;
        m[str] = true;
    }

    return true;
}

int solution(vector<vector<string>> relation) {
    int answer = 1;
    int size = relation.size();
    unordered_map<string, bool> m;
    unordered_map<char, bool> min;
    vector<string> key = {"1", "2", "3", "12", "13", "23", "123"};

    for (string k : key) {
        bool check = false;
        for (int i=0; i<k.length(); i++) {
            if (min[k[i]]) {
                check = true;
                break;
            }
        }

        if (check) continue;

        unordered_map<int, bool> um;
        for (int i=0; i<k.length(); i++) {
            um[k[i] - '0'] = true;
        }

        if (isUnique(m, um, relation, size)) {
            answer += 1;
            for (int i=0; i<k.length(); i++) {
                min[k[i]] = true;
            }
        }
    }

    return answer;
}

/*
1
2
3
12
13
23
123
*/
