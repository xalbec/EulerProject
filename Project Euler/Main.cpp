#include "ProblemSolver.h"
#include "Utilities.h"
#include "Megaint.h"
#include <chrono>;
#include <iostream>;
#include <string>;

using namespace std::chrono;
using namespace std;

int main() {

	auto start = high_resolution_clock::now();

	ProblemSolver ps;
	cout << ps.Problem16() << " is the solution. \n";

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "This program took " << duration.count() << " microseconds to run.";
	
} 