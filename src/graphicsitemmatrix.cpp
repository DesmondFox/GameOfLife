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

    for (size_t i = 0; i < this->countCol; i++)
        for (size_t j = 0; j < this->countRow; j++)
            m_matrix[i][j]->changeStatus(C_DIED);
}
