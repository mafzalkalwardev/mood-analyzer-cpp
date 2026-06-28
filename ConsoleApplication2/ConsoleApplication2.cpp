#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

// ---------------- DECISION TREE NODE ----------------
struct TreeNode {
    string question;     // For internal node
    string result;       // For leaf node
    TreeNode* yes;
    TreeNode* no;
};

// ---------------- CREATE DECISION TREE ----------------
TreeNode* createDecisionTree() {

    // Leaf nodes
    TreeNode* takeRest = new TreeNode{
        "", "You need rest. Drink chai ☕ and relax.", nullptr, nullptr };

    TreeNode* relax = new TreeNode{
        "", "You seem okay. Take a short break 😌.", nullptr, nullptr };

    TreeNode* enjoy = new TreeNode{
        "", "Mood is fresh. Enjoy your free time 😄.", nullptr, nullptr };

    TreeNode* productive = new TreeNode{
        "", "Energy is good. Focus on your tasks 💪.", nullptr, nullptr };

    // Internal decision nodes
    TreeNode* pressureHigh = new TreeNode{
        "Is your pressure level high?", "", takeRest, relax };

    TreeNode* freeTime = new TreeNode{
        "Do you have free time?", "", enjoy, productive };

    TreeNode* energyLow = new TreeNode{
        "Is your energy level low?", "", pressureHigh, freeTime };

    return energyLow; // root
}

// ---------------- TREE TRAVERSAL (LIVE PATH) ----------------
void analyzeMood(TreeNode* root) {

    TreeNode* current = root;
    string answer;

    cout << "\n--- Decision Tree Traversal ---\n\n";

    while (current->yes != nullptr && current->no != nullptr) {

        cout << "[" << current->question << "]\n";
        cout << "        |\n";
        cout << "     (yes/no): ";
        cin >> answer;

        if (answer == "yes") {
            cout << "        |\n";
            cout << "       YES\n";
            cout << "        |\n";
            current = current->yes;
        }
        else {
            cout << "        |\n";
            cout << "        NO\n";
            cout << "        |\n";
            current = current->no;
        }
    }

    cout << "[" << current->result << "]\n";
    cout << "\n--- Mood Analysis Complete ---\n";
}

// ---------------- MAIN FUNCTION ----------------
int main() {

    stack<string> emotionStack;
    queue<string> taskQueue;

    TreeNode* decisionTree = createDecisionTree();

    int choice;
    string input;

    do {
        cout << "\n========== MOOD ANALYZER ==========\n";
        cout << "1. Add Emotion\n";
        cout << "2. Add Task\n";
        cout << "3. Analyze Mood\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter emotion (any word): ";
            cin >> input;
            emotionStack.push(input);
            cout << "Emotion stored in stack.\n";
        }

        else if (choice == 2) {
            cout << "Enter upcoming task: ";
            cin >> input;
            taskQueue.push(input);
            cout << "Task stored in queue.\n";
        }

        else if (choice == 3) {
            if (emotionStack.empty()) {
                cout << "No emotions added yet.\n";
            }
            else {
                analyzeMood(decisionTree);
            }
        }

        else if (choice == 4) {
            cout << "Thank you for using Mood Analyzer!\n";
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}