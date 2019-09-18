#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <cstdio>
using namespace std;

struct Node {
	int val;
	Node* left;
	Node* right;
    Node(int val_):val(val_), left(NULL), right(NULL) {}
};

bool isNum (string str) {
	stringstream sin(str);
	int d;
	char c;
	if (!(sin >> d))
	  return false;
	if (sin >> c)
	  return false;

	return true;
}

int s2int ( const string& s) {
    stringstream ss;
	ss<<s;
	int ret;
	ss>>ret;
	return ret;
}

vector<string> split(const string& s, const string& delmiter) {
	vector<string> result;
	typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size()){
        int flag = 0;
        while(i != s.size() && flag == 0){
            flag = 1;
            for(string_size x = 0; x < delmiter.size(); ++x) {
                if(s[i] == delmiter[x]){
                	++i;
                    flag = 0;
                    break;
                }
            }
        }

        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0){
            for (string_size x = 0; x < delmiter.size(); ++x) {
			    if(s[j] == delmiter[x]){
                    flag = 1;
                    break;
                }
			}
            if(flag == 0)
				++j;
        }//end while
        if(i != j){
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}

Node* createBTree (vector<string>& v, int index) {
	Node* node = NULL;

	if (index < v.size()) {
		if (isNum(v[index]) == false) {
			return NULL;
		}
		node = new Node(s2int(v[index]));
		node->left = createBTree(v, index * 2 + 1);
		node->right = createBTree(v, index * 2 + 2);
		return node;
	}
	return node;
}


long long sum[1000005];
long long num[1000005];
int maxl = 0;

void dfs(Node *u, int h){
    sum[h] += u->val;
    num[h]++;
    maxl = max(maxl,h);
    if(u->left != NULL) dfs(u->left, h+1);
    if(u->right != NULL) dfs(u->right, h+1);
}

int levelOrder(Node* root) {
//ÇëÍê³É´úÂë
    int ans = 0;
    dfs(root,1);
    long maxs = 0, maxx = 0;
    for(int i = 1;i<=maxl;i++){
        if(sum[i]*maxx >= maxs*num[i]){
            maxx = num[i];
            maxs = sum[i];
            ans = i;
        }
    }

    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif // ONLINE_JUDGE
    string inString;
	int len = 0;
    cin>>inString;
	//vector<string> res = split(inString, " ");
	vector<string> res;
    if (isNum(inString)) {
		len = s2int(inString);
	}
	for (int i = 0; i < len; i++) {
		cin>>inString;
		res.push_back(inString);
	}
	/*
	for (int i = 0; i < res.size(); i++) {
	    cout<<res[i]<<"	";
	}
	cout<<endl;
	*/
    Node* root = createBTree(res,0);

    int ret = levelOrder(root);
    cout<<ret<<endl;
    return 0;
}
