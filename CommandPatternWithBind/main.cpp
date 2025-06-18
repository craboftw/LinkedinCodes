#include <iostream>
#include <vector>
#include <functional>
#include <string>

void log(const std::string& msg, int level) {
    std::cout << "[Level " << level << "] " << msg << '\n';
}

struct Robot {
    void move(int x, int y) {
        std::cout << "🤖 Moving to (" << x << "," << y << ")\n";
    }
};

struct User {
    std::string name;
    void greet() const {
        std::cout << "👋 Hi, I'm " << name << '\n';
    }
};

void heavyTask(bool debug) {
    if (debug) std::cout << "⏳ Running crazy task in debug mode...\n";
    else std::cout << "🚀 Running crazy task...\n";
}

int main() {
    std::vector<std::function<void()>> tasks;

    // 1. Free function with arguments
    tasks.push_back(std::bind(log, "System initialized", 1));

    // 2. Member function with parameters
    Robot robot;
    tasks.push_back(std::bind(&Robot::move, &robot, 10, 20));

    // 3. Const member function with an object
    User user{"Pakito"};
    tasks.push_back(std::bind(&User::greet, user));

    // 4. Lambda with captured state
    int counter = 42;
    tasks.push_back([counter]() {
        std::cout << "🧮 Current counter: " << counter << '\n';
    });

    // 5. Static/global function with a boolean argument
    tasks.push_back(std::bind(heavyTask, true));

    // 6. Inline anonymous lambda
    tasks.push_back([]() {
        std::cout << "📡 Checking connection...\n";
    });

    std::cout <<"Init tasks ⚒️"<<std::endl;
    // 🔁 Execute all tasks
    for (auto& task : tasks) {
        task();  // Everything behaves like a simple void()
    }
}
