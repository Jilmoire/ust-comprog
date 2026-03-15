// Date Created: March 14, 2026

#include <iostream>
#include <cstdlib> // Necessary for exit()

using namespace std;

void runExample(int choice) {
    cout << "\n--- Iteration Loop for choice " << choice << " ---" << endl;
    
    for (int i = 1; i <= 3; i++) {
        if (i == 2) {
            if (choice == 1) {
                cout << "  [Continue at 2]" << endl;
                continue; // Skips only the rest of this specific iteration
            }
            if (choice == 2) {
                cout << "  [Break at 2]" << endl;
                break;    // Exits this loop entirely
            }
            if (choice == 3) {
                cout << "  [Return at 2]" << endl;
                return;   // Exits this entire function immediately
            }
            if (choice == 4) {
                cout << "  [Exit at 2]" << endl;
                exit(0);  // Terminates the entire program immediately
            }
        }
        cout << "  Loop value: " << i << endl;
    }
    cout << "End of function reached." << endl;
}

int main() {
    // We call the function with different control flow types
    runExample(1); // Test Continue
    runExample(2); // Test Break
    runExample(3); // Test Return
    runExample(4); // Test Exit
    
    cout << "\nThis line is in main()." << endl;
    return 0;
}
