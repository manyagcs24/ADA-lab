#include <stdio.h>
#define LEFT 0
#define RIGHT 1
void print(int a[], int dir[], int n) {
    for(int i = 0; i < n; i++) {
        if(dir[a[i]] == LEFT)
            printf("%d<- ", a[i]);
        else
            printf("%d-> ", a[i]);
    }
    printf("\n");
}
int getMobile(int a[], int dir[], int n) {
    int mobile = 0;
    for(int i = 0; i < n; i++) {
        if(dir[a[i]] == LEFT && i > 0) {
            if(a[i] > a[i-1] && a[i] > mobile)
                mobile = a[i];
        }
        if(dir[a[i]] == RIGHT && i < n-1) {
            if(a[i] > a[i+1] && a[i] > mobile)
                mobile = a[i];
        }
    }
    return mobile;
}
int findPos(int a[], int n, int mobile) {
    for(int i = 0; i < n; i++) {
        if(a[i] == mobile)
            return i;
    }
    return -1;
}
void johnsonTrotter(int n) {
    int a[n], dir[n+1];
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i+1] = LEFT;
    }
    print(a, dir, n);
    while(1) {
        int mobile = getMobile(a, dir, n);
        if(mobile == 0)
            break;
        int pos = findPos(a, n, mobile);
        if(dir[mobile] == LEFT) {
            int temp = a[pos];
            a[pos] = a[pos-1];
            a[pos-1] = temp;
            pos = pos - 1;
        } else {
            int temp = a[pos];
            a[pos] = a[pos+1];
            a[pos+1] = temp;
            pos = pos + 1;
          }

        for(int i = 1; i <= n; i++) {
            if(i > mobile) {
                dir[i] = !dir[i];
            }
        }
        print(a, dir, n);
    }
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
