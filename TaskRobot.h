#pragma once
#include <iostream>
#include <set>
#include <string>
using namespace std;

// ======= Task 类 =======
class Task {
private:
    int id;
    string desc;
    int priority;
    string state; // "待执行" 或 "已执行"

public:
    Task(int _id = 0, string _desc = "", int _priority = 0)
        : id(_id), desc(_desc), priority(_priority), state("待执行") {}

    void execute() { state = "已执行"; }

    int getId() const { return id; }
    string getDesc() const { return desc; }
    int getPriority() const { return priority; }
    string getState() const { return state; }

    // 重载 < 运算符，用于 set 排序（按优先级从大到小，如果相同按ID从小到大）
    bool operator<(const Task& other) const {
        if (priority != other.priority)
            return priority > other.priority; // 大的优先级排前面
        return id < other.id;
    }
};

// ======= Robot 类 =======
class Robot {
private:
    string name;
    set<Task> tasks;

public:
    Robot(string _name = "") : name(_name) {}

    void addTask(int id, const string& desc, int priority) {
        tasks.insert(Task(id, desc, priority));
    }

    void undoTask() {
        if (!tasks.empty()) {
            // 删除优先级最小的任务
            auto it = prev(tasks.end());
            tasks.erase(it);
        }
    }

    void executeTask() {
        if (!tasks.empty()) {
            // 执行优先级最大的任务（set 开头）
            auto it = tasks.begin();
            Task t = *it;
            const_cast<Task&>(*it).execute(); // 修改状态
            tasks.erase(it); // 从 set 中移除已执行任务
            // 可选择保留已执行任务，如果需要可以插回
        }
    }

    void showTasks() const {
        for (const auto& t : tasks) {
            cout << "任务ID: " << t.getId()
                 << ", 描述: " << t.getDesc()
                 << ", 优先级: " << t.getPriority()
                 << ", 状态: " << t.getState() << endl;
        }
    }
};
