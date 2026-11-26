#include <cassert>
#include <iostream>
#include <vector>
#include <Eigen/Dense>

//template <typename T>

bool test_matrix_vector_product() {
  /*
   * Test implementation of operator* for Matrix-vector product.
   */
  bool tests_passed = true;

  Eigen::MatrixXd matrix = {(1., 2.), (3., 4.)};
  Eigen::VectorXd vec = {1., 1.};

  Eigen::VectorXd mat_vec = matrix * vec;

  Eigen::VectorXd reference = {3., 7.};

  double tol = 1e-8;
  for (auto i = 0u; i < reference.size(); i++) {
    // floating point values are "equal" if their
    // difference is small
    if ((reference.at(i) - mat_vec.at(i)) > tol) {
      tests_passed = false;
    }
  }
  if (tests_passed) {
    std::cout << "Tests passed!\n";
  } else {
    std::cout << "Tests failed \n";
    std::cout << "Reference: ";
    print_vec(reference, false);
    std::cout << "Computed: ";
    print_vec(mat_vec, false);
  }
  return tests_passed;
}

int main() {
  Eigen::MatrixXd matrix = {{1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.}};

  Eigen::VectorXd vec_a = {1., 2., 3.};
  Eigen::VectorXd vec_b = {4., 5., 6.};

  // adding two vectors
  auto vec_sum = vec_a + vec_b;
  std::cout << vec_sum << std::endl;

  test_matrix_vector_product();
}
