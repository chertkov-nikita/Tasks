#ifndef MATRIX_H
#define MATRIX_H


#include<QVector>
#include <QStringList>
class TMatrix
{
    QVector<QVector<qint16>> mass;
    int mass_size;

public:
    TMatrix();
    TMatrix(QString);
    QVector<QVector<qint16>> get_matrix();
    int get_size();
};


#endif // MATRIX_H
