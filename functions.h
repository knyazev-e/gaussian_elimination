#include <fstream>
#include <Eigen/Dense>
#include <string>
#include <vector>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

Eigen::MatrixXd readcsv(const std::string& filename);

void writecsv(const std::string& filename, const Eigen::VectorXd& answer);

Eigen::VectorXd gauss_elimination(const Eigen::MatrixXd& matrix);

#endif
