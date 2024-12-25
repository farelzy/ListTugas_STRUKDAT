#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Task {
    int taskID;
    string taskName;
    string course;
    string description;
    string deadline;
    bool isCompleted;
    Task* prev;
    Task* next;

    Task(int id, string name, string course, string desc, string dead)
        : taskID(id), taskName(name), course(course), description(desc), deadline(dead), isCompleted(false), prev(nullptr), next(nullptr) {}
};

class TaskManager {
private:
    Task* head;
    Task* tail;
    int taskCount;

public:
    TaskManager() : head(nullptr), tail(nullptr), taskCount(0) {}

    void addTask() {
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
        Task* newTask = new Task(taskCount, taskName, course, description, deadline);

        if (head == nullptr) {
            head = tail = newTask;
        } else{}
    }

    void displayTasks() {
        if (head == nullptr) {
            cout << "\nTidak ada tugas." << endl;
            return;
        }

        Task* temp = head;
        while (temp != nullptr) {
            cout << "\nTugas ID : " << temp -> taskID
                 << "\nNama : " << temp->taskName
                 << "\nMata Kuliah : " << temp->course
                 << "\nDeskripsi : " << temp->description
                 << "\nDeadline : " << temp-> deadline
                 << "\nStatus : " << (temp->isCompleted ? "Selesai" : "Belum Selesai") << endl;
            temp = temp->next;
        }
    }
     void editTask() {
        int id;
        cout << "\nMasukkan ID tugas yang akan diubah: ";
        cin >> id;
        cin.ignore();

        Task* temp = head;
        while (temp != nullptr && temp->taskID != id) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Tugas dengan ID " << id << " tidak ditemukan." << endl;
            return;
        }

        cout << "Masukkan nama tugas baru: ";
        getline(cin, temp->taskName);
        cout << "Masukkan nama mata kuliah baru: ";
        getline(cin, temp->course);
        cout << "Masukkan deskripsi tugas baru: ";
        getline(cin, temp->description);
        cout << "Masukkan deadline baru (format: yyyy-mm-dd): ";
        getline(cin, temp->deadline);
        cout << "Tugas ID " << id << " berhasil diubah." << endl;
    }
    void popTask() {
        if (head == nullptr) {
            cout << "Tidak ada tugas untuk dihapus." << endl;
            return;
        }

        Task* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }

        cout << "Tugas ID " << temp->taskID << " berhasil dihapus." << endl;
        delete temp;
    }
};
