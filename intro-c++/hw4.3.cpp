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

string DeltaVComparator(double RBCResult, double Mass){
    double TargetVelocity = 10.9;

    // under-speed
    if(RBCResult < (TargetVelocity - 0.05)){
        cout << "\nInsufficient Velocity. Risk of Earth Re-entry. Secondary Burn Required." << endl;
        return "under-speed";
    }
    // over-speed
    else if(RBCResult > (TargetVelocity + 0.05)){
        cout << "\nExcessive Velocity. Trajectory exceeds Lunar Gravity Well. Course correction required." << endl;
        return "over-speed";
    }
    // within Tolerance
    else{
        cout << "\nTrajectory Nominal. Artemis II is on course for Lunar Flyby." << endl;
        if(Mass > 25000){
            cout << "WARNING: Heavy Load detected. Monitor fuel reserves for re-entry.";
        }
        return "Nominal";
    }
}

int main(){
    int EngineSelection;
    double FinalBurnVelocity, Mass;
    double RBCResult;
    string MissionStatus;

    while(true){

        cout << "===============================================================================\n\n";
        cout << "     ARTEMIS II Lunar Free-Return Trajectory Calculator Simulation Program     \n\n";
        cout << "===============================================================================\n\n";

        cout << "ENGINES: AJ10-190(1). RCS Thrusters(2). Emergency Abort Motor(3).\n\n";

        cout << " -- Enter Engine ID: "; cin >> EngineSelection;
        cout << " -- Enter Final Burn Velocity: "; cin >> FinalBurnVelocity;
        cout << " -- Mass of the Spacecraft: "; cin >> Mass;

        if (FinalBurnVelocity <= 0 || Mass <= 0) {
            cout << "\n -!- Diagnostic Error: Velocity and Mass must be positive values. Please re-enter data.\n\n";
            continue; 
        }

        RBCResult = RocketBurnCalculator(EngineSelection, FinalBurnVelocity, Mass);
            if(RBCResult == -1){
                cout << "\n -!- ID Error: No engine with that ID was found. Try Again.\n\n";
                continue;
            } else {
                break; // this should exit the loop if RBCResult is not -1
            }
    }


    MissionStatus = DeltaVComparator(RBCResult, Mass);
    cout << "\n===============================================================================\n";
    if (MissionStatus == "Nominal") {
        cout << "        SIGN-OFF: Godspeed, Orion. See you on the dark side of the Moon.\n";
    } else if (MissionStatus == "under-speed") {
        cout << "        SIGN-OFF: Secondary Burn Needed. Ground Control Notified.\n";
    } else {
        cout << "        SIGN-OFF: Pilot intervention required. Ground Control Notified.\n";
    }
    cout << "===============================================================================\n";

    return 0;
    // to do: 
    // instructions, greetings, and decorations [done]
    // sign offs depending on status of DVC (optional) [done]

    return 0;
}