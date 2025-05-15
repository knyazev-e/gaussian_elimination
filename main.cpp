#include "functions.h"

int main() {
    Eigen::MatrixXd input_matrix = readcsv("linear_system.csv");
    Eigen::VectorXd answer = gauss_elimination(input_matrix);
    writecsv("answer.csv", answer);
    return 0;
}
