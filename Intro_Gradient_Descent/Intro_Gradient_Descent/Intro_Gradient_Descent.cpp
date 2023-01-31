// Intro_Gradient_Descent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>

#include<cmath>

double hypothesis(double x, double theta_0P = 0, double theta_1P = 0) {
    /* calculate the predicted value for a given set of inputs and Thetas
    
    param x: inputs feature Numpy array of float
    param theta_0: intersept - float
    param theta_1: slope float
    return predictaded targets*/

    return theta_0P + (theta_1P * x);

}

std::vector<double> hypthesis(std::vector<double>x, double theta_0 = 0, double theta_1 = 0) {
    std::vector<double>result;
    for (auto i = x.begin(); i != x.end(); i++) {
        result.emplace_back(theta_0 + (theta_1 * *i));
    }
    return result;
}

double costFunction(double theta_0P, double theta_1P, std::vector<double> x, std::vector<double> y) {
    /*calculate the total error for a given set of inputs and thetas*/

    double result{ 0.0 };
    for (auto i = x.begin(); i != x.end(); i++) {
        result += hypothesis(*i,theta_0P,theta_1P) - 
    }

    return 0;
}

int main()
{

    std::vector<double> dataY;
    std::vector<double>dataX;
    double element;
    std::ifstream myfile;
    myfile.open("test.csv", std::ifstream::in);
    if (myfile.is_open()) {
     
        while (myfile >> element) {
            dataY.emplace_back(element);
        }myfile.close();
        
    }else {
        std::cout << "file non ouvert" << '\n';
    }

    for (auto i = dataY.begin(); i != dataY.end(); i += 2) {
        dataX.emplace_back(*i);
    }
    for (int i = 0; i < dataY.size(); i += 1) {
        dataY.erase(dataY.begin() + i);
    }

    for (auto i = dataY.begin(); i != dataY.end(); i++) {
        std::cout << *i << '\n';
    }

    for (auto i = dataX.begin(); i != dataX.end(); i++) {
        std::cout << *i << '\n';
    }
    



    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
