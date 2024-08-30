//23K2001 - Muzammil
using namespace std;

int** multiplyArrays(int **mat1,int **mat2,int mat1rows,int mat1cols,int mat2rows,int mat2cols,int &resR,int &resC){
    if(mat1cols==mat2rows){
			resR = mat1rows;
			resC = mat2cols;
            int **prod = new int*[resR];
			for(int i=0;i<resR;i++){
				prod[i] = new int[resC];
				for(int j=0;j<resC;j++)
				prod[i][j] = 0;
			}

            for(int i=0;i<mat1rows;i++){
                for(int j=0;j<mat2cols;j++){
                    for(int x=0;x<mat1cols;x++)
						prod[i][j] += mat1[i][x]*mat2[x][j];
                }     
            }
			return prod;
        } else{
			cout<<"Sorry cannot multiply! (Orders not compatible)"<<endl;
			return nullptr;
		}
}