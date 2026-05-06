#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

double RocketBurnCalculator(int EngineSelection, double FinalBurnVelocity, double Mass){
    double EffectiveDeltaV = 0; 
    double k; // k is the Thrust-Efficiency Factor
    switch(EngineSelection){
        case 1:
            k = 1.0;
            break;
        case 2:
            k = 0.2;
            break;
        case 3:
            k = 2.5;
            break;
        default:
            return -1; // no such engine is found and will make the main() loop this function
    }

    return EffectiveDeltaV = FinalBurnVelocity*k;
}

string DeltaVComparator(double RBCResult){
    double TargetVelocity = 10.9;

    // under-speed
    if(RBCResult < (TargetVelocity - 0.05)){
        cout << "Insufficient Velocity. Risk of Earth Re-entry. Secondary Burn Required." << endl;
        return "under-speed";
    }
    // over-speed
    else if(RBCResult > (TargetVelocity + 0.05)){
        cout << "Excessive Velocity. Trajectory exceeds Lunar Gravity Well. Course correction required." << endl;
        return "over-speed";
    }
    // within Tolerance
    else{
        cout << "Trajectory Nominal. Artemis II is on course for Lunar Flyby." << endl;
        if(Mass > 25000){
            cout << "WARNING: Heavy Load detected. Monitor fuel reserves for re-entry."
        }
        return "Nominal";
    }
}

int main(){
    int EngineSelection;
    double FinalBurnVelocity, Mass;

    while(true){
        cout << "Enter Engine ID: "; cin >> EngineSelection;
        cout << "Enter Final Burn Velocity: "; cin >> FinalBurnVelocity;
        cout << "Mass of the Spacecraft: "; cin >> Mass;

        double RBCResult = RocketBurnCalculator(EngineSelection, FinalBurnVelocity, Mass);
            if(RBCResult == -1){
                cout << "No engine with that ID was found. Try Again.";
                continue;
            } else {
                break; // this should exit the loop if RBCResult is not -1
            }
    }
    DeltaVComparator(RBCResult); // will take the result of calculations and then prints out all thhe information needed to be printed

    // to do: 
    // instructions, greetings, and decorations
    // encouragement, warning sign offs depending on status of DVC (Optional)

    return 0;
}