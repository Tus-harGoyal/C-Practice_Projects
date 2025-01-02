#include <iostream>
#include <cmath>
#include <vector>

void thomasSolver(int nodes, std::vector<std::vector<double>>& AA, std::vector<double>& C, std::vector<double>& T) {
    // Placeholder implementation for demonstration purposes
    for (int i = 0; i < nodes; ++i) {
        T[i] = C[i];
    }
}

void printResults(const std::vector<double>& x, const std::vector<double>& T, const std::vector<double>& T_ana) {
    for (size_t i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " " << T[i] << " " << T_ana[i] << std::endl;
    }
}

int main() {
    const double Tin = 0.0;
    const double Tmax = 40.0;
    const double Dee = 2.0;  // Adjust this value as needed
    const double Alpha = 0.01;
    const double El = 1.0;
    const int Nodes = 11;
    const double delx = El / static_cast<double>(Nodes - 1);
    const double delt = Dee * delx * delx / Alpha;

    std::vector<double> x(Nodes);
    x[0] = 0.0;
    for (int i = 1; i < Nodes; ++i) {
        x[i] = x[i - 1] + delx;
    }

    std::vector<double> T0(Nodes + 2);
    for (int i = 1; i <= Nodes; ++i) {
        T0[i] = sin(M_PI * x[i - 1]);  // Corrected initialization
    }

    double tt = Tin + delt;

    while (tt <= Tmax) {
        std::vector<std::vector<double>> AA(Nodes, std::vector<double>(3, 0.0));
        std::vector<double> C(Nodes, 0.0);
        std::vector<double> T(Nodes, 0.0);

        for (int i = 1; i < Nodes; ++i) {
            AA[i][0] = -0.5 * Dee;
            AA[i][2] = AA[i][0];
            AA[i][1] = 1.0 - AA[i][0] - AA[i][2];
            C[i - 1] = 0.5 * Dee * (T0[i + 1] - 2 * T0[i] + T0[i - 1]);
        }

        thomasSolver(Nodes, AA, C, T);

        // Computation of Analytical Solution for the current time step
        std::vector<double> T_ana(Nodes);
        for (int i = 0; i < Nodes; ++i) {
            T_ana[i] = exp(-Alpha * M_PI * M_PI * tt) * sin(M_PI * x[i]);
        }

        std::cout << "Results at t = " << tt << std::endl;
        printResults(x, T, T_ana);

        // Update, Continue/Terminate
        tt += delt;
        T0 = T;  // Update T0 for the next iteration
    }

    return 0;
}
