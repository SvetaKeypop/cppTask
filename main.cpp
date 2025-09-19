#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void First(){
    string s;
    stack<char> st;

    cin>>s;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else {
            if (st.empty()){
                cout<<"false"<<endl;
                return;
            }
            char top = st.top();
            st.pop();
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                cout<<"false"<<endl;
                return;
            }
        }
    }
    if(st.empty()){
        cout<<"true"<<endl;
        return;
    }
    cout<<"false"<<endl;
}

void Second(){
    int m=3, n=3;
    vector<int> nums1 = {2,5,6,0,0,0};
    vector<int> nums2 = {1,3,6};
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    for (int x : nums1){
        cout << x << " ";
    }
    cout<<endl;
}

void Third(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int minPrice = 100000;
    int maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    cout<<maxProfit<<endl;
}

void Fourth(){
    string s, t;
    cin>>s>>t;
    if (s.size() != t.size()){
        cout<<"false"<<endl;
        return;
    }
    vector<int> cnt(26, 0);
    for (char c : s){
        cnt[c - 'a']++;
    }
    for (char c : t){
        cnt[c - 'a']--;
    }
    for(int x : cnt){
        if(x!=0){
            cout<<"false"<<endl;
            return;
        }
    }
    cout<<"true"<<endl;
}

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};


void Fifth(){
    RecentCounter counter;

    cout << counter.ping(1) << endl;
    cout << counter.ping(100) << endl;
    cout << counter.ping(3001) << endl;
    cout << counter.ping(3002) << endl;
}

int main()
{
    First();
    Second();
    Third();
    Fourth();
    Fifth();
}
