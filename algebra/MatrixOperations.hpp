#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include "Matrix.hpp"

namespace lito {

    template <typename T> Matrix<T> partialPivoting(Matrix<T>& M, const uint& idLine, const uint& idcolumn, const T error = T(1e-5));
    template <typename T> Matrix<T> totalPivoting(Matrix<T>& M, const uint& idLine, const uint& idcolumn, uint* columnOrder = nullptr, const T error = T(1e-5));
    template <typename T> std::pair<Matrix<T>, uint*> gaussReduction(const Matrix<T>& M, Matrix<T>& operations, const T error = T(1e-5));



    /*! partialPivoting
    * Calculate partial pivoting if the value of idLine and idColumn of the matrix is less than error
    * Matrix<T> M: The matrix to pivote
    * uint idLine: The line of the value to be pivoting
    * uint idcolumn: The line of the value to be pivoting
    * T error: The error value
    * return: The matrix of operation
    */
    template <typename T>
    Matrix<T> partialPivoting(Matrix<T>& M, const uint& idLine, const uint& idcolumn, const T error)
    {
        Matrix<T> operation(M.getRows(), M.getColumns, MatrixType::IDENTITY);

        if (M(idLine, idcolumn) <= error)
        {
            T valueAuxPivot;
            T  valueMaxPivot = T(0);
            uint idMaxPivot;
            uint idMaxPivotLine;
            uint idMaxPivotColumn;

            for (uint j = idLine + 1; j < M.getRows(); j++)
            {
                valueAuxPivot = T(std::abs(M(j, idcolumn)));
                if (error < valueAuxPivot && valueMaxPivot < valueAuxPivot)
                {
                    valueMaxPivot = valueAuxPivot;
                    idMaxPivot = j;
                }
            }

            if (valueMaxPivot > error)
            {
                M.elementarOperationSwitchLines(idLine, idMaxPivot);
                operation.elementarOperationSwitchLines(idLine, idMaxPivot);
            }
        }

        return operation;
    }

    /*! totalPivoting
    * Calculate total pivoting if the value of idLine and idColumn of the matrix is less than error
    * Matrix<T> M: The matrix to pivote
    * uint idLine: The line of the value to be pivoting
    * uint idcolumn: The line of the value to be pivoting
    * T error: The error value
    * return: The matrix of operation and new order of columns
    */
    template <typename T>
    Matrix<T> totalPivoting(Matrix<T>& M, const uint& idLine, const uint& idcolumn, uint* columnOrder, const T error)
    {
        Matrix<T> operation(M.getRows(), M.getColumns(), MatrixType::IDENTITY);

        if (M(idLine, idcolumn) <= error)
        {
            T valueAuxPivot;
            T  valueMaxPivot = T(0);
            uint idMaxPivot;
            uint idMaxPivotLine;
            uint idMaxPivotColumn;
            uint auxColumnOrder;

            for (uint j = idLine + 1; j < M.getRows(); j++)
            {
                valueAuxPivot = T(std::abs(M(j, idcolumn)));
                if (error < valueAuxPivot && valueMaxPivot < valueAuxPivot)
                {
                    valueMaxPivot = valueAuxPivot;
                    idMaxPivot = j;
                }
            }

            if (valueMaxPivot > error)
            {
                M.elementarOperationSwitchLines(idLine, idMaxPivot);
                operation.elementarOperationSwitchLines(idLine, idMaxPivot);
            }
            else
            {
                for (uint j = idcolumn + 1; j < M.getColumns(); j++)
                {
                    valueAuxPivot = T(std::abs(M(idLine, j)));
                    if (error < valueAuxPivot && valueMaxPivot < valueAuxPivot)
                    {
                        valueMaxPivot = valueAuxPivot;
                        idMaxPivot = j;
                    }
                }

                if (valueMaxPivot > error)
                {
                    M.elementarOperationSwitchColumns(idcolumn, idMaxPivot);
                    if (columnOrder != nullptr)
                    {
                        auxColumnOrder = columnOrder[idMaxPivot];
                        columnOrder[idMaxPivot] = columnOrder[idcolumn];
                        columnOrder[idcolumn] = auxColumnOrder;

                    }
                }
                else
                {
                    for (uint j = idLine + 1; j < M.getRows(); j++)
                    {
                        for (uint k = idcolumn + 1; k < M.getColumns(); k++)
                        {
                            valueAuxPivot = T(std::abs(M(j, k)));
                            if (error < valueAuxPivot && valueMaxPivot < valueAuxPivot)
                            {
                                valueMaxPivot = valueAuxPivot;
                                idMaxPivotLine = j;
                                idMaxPivotColumn = k;
                            }
                        }
                    }

                    if (valueMaxPivot > error)
                    {
                        M.elementarOperationSwitchLines(idLine, idMaxPivotLine);
                        operation.elementarOperationSwitchLines(idLine, idMaxPivot);

                        M.elementarOperationSwitchColumns(idcolumn, idMaxPivotColumn);
                        if (columnOrder != nullptr)
                        {
                            auxColumnOrder = columnOrder[idMaxPivot];
                            columnOrder[idMaxPivot] = columnOrder[idcolumn];
                            columnOrder[idcolumn] = auxColumnOrder;

                        }
                    }
                }
            }
        }

        return operation;
    }

    /*! gaussReduction
    * Calculate the Gauss reduction
    * Matrix<T> M: The matrix to reduce
    * Matrix<T> operations: The matrix with operations
    * T error: The error value
    * return: The matrix reducted and the new orde of columns
    */
    template <typename T>
    std::pair<Matrix<T>, uint*> gaussReduction(const Matrix<T>& M, Matrix<T>& operations, const T error)
    {
        Matrix<T> reduction = M;
        operations = Matrix<T>(reduction.getRows(), reduction.getColumns(), MatrixType::IDENTITY);
        uint* columnOrder = new uint[reduction.getColumns()];
        T mulLine;

        for (uint i = 0; i < reduction.getColumns(); i++)
            columnOrder[i] = i;
        
        for (uint i = 0; i < reduction.getRows(); i++)
        {
            operations = matMul(totalPivoting(reduction, i, i, columnOrder, error), operations);
            
            for (uint j = i + 1; j < reduction.getRows(); j++)
            {
                if (T(std::abs(reduction(j, i))) > error)
                {
                    mulLine = -(reduction(j, i) / reduction(i, i));
                    reduction.elementarOperationSumLines(i, j, mulLine);
                    operations.elementarOperationSumLines(i, j, mulLine);
                }
            }
        }
        return std::pair<Matrix<T>, uint*>(reduction, columnOrder);
    }

}

#endif