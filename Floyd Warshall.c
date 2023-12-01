#include<stdio.h>
#include<stdlib.h>
#define min(a , b) a < b ? a : b;
const int inf = 1<<20;

int main(){
	int node , edge;
	scanf("%d %d", &node , &edge);
	int weight[node][node];
	for(int i = 0 ; i < node;i++){
		for(int j = 0 ; j < node;j++){
			i == j ? weight[i][j] = 0 : weight[i][j] = inf;
		}
	}

	for(int i = 0 ; i < edge;i++){
		int u , v , w;
		scanf("%d %d %d", &u , &v , &w);
		weight[u][v] = w;
		//weight[v][u] = inf;
	}

	for(int k = 1 ; k < node-1;k++){
		for(int i = 0 ; i < node;i++){
			for(int j = 0 ; j < node;j++){
				weight[i][j] = min(weight[i][j] , weight[i][k] + weight[k][j]);
			}
		}
	}

	int source;
	scanf("%d" , &source);
	for(int i = 0 ; i < node;i++){
		printf("Shortest distance from %d to %d is = %d\n", source , i , weight[source][i] == inf ? 1000000000 : weight[source][i]);
	}

	return 0;
}
