#include <fstream>
#include <Eigen/Dense>
#include <string>
#include <algorithm>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

Eigen::MatrixXd readcsv(const std::string& filename);

void writecsv(const std::string& filename, const Eigen::VectorXd& answer);

Eigen::VectorXd gauss_elimination(Eigen::MatrixXd& matrix);

#endif
