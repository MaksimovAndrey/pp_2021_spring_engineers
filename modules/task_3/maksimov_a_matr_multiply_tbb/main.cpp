// Copyright 2021 Maksimov Andrey
#include <tbb/tbb.h>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "./matrix_multiply_tbb.h"

TEST(Matr_mupltiply, Can_generate_matrix) {
    const int matrRows = 20;
    std::vector<double> matr = generateMatrix(matrRows);
    for (int i = 0; i < matrRows * matrRows; i++) {
        ASSERT_GT(matr[i], 0.0);
    }
}

TEST(Matr_mupltiply, Rows_not_equal) {
    std::vector<double> matr1 = { 2.0 };
    std::vector<double> matr2
        = { 4.0, 1.0,
            1.0, 1.0 };
    std::vector<double> expectedMatr = { 8.0 };

    ASSERT_ANY_THROW(mupltiplyMatrixByMatrix(matr1, matr2, 1, 2));
}


TEST(Matr_mupltiply, Correct_mupltiply_ALL_1000x1000_4_threads) {
    const int matrRows = 1000;
    std::vector<double> matr1 = generateMatrix(matrRows);
    std::vector<double> matr2 = generateMatrix(matrRows);

    std::vector<double> resultMatr
        = mupltiplyMatrixByMatrix(matr1, matr2, matrRows, matrRows);
    std::vector<double> resultMatrOmp
        = mupltiplyMatrixByMatrixOmp(matr1, matr2, matrRows, matrRows, 4);
    std::vector<double> resultMatrTbb
        = mupltiplyMatrixByMatrixTbb(matr1, matr2, matrRows, matrRows, 4);
    for (int i = 0; i < matrRows * matrRows; i++) {
        ASSERT_EQ(resultMatr[i], resultMatrTbb[i]);
    }
}

TEST(Matr_mupltiply, Correct_mupltiply_ALL_1440x1440_9_threads) {
    const int matrRows = 1440;
    std::vector<double> matr1 = generateMatrix(matrRows);
    std::vector<double> matr2 = generateMatrix(matrRows);

    std::vector<double> resultMatr
        = mupltiplyMatrixByMatrix(matr1, matr2, matrRows, matrRows);
    std::vector<double> resultMatrOmp
        = mupltiplyMatrixByMatrixOmp(matr1, matr2, matrRows, matrRows, 9);
    std::vector<double> resultMatrTbb
        = mupltiplyMatrixByMatrixTbb(matr1, matr2, matrRows, matrRows, 9);
    for (int i = 0; i < matrRows * matrRows; i++) {
        ASSERT_EQ(resultMatr[i], resultMatrTbb[i]);
    }
}

TEST(Matr_mupltiply, Correct_mupltiply_ALL_1600x1600_4_threads) {
    const int matrRows = 1600;
    std::vector<double> matr1 = generateMatrix(matrRows);
    std::vector<double> matr2 = generateMatrix(matrRows);

    std::vector<double> resultMatr
        = mupltiplyMatrixByMatrix(matr1, matr2, matrRows, matrRows);
    std::vector<double> resultMatrOmp
        = mupltiplyMatrixByMatrixOmp(matr1, matr2, matrRows, matrRows, 4);
    std::vector<double> resultMatrTbb
        = mupltiplyMatrixByMatrixTbb(matr1, matr2, matrRows, matrRows, 4);
    for (int i = 0; i < matrRows * matrRows; i++) {
        ASSERT_EQ(resultMatr[i], resultMatrTbb[i]);
    }
}

TEST(Matr_mupltiply, Correct_mupltiply_ALL_6400x6400_9_threads) {
    const int matrRows = 6400;
    std::vector<double> matr1 = generateMatrix(matrRows);
    std::vector<double> matr2 = generateMatrix(matrRows);

    std::vector<double> resultMatrOmp
        = mupltiplyMatrixByMatrixOmp(matr1, matr2, matrRows, matrRows, 9);
    std::vector<double> resultMatrTbb
        = mupltiplyMatrixByMatrixTbb(matr1, matr2, matrRows, matrRows, 9);
    for (int i = 0; i < matrRows * matrRows; i++) {
        ASSERT_EQ(resultMatrOmp[i], resultMatrTbb[i]);
    }
}

int main() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
