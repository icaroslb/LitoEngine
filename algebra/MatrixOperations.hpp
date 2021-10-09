#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include "Matrix.hpp"

namespace lito {

    template <typename T> void partialPivoting(Matrix<T>& M, Matrix<T>& rowOperations, const uint& idLine, const uint& idcolumn, const T error = T(1e-5));
    template <typename T> void totalPivoting(Matrix<T>& M, Matrix<T>& rowOperation, Matrix<T>& columnOperation, const uint& idLine, const uint& idcolumn, const T error = T(1e-5));
    template <typename T> Matrix<T> gaussReduction(const Matrix<T>& M, Matrix<T>& rowOperations, Matrix<T>& columnOperations, const T error = T(1e-5));
    template <typename T> Matrix<T> gaussJordanReduction(const Matrix<T>& M, Matrix<T>& rowOperations, Matrix<T>& columnOperations, const T error = T(1e-5));



    /*! partialPivoting
    * Calculate partial pivoting if the value of idLine and idColumn of the matrix is less than error
    * Matrix<T> M: The matrix to pivote
    * uint idLine: The line of the value to be pivoting
    * uint idcolumn: The line of the value to be pivoting
    * T error: The error value
    */
    template <typename T>
    void partialPivoting(Matrix<T>& M, Matrix<T>& rowOperations, const uint& idLine, const uint& idcolumn, const T error)
    {
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
                rowOperations.elementarOperationSwitchLines(idLine, idMaxPivot);
            }
        }
    }

    /*! totalPivoting
    * Calculate total pivoting if the value of idLine and idColumn of the matrix is less than error
    * Matrix<T> M: The matrix to pivote
    * Matrix<T> rowOperation: The matrix with row operations
    * Matrix<T> columnOperation: The matrix with column operations
    * uint idLine: The line of the value to be pivoting
    * Matrix<T> idcolumn: The matrix of position
    * T error: The error value
    */
    template <typename T>
    void totalPivoting(Matrix<T>& M, Matrix<T>& rowOperation, Matrix<T>& columnOperation, const uint& idLine, const uint& idcolumn, const T error)
    {
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
                rowOperation.elementarOperationSwitchLines(idLine, idMaxPivot);
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
                    columnOperation.elementarOperationSwitchColumns(idcolumn, idMaxPivot);
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
                        rowOperation.elementarOperationSwitchLines(idLine, idMaxPivot);

                        M.elementarOperationSwitchColumns(idcolumn, idMaxPivotColumn);
                        columnOperation.elementarOperationSwitchColumns(idcolumn, idMaxPivot);
                    }
                }
            }
        }
    }

    /*! gaussReduction
    * Calculate the Gauss reduction
    * Matrix<T> M: The matrix to reduce
    * Matrix<T> operations: The matrix with operations
    * T error: The error value
    * return: The matrix reducted
    */
    template <typename T>
    Matrix<T> gaussReduction(const Matrix<T>& M, Matrix<T>& rowOperations, Matrix<T>& columnOperations, const T error)
    {
        Matrix<T> reduction = M;
        columnOperations = rowOperations = Matrix<T>(reduction.getRows(), reduction.getColumns(), MatrixType::IDENTITY);
        T mulLine;

        for (uint i = 0; i < reduction.getRows(); i++)
        {
            totalPivoting(reduction, rowOperations, columnOperations, i, i, error);
            
            if (std::abs(reduction(i, i) > error))
            {
                for (uint j = i + 1; j < reduction.getRows(); j++)
                {
                    if (T(std::abs(reduction(j, i))) > error)
                    {
                        mulLine = -(reduction(j, i) / reduction(i, i));
                        reduction.elementarOperationSumLines(i, j, mulLine);
                        rowOperations.elementarOperationSumLines(i, j, mulLine);
                    }
                }
            }
            else
            {
                break;
            }
        }

        return reduction;
    }

    /*! gaussJordanReduction
    * Calculate the Gauss Jordan reduction
    * Matrix<T> M: The matrix to reduce
    * Matrix<T> rowOperations: The matrix with rows operations
    * Matrix<T> columnOperations: The matrix with columns operations
    * T error: The error value
    * return: The matrix reducted
    */
    template <typename T>
    Matrix<T> gaussJordanReduction(const Matrix<T>& M, Matrix<T>& rowOperations, Matrix<T>& columnOperations, const T error)
    {
        Matrix<T> reduction;
        T actualMulLine;
        T mulLine;
        uint line = M.getRows();
        uint lineAux;

        reduction = gaussReduction(M, rowOperations, columnOperations, error);

        for (uint i = 0; i < reduction.getRows(); i++)
        {
            line = reduction.getRows() - i - 1;
            actualMulLine = reduction(line, line);

            if (T(std::abs(actualMulLine)) > error)
            {
                reduction.elementarOperationMultLine(line, T(1) / actualMulLine);
                rowOperations.elementarOperationMultLine(line, T(1) / actualMulLine);

                for (uint j = i + 1; j < reduction.getRows(); j++)
                {
                    lineAux = reduction.getRows() - j - 1;
                    mulLine = -reduction(lineAux, line);

                    if (T(std::abs(mulLine)) > error)
                    {
                        reduction.elementarOperationSumLines(line, lineAux, mulLine);
                        rowOperations.elementarOperationSumLines(line, lineAux, mulLine);
                    }
                }
            }
        }
        return reduction;
    }

}

#endif