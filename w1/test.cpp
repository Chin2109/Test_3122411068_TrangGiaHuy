#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

struct TestCase {
    string input;
    string expected;
};

int main() {
    vector<TestCase> tests = {
        {"0 0 0\n", "Infinite solutions."},
        {"0 0 1\n", "No solution."},
        {"0 1 1\n", "No solution."},
        {"0 1 -1\n", "The equation has 2 real solution(s):"},
        {"1 0 1\n", "No solution."},
        {"1 0 -1\n", "The equation has 2 real solution(s):"},
        {"1 -2 1\n", "The equation has 2 real solution(s):"}
    };

    int passed = 0;
    for (size_t i = 0; i < tests.size(); i++) {
        // chạy chương trình chính b1.exe với input
        string cmd = "echo \"" + tests[i].input + "\" | ./b1";
        FILE* pipe = popen(cmd.c_str(), "r");
        if (!pipe) {
            cerr << "Không mở được pipe.\n";
            return 1;
        }

        char buffer[256];
        string output = "";
        while (fgets(buffer, sizeof(buffer), pipe)) {
            output += buffer;
        }
        pclose(pipe);

        if (output.find(tests[i].expected) != string::npos) {
            cout << "Case " << i+1 << " PASSED\n";
            passed++;
        } else {
            cout << "Case " << i+1 << " FAILED\n";
            cout << " Input: " << tests[i].input;
            cout << " Expected: " << tests[i].expected << "\n";
            cout << " Got: " << output << "\n";
        }
    }

    cout << passed << "/" << tests.size() << " tests passed.\n";
    return 0;
}
