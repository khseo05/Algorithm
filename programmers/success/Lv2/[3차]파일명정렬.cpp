//2026.06.26 success
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    string lower_name;
    string name;
    int num;

    bool operator <(const Node& other)const {
        if (lower_name == other.lower_name) return num < other.num;
        return lower_name < other.lower_name;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<Node> v;
    for (string file : files) {
        string number = "";
        string head = "";
        bool header = true;
        for (char x : file) {
            if (isdigit(x)) {
                number += x;
                header = false;
            } else {
                if (header) head += x;
                else break;
            }
        }
        string lower_name = head;
        for (auto& x : lower_name) x = tolower(x);
        v.push_back({lower_name, file, stoi(number)});
    }

    stable_sort(v.begin(), v.end());

    for (auto& node : v) answer.push_back(node.name);

    return answer;
}
