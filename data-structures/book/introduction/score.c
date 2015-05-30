#include <stdio.h>
#include <stdlib.h>

typedef enum{A,B,C,D,E} SchoolName;
typedef enum{Female,Male} SexType;
typedef struct{
    char event[3];  //项目
    SexType sex;
    SchoolName school;
    int score;
} Component;
typedef struct{
    int MaleSum;		//男团总分
    int FemaleSum;	//女团总分
    int TotalSum;	//团体总分
} Sum;
Sum SumScore(SchoolName sn,Component a[],int n)
{
    Sum temp;
    temp.MaleSum=0;
    temp.FemaleSum=0;
    temp.TotalSum=0;
    int i;
    for(i=0;i<n;i++){
        if(a[i].school==sn){
            if(a[i].sex==Male) temp.MaleSum+=a[i].score;
            if(a[i].sex==Female) temp.FemaleSum+=a[i].score;
        }
    }
    temp.TotalSum=temp.MaleSum+temp.FemaleSum;
    return temp;
}

void printScore(Sum s) {
    printf("male: %d, female: %d, total: %d\n", s.MaleSum, s.FemaleSum, s.TotalSum);
}

int main(int argc, char *argv[]) {
    Component a[] = {
        {"tv", Female, A, 10},
        {"mv", Male, B, 20},
        {"hv", Male, C, 30},
        {"wv", Female, D, 40},
        {"yv", Male, E, 50}
    };
    
    printScore(SumScore(A, a, sizeof(a) / sizeof(Component)));
    printScore(SumScore(B, a, sizeof(a) / sizeof(Component)));
    printScore(SumScore(C, a, sizeof(a) / sizeof(Component)));
    printScore(SumScore(D, a, sizeof(a) / sizeof(Component)));
    printScore(SumScore(E, a, sizeof(a) / sizeof(Component)));
    
    return 0;
}
