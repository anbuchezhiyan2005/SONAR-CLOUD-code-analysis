/*#include<stdio.h>
#include<stdlib.h>
int check(int* p, int n,int size){
	int flag = 0;
	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if(*(p + i) + *(p + j) == n){
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1){
		printf("YES\n");
	}
	else
		printf("NO");
}

void input(int* p,int n){
	for(int i = 0; i < n; i++){
		scanf("%d",(p + i));
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int num;
	scanf("%d",&num);
	int *p = (int*) malloc(size * sizeof(int));
	input(p,size);
	check(p, num, size);

	free(p);
	return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>

void input(int* p, int n){
	for(int i = 0; i < n; i++){
	scanf("%d",(p + i));
	}
}

int find_min(int* p ,int n){
	int min = *p;
	for(int i = 0; i < n; i++){
		if(*(p + i) < min){
			min = *(p + i);
		}
	}
	return min;
}

void remove_min(int* p, int n, int min) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == min) {
            for (int j = i; j < n - 1; j++) {
                *(p + j) = *(p + j + 1);
            }
            n--;
            break;
        }
    }
}

int find_max(int* p, int n){
	int max = *p;
	for(int i = 0; i < n; i++){
		if(*(p + i) > max){
			max = *(p + i);
		}
	}
	return max;
}

void remove_max(int* p, int n, int max) {
    for (int i = 0; i < n; i++) {
        if (*(p + i) == max) {
            for (int j = i; j < n - 1; j++) {
                *(p + j) = *(p + j + 1);
            }
            n--;
            break;
        }
    }
}


void array_M(int* p ,int m ,int* M){
	for(int i = 0; i < m; i++){
		*(M + i) = *(p + i);
	}
	printf("array M: \n");
	for(int i = 0; i < m; i++){
		printf("%d ",*(M + i));
	}
}

void sort(int *M, int m) {
    int temp;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (*(M + j) > *(M + j + 1)) {
                temp = *(M + j);
                *(M + j) = *(M + j + 1);
                *(M + j + 1) = temp;
            }
        }
    }
}

int output(int* M,int m){
	int ans = *(M + m - 1) - *M;
	return ans;
}

int main(){
	int n,m;
	printf("enther the no. of chocolate bags: ");
	scanf("%d",&n);
	printf("enter the number of children: ");
	scanf("%d",&m);

	int* p = (int*)malloc(n * sizeof(int));

	input(p,n);

	int min = find_min(p,n);
	remove_min(p,n,min);
	n--;

	int max = find_max(p,n);
	remove_max(p,n,max);
	n--;

	int* M = (int*)malloc(m * sizeof(int));
	array_M(p,m,M);

	sort(M,m);
	
	printf("\nOUTPUT: %d",output(M,m));

free(p);
free(M);
return 0;
}