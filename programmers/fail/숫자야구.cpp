//2026.05.03 fail
#include <string>
#include <vector>

using namespace std;

extern string submit(int);

string pad(int x) {
    string s = to_string(x);
    while (s.size() < 4) s = "0" + s;
    return s;
}

int solution(int n) {
    int num1[4];
    int idx = 0;

    for (int i = 0; i <= 9999; i += 1111) {
        if (submit(i) == "0S 0B") continue;

        if (idx == 4) break;
        num1[idx] = i / 1000;
        idx++;
    }

    int num2[4];
    num2[0] = num1[0]*1000 + num1[0]*100 + num1[1]*10 + num1[1];
    num2[1] = num1[1]*1000 + num1[1]*100 + num1[0]*10 + num1[0];
    num2[2] = num1[2]*1000 + num1[2]*100 + num1[3]*10 + num1[3];
    num2[3] = num1[3]*1000 + num1[3]*100 + num1[2]*10 + num1[2];

    vector<int> num3;

    for (int i = 0; i < 4; i++) {
        if (submit(num2[i]) == "0S 2B") continue;
        num3.push_back(num2[i]);
    }

    if (num3.size() < 2) return 0;

    string s1 = pad(num3[0]);
    string s2 = pad(num3[1]);

    int num4[2];

    num4[0] = (s1[0]-'0')*1000 + (s2[1]-'0')*100 + (s1[2]-'0')*10 + (s2[3]-'0');
    num4[1] = (s2[0]-'0')*1000 + (s1[1]-'0')*100 + (s2[2]-'0')*10 + (s1[3]-'0');

    for (int i = 0; i < 2; i++) {
        if (submit(num4[i]) == "4S 0B") {
            return num4[i];
        }
    }

    return 0;
}
