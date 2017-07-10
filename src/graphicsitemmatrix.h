//
// Матрица для хранения графических элементов
//

#ifndef GRAPHICSITEMMATRIX_H
#define GRAPHICSITEMMATRIX_H

#include "lifecell.h"
#include "basematrix.h"

typedef BaseMatrix<LifeCell *> Base;

class GraphicsItemMatrix
        : public Base
{
public:
    GraphicsItemMatrix();
    ~GraphicsItemMatrix();
//    void allocMemory();

};

#endif // GRAPHICSITEMMATRIX_H
