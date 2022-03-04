#define _CRT_SECURE_NO_WARNINGS
/* To Be or Not To Be !!
Allah_Almost3aan
Make it happens :) */
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using ll = long long;
const ll OO = 1e18;
#define ed '\n'
#define F first
#define S second
#define sz(a)a.size()
#define vi vector<int>
#define pii pair<int,int>
int di[8] = { 0, 0, 1, -1, -1, 1, -1, 1 };
int dj[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
#define all(c) c.begin(),c.end()
#define RT(v)return cout<<v<<ed,0
#define rall(s)s.rbegin(),s.rend()
#define fr(i,l,n)for(int i=l;i<n;i++)
#define stpr(n)fixed<<setprecision(n)
#define show(x)cout<<"> "<<(#x)<<" = "<<x<<ed
#define reset(mem,val)memset(mem,val,sizeof mem)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
string ys = "YES", no = "NO"; const int N = 1 << 20;
#define NOVALUE -1

struct Node{
	int val;
	Node* left;
	Node* right;
	Node(){
		this->val = NOVALUE;
		this->left = NULL;
		this->right = NULL;
	}
};
bool specified;
Node* root;
int nodes, inputNodes;
string path;
void insert(Node* root, int &key, int pos){
	if (pos == path.size()){
		if (root->val != NOVALUE)
			specified = false;
		root->val = key;
	}

	else if (path[pos] == 'L'){
		if (root->left == NULL){
			nodes++;
			Node* node = new Node;
			root->left = node;
			insert(node, key, pos + 1);
		}
		else insert(root->left, key, pos + 1);
	}
	else {
		if (root->right == NULL){
			nodes++;
			Node* node = new Node;
			root->right = node;
			insert(node, key, pos + 1);
		}
		else insert(root->right, key, pos + 1);
	}
}

void clear(Node* root){
	if (root == NULL)return;
	clear(root->left);
	clear(root->right);
	delete root;
}


void bfs(){
	queue< Node* > q;
	q.push(root);
	vector < int > ans;
	Node* node;
	while (!q.empty()){
		node = q.front(); q.pop();
		ans.push_back(node->val);
		if (node->left != NULL) q.push(node->left);
		if (node->right != NULL) q.push(node->right);
	}

	for (int i = 0; i < (int)ans.size() - 1; i++)
		printf("%d ", ans[i]);
	printf("%d\n", ans[ans.size() - 1]);
}
void solve(){
	if (specified == false || inputNodes != nodes)puts("not complete");
	else bfs();

}
void init(){
	clear(root);
	root = new Node;
	nodes = 1;
	specified = true;
	inputNodes = 0;
}

int main(){
	string s;
	int val;

	init();
	while (cin >> s){
		if (s == "()"){
			solve();
			init();
		}
		else{
			inputNodes++;
			stringstream ss;
			for (int i = 0; i < s.size(); i++)
			if (s[i] == '(' || s[i] == ')' || s[i] == ',') s[i] = ' ';
			ss << s;
			ss >> val;
			path = "";
			ss >> path;
			insert(root, val, 0);
		}
	}
	return 0;
}
//????????????????????????????????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!