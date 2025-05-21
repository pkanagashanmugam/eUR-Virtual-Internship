#include <stdio.h>
#include <stdlib.h>

void initialize_matrix(int ***matrix_pointer,int x,int y){
    *matrix_pointer=(int **)calloc(x,sizeof(int *));
    for(int i=0;i<x;i++)
        *(*matrix_pointer+i)=(int *)calloc(y,sizeof(int));
        
    printf("Enter the Matrix Elements : \n");
    for(int row=0;row<x;row++){
        for(int col=0;col<y;col++){
            printf("Enter matrix element [%d][%d] : ",row,col);
            scanf("%d",*(*matrix_pointer+row)+col);
        }
    }
}

void print_matrix(int **matrix,int x,int y){
    for(int row=0;row<x;row++){
        for(int col=0;col<y;col++)
            printf("%d ",*(*(matrix+row)+col));
        printf("\n");
    }
}

int main()
{
    int mat1_x,mat1_y,mat2_x,mat2_y;
    int **matrix_a,**matrix_b;
    
    printf("Enter row size of Matrix 1 :");
    scanf("%d",&mat1_x);
    printf("Enter column size of Matrix 1 :");
    scanf("%d",&mat1_y);
    
    initialize_matrix(&matrix_a,mat1_x,mat1_y);

    printf("Enter row size of Matrix 2 :");
    scanf("%d",&mat2_x);
    if(mat1_y!=mat2_x){
        printf("Dimensions of the two matrices does not support multiplication.Try Again!");
        return 0;
    }else{
        printf("Enter column size of Matrix 2 :");
        scanf("%d",&mat2_y);
        initialize_matrix(&matrix_b,mat2_x,mat2_y);
        
        printf("\nMatrix A :\n");
        print_matrix(matrix_a,mat1_x,mat1_y);
        
        printf("\nMatrix B :\n");
        print_matrix(matrix_b,mat2_x,mat2_y);
        
        int **matrix_c;
        matrix_c=(int **)calloc(mat1_x,sizeof(int *));
        for(int i=0;i<mat1_x;i++)
            *(matrix_c+i)=(int *)calloc(mat2_y,sizeof(int));
            
        
        for(int i=0;i<mat1_x;i++)
            for(int j=0;j<mat2_y;j++)
                for(int k=0;k<mat2_x;k++)
                    *(*(matrix_c+i)+j)+=((*(*(matrix_a+i)+k))*(*(*(matrix_b+k)+j)));
                    
        printf("\nMatrix C :\n");
        print_matrix(matrix_c,mat1_x,mat2_y);

    }
    return 0;
}
