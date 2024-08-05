#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate portfolio variance
double calculatePortfolioVariance(const std::vector<double>& weights,
                                  const std::vector<std::vector<double>>& covarianceMatrix) {
    double variance = 0.0;
    size_t n = weights.size();
    
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            variance += weights[i] * weights[j] * covarianceMatrix[i][j];
        }
    }
    
    return variance;
}

int main() {
    // Weights of assets in the portfolio
    std::vector<double> weights = {0.6, 0.4};
    
    // Covariance matrix
    std::vector<std::vector<double>> covarianceMatrix = {
        {0.02, 0.01},
        {0.01, 0.03}
    };
    
    double portfolioVariance = calculatePortfolioVariance(weights, covarianceMatrix);
    double portfolioStandardDeviation = std::sqrt(portfolioVariance);
    
    std::cout << "Portfolio Variance: " << portfolioVariance << std::endl;
    std::cout << "Portfolio Standard Deviation: " << portfolioStandardDeviation << std::endl;

    return 0;
}
