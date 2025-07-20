# Call History Analyzer 

A C++ terminal-based tool that analyzes call logs and shows the most talked contact:
- Per **day**
- Per **month**
- Per **year**

### Features

- Input: `calls.csv` file with format:  
  `YYYY-MM-DD HH:MM:SS,ContactName,DurationInSeconds`

- Outputs:
  - Total call records
  - Most talked contact each day/month/year

### Run Instructions

```bash
g++ -o callanalyzer main.cpp CallAnalyzer.cpp
./callanalyzer
