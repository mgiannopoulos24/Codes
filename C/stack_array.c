#include<stdio.h>
#include<stdlib.h>

int top = -1 , *arr , n;

void push(int x)
{
    if(top == ((n / 2) - 1)){
        int *new_arr = (int *)realloc(arr, (2 * n * sizeof(int)));
        arr = new_arr;
        n = n * 2;
        printf("Double Memory Allocated\n");
    }
    arr[++top] = x;
}

int pop()
{
    if(top == -1){
	    printf("Stack Empty\n");
        return -1;
    }

    else{
        int temp = arr[top];
        top--;
        return temp;
    }
}

void print()
{
    int i;

    for(i = 0 ; i <= top ; i++){
	printf("%d " , arr[i]);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <initial_size>\n", argv[0]);
        return 1;
    }

    int a, temp, y = 1;
    sscanf(argv[1], "%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (y == 1) {
        printf("Enter Your Choice:\n1. Push\n2. Pop\n3. Print\nChoice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("Enter Element: ");
                scanf("%d", &temp);
                push(temp);
                break;
            case 2:
                if (top == -1)
                    printf("Stack Empty\n");
                else
                    printf("Popped Element: %d\n", pop());
                break;
            case 3:
                print();
                printf("\n");
                break;
            default:
                printf("Invalid Choice\n");
        }

        printf("Do you want to continue? (1/0): ");
        scanf("%d", &y);
    }

    // Free allocated memory before program exit
    free(arr);

    return 0;
}
