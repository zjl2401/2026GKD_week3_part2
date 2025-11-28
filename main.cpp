#include <iostream>
#include <sstream>
#include "TaskScheduler.h"
using namespace std;

int main() {
    TaskScheduler scheduler;
    string line;

    while (getline(cin, line)) {
        if (line == "退出") break;

        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if (cmd == "添加机器人") {
            string name; ss >> name;
            scheduler.addRobot(name);
        }
        else if (cmd == "添加任务") {
            string robotName, desc;
            int id, priority;
            ss >> robotName >> id >> desc >> priority;
            Robot* rob = scheduler.getRobot(robotName);
            if (rob) rob->addTask(id, desc, priority);
        }
        else if (cmd == "撤销任务") {
            string robotName; ss >> robotName;
            Robot* rob = scheduler.getRobot(robotName);
            if (rob) rob->undoTask();
        }
        else if (cmd == "执行任务") {
            string robotName; ss >> robotName;
            Robot* rob = scheduler.getRobot(robotName);
            if (rob) rob->executeTask();
        }
        else if (cmd == "删除机器人") {
            string robotName; ss >> robotName;
            scheduler.deleteRobot(robotName);
        }
        else if (cmd == "查询任务") {
            string robotName; ss >> robotName;
            Robot* rob = scheduler.getRobot(robotName);
            if (rob) rob->showTasks();
        }
        else if (cmd == "获取机器人名称列表") {
            for (const auto& n : scheduler.getRobotNames()) cout << n << endl;
        }
    }

    return 0;
}
