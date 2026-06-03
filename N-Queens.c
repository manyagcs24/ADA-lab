#include <stdio.h>
#include <stdbool.h>
#define MAX 20
int N;
int board[MAX][MAX];
bool isSafe(int row,int col){
    for(int i=0;i<row;i++){
        if(board[i][col])return false;
        if(col-(row-i)>=0&&board[i][col-(row-i)])return false;
        if(col+(row-i)<N&&board[i][col+(row-i)])return false;
    }
    return true;
}
void printBoard(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)printf("%c ",board[i][j]?'Q':'.');
        printf("\n");
    }
    printf("\n");
}
void solve(int row){
    if(row==N){
        printBoard();
        return;
    }
    for(int col=0;col<N;col++){
        if(isSafe(row,col)){
            board[row][col]=1;
            solve(row+1);
            board[row][col]=0;
        }
    }
}
int main(){
    printf("Enter the size of the board (N): ");
    scanf("%d",&N);
    if(N>MAX||N<1){
        printf("Invalid board size. Please enter between 1 and %d.\n",MAX);
        return 1;
    }
    solve(0);
    return 0;
}
