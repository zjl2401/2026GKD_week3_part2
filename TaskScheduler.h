#pragma once
#include <map>
#include <string>
#include <vector>
#include "TaskRobot.h"
using namespace std;

class TaskScheduler {
private:
    map<string, Robot> robots;

public:
    void addRobot(const string& name) {
        robots[name] = Robot(name);
    }

    void deleteRobot(const string& name) {
        robots.erase(name);
    }

    bool hasRobot(const string& name) const {
        return robots.find(name) != robots.end();
    }

    Robot* getRobot(const string& name) {
        if (!hasRobot(name)) return nullptr;
        return &robots.at(name);
    }

    vector<string> getRobotNames() const {
        vector<string> names;
        for (const auto& kv : robots) names.push_back(kv.first);
        return names;
    }
};
