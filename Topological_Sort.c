#include <stdio.h>
#define MAX 10
int main() {
    int n, i, j;
    int indegree[MAX] = {0};
    int graph[MAX][MAX];
    int order[MAX], count = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
    while(count < n) {
        int found = 0;
        for(i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                order[count++] = i;
                indegree[i] = -1;
                for(j = 0; j < n; j++) {
                    if(graph[i][j] == 1) {
                        indegree[j]--;


                    }
                }
                found = 1;
            }
        }
        if(!found) break;
    }
    if(count < n) {
        printf("No Topological Sequence (cycle detected)\n");
    } else {
        printf("Topological Order: ");
        for(i = 0; i < n; i++) {
            printf("%d ", order[i]);
        }
        printf("\n");
    }
    return 0;
}
