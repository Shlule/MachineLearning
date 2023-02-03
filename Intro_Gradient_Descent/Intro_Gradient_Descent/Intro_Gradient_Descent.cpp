// Intro_Gradient_Descent.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<sstream>
#include<vector>

#include<cmath>
struct ThetasCoef {
    double theta_0;
    double theta_1;
};
double hypothesis(double x, double theta_0P = 0, double theta_1P = 0) {
    /* calculate the predicted value for a given set of inputs and Thetas
    
    param x: inputs feature Numpy array of float
    param theta_0: intersept - float
    param theta_1: slope float
    return predictaded targets*/

    return theta_0P + (theta_1P * x);

}

std::vector<double> hypothesis(std::vector<double>x, double theta_0 = 0, double theta_1 = 0) {
    std::vector<double>result;
    for (auto i = x.begin(); i != x.end(); i++) {
        double xValue = theta_0 + (theta_1 * *i);
        result.emplace_back(xValue);
    }
    return result;
}

double costFunction(double theta_0P, double theta_1P, std::vector<double> x, std::vector<double> y) {
    /*calculate the total error for a given set of inputs and thetas*/

    double result{ 0.0 };
    for (int i = 0; i < x.size();i++) {
        double diff = hypothesis(x[i], theta_0P, theta_1P) - y[i];
        double squaredDiff = pow(diff, 2);
        result += squaredDiff;
    }

    return result / (x.size() * 2);
}

ThetasCoef gradient(double theta_0P, double theta_1P, double alpha, std::vector<double> x, std::vector<double> y) {
    double sumDiff0{0.0};
    double sumDiff1{ 0.0 };
    double theta_0{ theta_0P };
    double theta_1{ theta_1P };


    for (int i = 0; i < x.size(); i++) {
       const double errorDiff0 = (hypothesis(x[i], theta_0, theta_1) - y[i]);
       const double errorDiff1 = (hypothesis(x[i], theta_0, theta_1) - y[i]) * x[i];

       sumDiff0 += errorDiff0;
       sumDiff1 += errorDiff1;
    }
   
    double theta_0_temp = (alpha / x.size()) * sumDiff0;
    double theta_1_temp = (alpha / x.size()) * sumDiff1;

    double new_theta_0 = theta_0 - theta_0_temp;
    double new_theta_1 = theta_1 - theta_1_temp;

    struct ThetasCoef myStruct;

    myStruct.theta_0 = new_theta_0;
    myStruct.theta_1 = new_theta_1;

    return myStruct;
    
}

void findThetas( double theta_0P, double theta_1P, double alpha, double threshold, std::vector<double> xP, std::vector<double> yP) {
   
    double diff = costFunction(theta_0P, theta_1P, xP, yP);
    std::cout << "initial Cost" << diff << '\n';

    int iterationNb{ 0 };

    struct ThetasCoef myResult;

    double theta_0{ theta_0P };
    double theta_1{ theta_1P };
    double initialCost{ 0.0 };
    double newCost{ 0.0 };

    while (diff >= threshold) {
        initialCost = costFunction(theta_0, theta_1, xP, yP);

        myResult = gradient(theta_0, theta_1, alpha, xP, yP);

        theta_0 = myResult.theta_0;
        theta_1 = myResult.theta_1;

        newCost = costFunction(theta_0, theta_1, xP, yP);
        std::cout << "cost : " << newCost << '\n';

        diff = initialCost - newCost;

        iterationNb++;

        std::cout << "Iteration : " << iterationNb << '\n';
        std::cout << "diff : " << diff << '\n';
        std::cout << "theta0 : " << theta_0 << '\n';
        std::cout << "theta1 : " << theta_1 << '\n';
        std::cout <<'\n';
    }

}




int main()
{
    // Read Data from file in to vector.
    std::vector<double> dataY;
    std::vector<double>dataX;
    double element;
    std::ifstream myfile;
    myfile.open("train.csv", std::ifstream::in);
    if (myfile.is_open()) {
     
        while (myfile >> element) {
            dataY.emplace_back(element);
        }
        myfile.close();
        
    }else {
        std::cout << "file non ouvert" << '\n';
    }

    for (int i = 0; i < dataY.size()-1; i += 2) {
        dataX.emplace_back(dataY[i]);
    }
    for (int i = 0; i < dataY.size(); i += 1) {
        dataY.erase(dataY.begin() + i);
    }
    //========================================================
    
    // making descet of gradient

    //std::cout << costFunction(0.014, 1.0, dataX, dataY);
    findThetas(0.0, 0.0, 0.0001, 0.000001, dataX, dataY);


    /*for (double x : dataY) {
        std::cout << x << '\n';
    }*/

    
    



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
