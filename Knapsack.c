#include <stdio.h>
struct Item{int weight;int value;};
int main(){
    int n,capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);
    struct Item items[n];
    for(int i=0;i<n;i++){
        printf("Enter weight and value of item %d: ",i+1);
        scanf("%d %d",&items[i].weight,&items[i].value);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d",&capacity);
    double ratio[n];
    for(int i=0;i<n;i++)ratio[i]=(double)items[i].value/items[i].weight;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                double tempR=ratio[i];ratio[i]=ratio[j];ratio[j]=tempR;
                struct Item temp=items[i];items[i]=items[j];items[j]=temp;
            }
        }
    }
    double maxValue=0.0;int remaining=capacity;
    for(int i=0;i<n;i++){
        if(items[i].weight<=remaining){
            remaining-=items[i].weight;
            maxValue+=items[i].value;
        }else{
            maxValue+=ratio[i]*remaining;
            break;
        }
    }
    printf("Maximum value in Knapsack = %.2f\n",maxValue);
    return 0;
}
