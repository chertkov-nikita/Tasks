#include "matrix.h"

TMatrix::TMatrix()
{

}

TMatrix::TMatrix(QString str)
{
    QVector<qint16> tmp;
    QStringList line_list = str.split('\n');
    QStringList num_list;
    mass_size = line_list.length();
    for (int i = 0; i < mass_size; i++)
    {
        num_list = line_list[i].split(' ');
        for (int j = 0; j < num_list.length(); j++)
        {
            tmp.push_back(num_list[j].toInt());
        }
        mass.push_back(tmp);
        tmp.clear();
    }
}

int TMatrix::get_size()
{
    return mass_size;
}

QVector<QVector<qint16>> TMatrix::get_matrix()
{
    return mass;
}
