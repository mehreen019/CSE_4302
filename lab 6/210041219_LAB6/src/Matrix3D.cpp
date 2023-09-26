#include "Matrix3D.h"

Matrix3D::Matrix3D()
{
    //ctor
}

Matrix3D::~Matrix3D()
{
    //dtor
}

void Matrix3D::setmat(int i, int j, double val){
    mat[i][j]=val;
}

double Matrix3D::det(){
    double sub1=(mat[1][1]*mat[2][2])-(mat[1][2]*mat[2][1]);
    double sub2=(mat[1][0]*mat[2][2])-(mat[1][2]*mat[2][0]);
    double sub3=(mat[1][0]*mat[2][1])-(mat[2][0]*mat[1][1]);

    return mat[0][0]*sub1+mat[0][1]*sub2+mat[0][2]*sub3;
}

double Matrix3D::submat(int i, int j){

}

Matrix3D Matrix3D::inverse(){
    Matrix3D temp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp.setmat(i,j, mat[j][i]);
        }
    }

    return temp;
}

void Matrix3D::display(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

Matrix3D Matrix3D::operator+(const Matrix3D& m) const{
    Matrix3D temp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp.mat[i][j]=mat[i][j]+m.mat[i][j];
        }
    }
    return temp;
}

Matrix3D Matrix3D::operator-(const Matrix3D& m)const{
    Matrix3D temp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp.mat[i][j]=mat[i][j]-m.mat[i][j];
        }
    }
    return temp;
}

Matrix3D Matrix3D::operator*(const Matrix3D& m)const{
    Matrix3D temp;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temp.mat[i][j]=mat[i][j]*m.mat[i][j];
        }
    }
    return temp;
}


