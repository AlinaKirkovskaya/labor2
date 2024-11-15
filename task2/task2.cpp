#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Process {
    int id;         // Унікальний ідентифікатор
    int arrival;    // Час прибуття
    int burst;      // Час виконання
    int priority;   // Пріоритет
};

void roundRobin(const std::vector<Process>& processes, int quantum) {
    std::queue<Process> q;
    for (const auto& p : processes) q.push(p);

    int time = 0;
    std::cout << "\nRound Robin Execution:\n";
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        if (current.arrival <= time) {
            int executedTime = std::min(current.burst, quantum);
            current.burst -= executedTime;
            time += executedTime;

            std::cout << "Process " << current.id << " executed for " << executedTime << " units. ";
            if (current.burst > 0) {
                q.push(current);
                std::cout << "Remaining burst: " << current.burst << "\n";
            }
            else {
                std::cout << "Finished!\n";
            }
        }
        else {
            time++;
            q.push(current);
        }
    }
}

int main() {
    int n = 5; // Кількість процесів
    int quantum = 3;
    std::vector<Process> processes = {
        {1, 0, 7, 3}, {2, 2, 4, 1}, {3, 4, 1, 2}, {4, 5, 4, 4}, {5, 6, 3, 5}
    };

    std::cout << "ID\tArrival\tBurst\tPriority\n";
    for (const auto& p : processes) {
        std::cout << p.id << "\t" << p.arrival << "\t" << p.burst << "\t" << p.priority << "\n";
    }

    roundRobin(processes, quantum);
    return 0;
}