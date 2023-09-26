#ifndef MATRIX3D_H
#define MATRIX3D_H
#include<iostream>

class Matrix3D
{
    public:
        Matrix3D();
        virtual ~Matrix3D();

        void setmat(int i, int j, double val);
        double det();
        Matrix3D inverse();
        double submat(int i, int j);
        void display();
        Matrix3D operator+(const Matrix3D& m)const;
        Matrix3D operator-(const Matrix3D& m)const;
        Matrix3D operator*(const Matrix3D& m)const;

    private:
        double mat[3][3];
};

#endif // MATRIX3D_H
