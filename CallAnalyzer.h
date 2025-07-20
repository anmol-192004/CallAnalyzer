#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct CallRecord {
    std::string datetime;
    std::string contact;
    int duration; // in seconds
};

class CallAnalyzer {
private:
    std::vector<CallRecord> records;

public:
    void loadFromFile(const std::string& filename);
    void mostTalkedContactByDay();
    void mostTalkedContactByMonth();
    void mostTalkedContactByYear();
    void printAllStats();
};
