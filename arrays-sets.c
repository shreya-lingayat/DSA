#include <stdio.h>
int menu(void);
void accept_array(int A[],int B[]);
void display_array(int A[],int B[]);
void union_set(int A[],int B[]);
void intersection_set(int A[],int B[]);
void difference_set(int A[],int B[]);
void symmetric_difference(int A[],int B[]);
 


int main(void)
{
    int A[5];
    int B[5];
    int U[10];
    int C[10];
   
    int ch;
    
    do{
        ch=menu();
        switch(ch)
        {
            case 1:
            accept_array(A,B);
            break;

            case 2:
           display_array(A,B);
            break;

            case 3:
            union_set(A,B);
            break;

            case 4:
            intersection_set(A,B);
            break;

            case 5:
            difference_set(A,B);
            break;

            case 6:
             symmetric_difference(A,B);
            break;

            case 0:
            printf("Thank You");
            
        }

    }while(ch!=0);
    
}

    int menu(void)
    {
        int choice;
        do{
            printf("\n\n\t\tMenu ");
            printf("\n\t1.Accept Set A and B ");
            printf("\n\t2.Display Set A and B ");
            printf("\n\t3.Union of both sets : ");
            printf("\n\t4.Intersection of both sets : ");
            printf("\n\t5.Difference of both sets : ");
            printf("\n\t6.Symmetric difference of both sets : ");
            printf("\n\t0.Exit the Program ");
            printf("\n\tEnter Your choice => ");
            scanf("%d",&choice);


        }while(choice>7 || choice < 0);
     return choice;
    }

void accept_array(int A[],int B[])
{
    printf("Enter 5 elements in Set A:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("Enter 5 elements in Set B:");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &B[i]);
    }

}

void display_array(int A[],int B[])
{
 
    printf("Elements of Set A:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d   ", A[i]);
    }

    printf("\nElements of Set B:");
    for (int i = 0; i < 5; i++)
    {
        printf("%d   ", B[i]);
    }

}

void union_set(int A[],int B[])

{ 
    int U[10];
      int cnt = 0;
    int flag;

    for (int i = 0; i < 5; i++)
    {
        U[cnt] = A[i];
        cnt++;
    }

    
    for (int i = 0; i < 5; i++)
    {
        flag = 0;
        for (int j = 0; j < cnt; j++)
        {
            if (B[i] == U[j])
            {
                flag = 1;
                
                break;
            }
        }
        if (flag == 0)
        {
            U[cnt] = B[i];
            cnt++;
        }
    }
    printf("Elements in Union set U :");
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ", U[i]);
    }

}

void intersection_set (int A[],int B[])
{
    int C[10];
    int idx_c = 0;

    // intersection
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (A[i] == B[j])
            {
                C[idx_c] = A[i];
                idx_c++;
            }
        }
    }

    printf("Elements in intersection set A and B : ");
    for (int i = 0; i < idx_c; i++)
    {
        printf("%d ", C[i]);
    } 
}
void difference_set(int A[],int B[])
{     int A_B[10];
    int B_A[10];  
    int idx_ab = 0; // reset count
    int idx_ba = 0;

    // difference  A-B i.e A-interection OR INCLUDE THOSE NOT EQUAL TO b SET

    for (int i = 0; i < 5; i++)
    { int found =0;
        for (int j = 0; j < 5; j++)
        {  
            if (A[i] == B[j])//not equal to is confusing fo use found
            { found=1;
                j=5+1;
                
            }
        } if(found==0){
            A_B[idx_ab] = A[i];
           ( idx_ab)++;
                
        }
    }
    printf("Elements in set difference (A-B) : ");
    for (int i = 0; i < idx_ab; i++)
    {
        printf("%d ", A_B[i]);
    }

    // difference B-A

    for (int i = 0; i < 5; i++)
    {     int found=0;
        for (int j = 0; j < 5; j++)
        {
            if (B[i] == A[j])
            {   found=1;
                
                j=5+1;
            }
        }if(found==0){

                B_A[idx_ba] = B[i];
                (idx_ba)++;
        }
    }
    printf("\nElements in set difference (B-A) : ");
    for (int i = 0; i < idx_ba; i++)
    {
        printf("%d ", B_A[i]);
    }

}

void symmetric_difference(int A[],int B[])
{
    // symmetric difference
    
    int symdiff[10];
    int idx_symdiff=0;
    
for (int i = 0; i <5; i++){
    int flag=0;
    for (int j = 0; j <5; j++){
        if(A[i]==B[j]){
            flag=1;
            j=6;
        }
        
    }if(flag==0){
         symdiff[idx_symdiff]=A[i];
             idx_symdiff++;

    }
}
for (int i = 0; i <5; i++){
    int flag=0;
    for (int j = 0; j <5; j++){
        if(B[i]==A[j]){
            flag=1;
            j=6;
        }
        
    }if(flag==0){
         symdiff[idx_symdiff]=B[i];
             idx_symdiff++;

    }
}


printf("Elements in set symmetric set difference (A B) : ");
    for (int i = 0; i < idx_symdiff; i++)
    {
        printf("%d ", symdiff[i]);
    }

} 
