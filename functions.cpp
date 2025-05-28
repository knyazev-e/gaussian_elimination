#include "functions.h"
#include <iostream>

Eigen::MatrixXd readcsv(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::getline(file, line);
    size_t column_count = std::count(line.begin(), line.end(), ',') + 1;
    size_t row_count = 1;
    while (std::getline(file, line)) {
        row_count++;
    }
    file.close();

    file.open(filename);
    Eigen::MatrixXd matrix(row_count, column_count);

    std::string row;
    size_t row_number = 0;
    while (std::getline(file, row)) {
        std::istringstream row_stream(row);

        std::string number;
        size_t column_number = 0;
        while (std::getline(row_stream, number, ',')) {
            matrix(row_number, column_number) = std::stod(number);
            column_number++;
        }
        row_number++;
    }
    file.close();
    return matrix;
}

void writecsv(const std::string& filename, const Eigen::VectorXd& answer) {
    std::ofstream file(filename);
    for (size_t i = 0; i < answer.size(); i++) {
        file << answer(i);
        if (i != (answer.size()-1)) {
            file << ',';
        }
    }
    file.close();
}

Eigen::VectorXd gauss_elimination(Eigen::MatrixXd& matrix) {
    int row_number = matrix.rows();
    int col_number = matrix.cols();

    // elimination
    for (int c = 0; c < (row_number); ++c) {
        if (matrix(c, c) == 0) {
            for (int r = c + 1; r < row_number; ++r) {
                if (matrix(r, c) != 0) {
                    matrix.row(c).swap(matrix.row(r));
                    break;
                }
            }
        }

        if (matrix(c, c) == 0) {
            continue;
        }

        for (int r = c + 1; r < row_number; ++r) {
            matrix.row(r) = matrix.row(r)*matrix(c, c) - matrix.row(c)*matrix(r, c);
        }
    }

    // calculating the unknowns
    Eigen::VectorXd answer(row_number);
    for (int r = row_number - 1; r >= 0; --r) {
        for (int c = row_number - 1; c > r; --c) {
            matrix(r, col_number - 1) -= matrix(r, c)*answer(c);
            matrix(r, c) = 0;
        }
        if (matrix(r,r) != 0) {
            answer(r) = matrix(r, col_number - 1)/matrix(r,r);
        }
    }

    return answer;
}
