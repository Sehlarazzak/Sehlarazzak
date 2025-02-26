#include <iostream>

class Polynomial {
private:
    int degree;
    double* coefficients;

public:
    // Default constructor
    Polynomial() : degree(0), coefficients(new double[1]{0}) {}

    // Parameterized constructor
    Polynomial(int deg, const double* coeffs) : degree(deg) 
	{
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = coeffs[i];
        }
    }

    // Copy constructor
    Polynomial(const Polynomial& other) : degree(other.degree) 
	{
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }

    // Move constructor
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        double power = 1; 
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * power;
            power *= x; 
        }
        return result;
    }
	
    Polynomial add(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{0};

        for (int i = 0; i <= degree; i++) {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; i++) {
            newCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{0};

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }

    void display() const {
        for (int i = degree; i >= 0; i--) {
            std::cout << coefficients[i];
            if (i > 0) std::cout << "x^" << i << " + ";
        }
        std::cout << std::endl;
    }
};

int main() {
    double coeffs1[] = {1, 2, 3}; 
    Polynomial p1(2, coeffs1);

    double coeffs2[] = {4, 5, 6}; 
    Polynomial p2(2, coeffs2);

    std::cout << "Polynomial 1: ";
    p1.display();

    std::cout << "Polynomial 2: ";
    p2.display();

    Polynomial sum = p1.add(p2);
    std::cout << "Sum of Polynomials: ";
    sum.display(); 

    Polynomial product = p1.multiply(p2);
    std::cout << "Product of Polynomials: ";
    product.display(); 
    double x = 2;
    std::cout << "p1 evaluated at x=" << x << ": " << p1.evaluate(x) << std::endl;

    return 0;
}

