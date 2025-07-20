#include "CallAnalyzer.h"
#include <iostream>

int main() {
    CallAnalyzer analyzer;
    std::string file;

    std::cout << "Enter call log filename (e.g., calls.csv): ";
    std::cin >> file;

    analyzer.loadFromFile(file);

    std::cout << "\n[ Call History Analyzer ]\n";
    analyzer.printAllStats();
    analyzer.mostTalkedContactByDay();
    analyzer.mostTalkedContactByMonth();
    analyzer.mostTalkedContactByYear();

    return 0;
}
