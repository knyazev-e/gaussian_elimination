#include "functions.h"

Eigen::MatrixXd readcsv(const std::string& filename) {
    std::ifstream file(filename);
    size_t row_count = 0;
    std::string line;
    while (std::getline(file, line)) {
        row_count++;
    }
    size_t column_count = std::count(line.begin(), line.end(), ',') + 1;
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

    for (int i = 0; i < (row_number - 1); ++i) {

        if (matrix(i, i) == 0) {
            for (int k = i + 1; k < row_number; ++k) {
                if (matrix(k, i) != 0) {
                    matrix.row(i).swap(matrix.row(k));
                    break;
                }
            }
        }

        if (matrix(i, i) == 0) {
            continue;
        }

        for (int j = i + 1; j < row_number; ++j) {
            matrix.row(j) = matrix(i, i)*matrix.row(j) - matrix(j, i)*matrix.row(i);
        }
    }

    //assuming the system passed in the file has a solution and therefore has n rows and (n+1) columns
    Eigen::VectorXd answer(row_number);
    for (int i = row_number - 1; i >= 0; --i) {
        for (int j = row_number - 1; j > i; --j) {
            matrix(i, row_number) -= matrix(i, j)*answer(j);
            matrix(i, j) = 0;
        }
        if (matrix(i,i) != 0) {
            answer(i) = matrix(i, row_number)/matrix(i,i);
        }
    }

    return answer;
}
