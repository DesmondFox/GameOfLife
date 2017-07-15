#include "graphicsitemmatrix.h"

GraphicsItemMatrix::GraphicsItemMatrix()
    : Base()
{

}

GraphicsItemMatrix::~GraphicsItemMatrix()
{
}

void GraphicsItemMatrix::allDead()
{
    // Метод для очистки поля от живых клеток

    for (size_t i = 0; i < this->countRow; i++)
        for (size_t j = 0; j < this->countCol; j++)
            this->m_matrix[i][j]->changeStatus(C_DIED);

    qDebug() << "Notice:\t GraphicsItemMatrix: All cells cleared";
}
