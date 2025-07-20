#include "CallAnalyzer.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <algorithm>

void CallAnalyzer::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string datetime, contact, durStr;

        std::getline(ss, datetime, ',');
        std::getline(ss, contact, ',');
        std::getline(ss, durStr);

        int duration = std::stoi(durStr);

        records.push_back({ datetime, contact, duration });
    }
    file.close();
}

void CallAnalyzer::printAllStats() {
    std::cout << "Total records: " << records.size() << "\n";
}

void CallAnalyzer::mostTalkedContactByDay() {
    std::map<std::string, std::unordered_map<std::string, int>> dailyMap;

    for (const auto& rec : records) {
        std::string date = rec.datetime.substr(0, 10); // YYYY-MM-DD
        dailyMap[date][rec.contact] += rec.duration;
    }

    std::cout << "\n--- Most Talked Contact Per Day ---\n";
    for (const auto& entry : dailyMap) {
        std::string date = entry.first;
        std::string maxContact;
        int maxDuration = 0;

        for (const auto& pair : entry.second) {
            if (pair.second > maxDuration) {
                maxDuration = pair.second;
                maxContact = pair.first;
            }
        }

        std::cout << date << " → " << maxContact << " (" << maxDuration << " sec)\n";
    }
}

void CallAnalyzer::mostTalkedContactByMonth() {
    std::map<std::string, std::unordered_map<std::string, int>> monthMap;

    for (const auto& rec : records) {
        std::string month = rec.datetime.substr(0, 7); // YYYY-MM
        monthMap[month][rec.contact] += rec.duration;
    }

    std::cout << "\n--- Most Talked Contact Per Month ---\n";
    for (const auto& entry : monthMap) {
        std::string month = entry.first;
        std::string maxContact;
        int maxDuration = 0;

        for (const auto& pair : entry.second) {
            if (pair.second > maxDuration) {
                maxDuration = pair.second;
                maxContact = pair.first;
            }
        }

        std::cout << month << " → " << maxContact << " (" << maxDuration << " sec)\n";
    }
}

void CallAnalyzer::mostTalkedContactByYear() {
    std::map<std::string, std::unordered_map<std::string, int>> yearMap;

    for (const auto& rec : records) {
        std::string year = rec.datetime.substr(0, 4); // YYYY
        yearMap[year][rec.contact] += rec.duration;
    }

    std::cout << "\n--- Most Talked Contact Per Year ---\n";
    for (const auto& entry : yearMap) {
        std::string year = entry.first;
        std::string maxContact;
        int maxDuration = 0;

        for (const auto& pair : entry.second) {
            if (pair.second > maxDuration) {
                maxDuration = pair.second;
                maxContact = pair.first;
            }
        }

        std::cout << year << " → " << maxContact << " (" << maxDuration << " sec)\n";
    }
}
