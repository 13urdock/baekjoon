#include <stdio.h>

int n, temp, post[100001], in[100001];

void pre(int ps, int pd, int is, int id){
    int root = post[pd];
    printf("%d ", root);
    int lcnt = in[root] - is - 1;
    if(in[root] != is) pre(ps, ps + lcnt, is, in[root] - 1);
    if(in[root] != id) pre(ps + lcnt + 1, pd - 1, in[root] + 1, id);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        in[temp] = i;
    }
    for(int i = 0; i < n; i++)scanf("%d", &post[i]);
    pre(0, n - 1, 0, n - 1);
}