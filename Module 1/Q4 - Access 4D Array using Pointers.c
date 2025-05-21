#include <stdio.h>

int main()
{
    int mat[2][3][4][5],i,j,k,l;
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            for(k=0;k<4;k++)
                for(l=0;l<5;l++)
                    mat[i][j][k][l]=i+j+k+l+1;
    i=1,j=1,k=3;
    printf("Value of mat[i][j][k][2] using [] indexing is : %d\n",mat[i][j][k][2]);
    printf("Value of mat[i][j][k][2] using pointers is : %d\n",*(*(*(*(mat+i)+j)+k)+2));
    return 0;
}
