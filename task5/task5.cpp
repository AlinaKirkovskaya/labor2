#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;         // Унікальний ідентифікатор
    int arrival;    // Час прибуття
    int burst;      // Час виконання
    int priority;   // Пріоритет
};

void priorityScheduling(const std::vector<Process>& processes) {
    std::vector<Process> sortedProcesses = processes;
    std::sort(sortedProcesses.begin(), sortedProcesses.end(),
        [](const Process& a, const Process& b) { return a.priority < b.priority; });

    std::cout << "\nPriority Scheduling Execution:\n";
    std::cout << "ID\tBurst\tPriority\n";
    for (const auto& p : sortedProcesses) {
        std::cout << p.id << "\t" << p.burst << "\t" << p.priority << "\n";
    }
}

double calculateAverage(const std::vector<int>& times) {
    int sum = 0;
    for (int t : times) sum += t;
    return static_cast<double>(sum) / times.size();
}

int main() {
    std::vector<Process> processes = {
        {1, 0, 7, 3}, {2, 2, 4, 1}, {3, 4, 1, 2}, {4, 5, 4, 4}, {5, 6, 3, 5}
    };

    std::cout << "ID\tArrival\tBurst\tPriority\n";
    for (const auto& p : processes) {
        std::cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.priority << "\n";
    }

    priorityScheduling(processes);
    return 0;
}