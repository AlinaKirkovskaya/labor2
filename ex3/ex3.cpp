#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;         // Унікальний ідентифікатор
    int arrival;    // Час прибуття
    int burst;      // Час виконання
    int priority;   // Пріоритет
};

void fcfs(const std::vector<Process>& processes) {
    std::vector<Process> sortedProcesses = processes;
    std::sort(sortedProcesses.begin(), sortedProcesses.end(),
        [](const Process& a, const Process& b) { return a.arrival < b.arrival; });

    int currentTime = 0;
    std::cout << "\nFCFS Execution:\n";
    std::cout << "ID\tStart\tFinish\tWaiting\n";
    for (const auto& p : sortedProcesses) {
        int start = std::max(currentTime, p.arrival);
        int finish = start + p.burst;
        int waiting = start - p.arrival;
        currentTime = finish;

        std::cout << p.id << "\t" << start << "\t" << finish << "\t" << waiting << "\n";
    }
}

int main() {
    std::vector<Process> processes = {
        {1, 0, 7, 3}, {2, 2, 4, 1}, {3, 4, 1, 2}, {4, 5, 4, 4}, {5, 6, 3, 5}
    };

    std::cout << "ID\tArrival\tBurst\tPriority\n";
    for (const auto& p : processes) {
        std::cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.priority << "\n";
    }

    fcfs(processes);
    return 0;
}