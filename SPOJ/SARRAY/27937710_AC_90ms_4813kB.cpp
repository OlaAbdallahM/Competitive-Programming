#include <cstdio>
#include <cstring>
 
using namespace std;
 
#define MAX_LEN 100000
#define ALPH_SIZE 123
 
char A[MAX_LEN + 1];
int N, pos[MAX_LEN], rnk[MAX_LEN];
int cont[MAX_LEN], nxt[MAX_LEN];
bool bh[MAX_LEN + 1], b2h[MAX_LEN + 1];
 
void build_suffix_array(){
	N = strlen(A);
 
	memset(cont, 0, sizeof(cont));
 
	for (int i = 0; i<N; ++i) ++cont[A[i]];
	for (int i = 1; i<ALPH_SIZE; ++i) cont[i] += cont[i - 1];
	for (int i = 0; i<N; ++i) pos[--cont[A[i]]] = i;
 
	for (int i = 0; i<N; ++i){
		bh[i] = (i == 0 || A[pos[i]] != A[pos[i - 1]]);
		b2h[i] = false;
	}
 
	for (int H = 1; H<N; H <<= 1){
		int buckets = 0;
 
		for (int i = 0, j; i<N; i = j){
			j = i + 1;
 
			while (j<N && !bh[j]) ++j;
			nxt[i] = j;
			++buckets;
		}
 
		if (buckets == N) break;
 
		for (int i = 0; i<N; i = nxt[i]){
			cont[i] = 0;
			for (int j = i; j<nxt[i]; ++j)
				rnk[pos[j]] = i;
		}
 
		++cont[rnk[N - H]];
		b2h[rnk[N - H]] = true;
 
		for (int i = 0; i<N; i = nxt[i]){
			for (int j = i; j<nxt[i]; ++j){
				int s = pos[j] - H;
 
				if (s >= 0){
					int head = rnk[s];
					rnk[s] = head + cont[head];
					++cont[head];
					b2h[rnk[s]] = true;
				}
			}
 
			for (int j = i; j<nxt[i]; ++j){
				int s = pos[j] - H;
 
				if (s >= 0 && b2h[rnk[s]]){
					for (int k = rnk[s] + 1; !bh[k] && b2h[k]; ++k)
						b2h[k] = false;
				}
			}
		}
 
		for (int i = 0; i<N; ++i){
			pos[rnk[i]] = i;
			bh[i] |= b2h[i];
		}
	}
}
 
int main(){
	scanf("%s", A);
	build_suffix_array();
 
	for (int i = 0; i<N; ++i)
		printf("%d\n", pos[i]);
 
	return 0;
}