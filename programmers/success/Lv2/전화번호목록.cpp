//2026.05.27 success
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    int n = phone_book.size();
    sort(phone_book.begin(),  phone_book.end());

    for (int i=0; i<n-1; i++) {
        if (phone_book[i+1].substr(0, phone_book[i].length()) == phone_book[i]) return false;
    }

    return true;
}
