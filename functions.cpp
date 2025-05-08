#include "functions.h"

Eigen::MatrixXd readcsv(const std::string& filename) {
    std::ifstream file(filename);
    Eigen::MatrixXd matrix;

    std::string row;
    size_t row_number = 0;
    while std::getline(file, row) {
        std::istringstream row_stream(row);

        std::string number;
        size_t column_number = 0;
        while std::getline(row_stream, number, ',') {
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

Eigen::VectorXd gauss_elimination(const Eigen::MatrixXd& matrix) {}
