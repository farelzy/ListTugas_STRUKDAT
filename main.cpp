#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    int taskID;
    string taskName;
    string course;
    string description;
    string deadline;
    bool isCompleted;

    Task(int id, string name, string course, string desc, string dead)
        : taskID(id), taskName(name), course(course), description(desc), deadline(dead), isCompleted(false) {}
};

void addTask(vector<Task> &taskList, int &taskCount) {
    string taskName, course, description, deadline;

    cout << "\nMasukkan nama tugas: ";
    getline(cin, taskName);
    cout << "Masukkan nama mata kuliah: ";
    getline(cin, course);
    cout << "Masukkan deskripsi tugas: ";
    getline(cin, description);
    cout << "Masukkan deadline (format: yyyy-mm-dd): ";
    getline(cin, deadline);

    taskCount++;
    taskList.emplace_back(taskCount, taskName, course, description, deadline);
    cout << "Tugas ID " << taskCount << " telah ditambahkan." << endl;
}