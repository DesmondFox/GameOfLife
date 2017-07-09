//#include "graphicsitemmatrix.h"

//GraphicsItemMatrix::GraphicsItemMatrix()
//{
//    m_matrix    = nullptr;
//}

//void GraphicsItemMatrix::allocate(size_t row, size_t col)
//{
//    Q_ASSERT(row > 0 && col > 0);

//    if (m_matrix != nullptr)
//        return;

//    m_matrix = new QGraphicsItem*[row];
//    for (size_t i = 0; i < row; i++)
//        m_matrix[i] = new QGraphicsItem[col];

//    _rows = row;
//    _cols = col;

//    qDebug() << "Notice:\t Graphics Item Matrix has been created [" << row << "x" << col << "]";
//}
