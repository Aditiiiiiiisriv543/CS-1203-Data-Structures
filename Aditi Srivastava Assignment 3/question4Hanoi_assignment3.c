#include<stdio.h>

/*Tower of Hanoi Logic: 
Base case is when n=1, we move directly from source to dest. 
Recursive case is when n>1, we move n-1 elements to temp peg, then we move n'th term to destination
Next step is that we do this recursively for n-1'th element, using source as temp peg in this case, and so on.*/

void Hanoi(int n, char source, char temp, char dest){
    //Establishing base case
    if(n==1){
        printf("Moved disk %d from %c to %c\n", n, source, dest);
        return;
    }
    else{
//Recursive case
        Hanoi(n - 1,source, dest, temp);
        printf("Move disk %d from %c to %c\n", n, source, dest);
        Hanoi(n - 1, temp, source, dest);
    }
}

int main() {
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);

    Hanoi(num, 'A', 'B', 'C');

    return 0;
}
