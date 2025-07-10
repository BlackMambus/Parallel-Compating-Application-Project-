#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>

int main() {
    const int size = 1e7;
    std::vector<int> data(size, 1); // Initialize vector with 1s
    long long sum = 0;

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    return 0;
}




