
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <ctime>

struct Process {
    int id;         // Унікальний ідентифікатор
    int arrival;    // Час прибуття
    int burst;      // Час виконання
    int priority;   // Пріоритет
};

std::vector<Process> generateProcesses(int n) {
    std::vector<Process> processes;
    srand(time(nullptr));
    for (int i = 0; i < n; ++i) {
        processes.push_back({ i + 1, rand() % 10, rand() % 10 + 1, rand() % 5 + 1 });
    }
    return processes;
}

void printProcesses(const std::vector<Process>& processes) {
    std::cout << "ID\tArrival\tBurst\tPriority\n";
    for (const auto& p : processes) {
        std::cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.priority << "\n";
    }
}

int main() {
    int n = 5; // Кількість процесів
    auto processes = generateProcesses(n);
    printProcesses(processes);
    return 0;
}