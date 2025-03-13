// Import libraries
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>    
using namespace std;

// Define LL as long long int
#define LL long long int

// Define global variables
LL initialBudget;
LL currentBudget;
LL totalResouceCount;
LL numberOfGameTurns;
LL totalProfit;

void updateTotalProfit(LL profit){
    totalProfit += profit;
}

// Create resource class
struct Resource{
    // Define resource properties
    LL identifier;
    LL activationCost;   //marker
    LL periodicCost;
    LL upTime;
    LL downTime;
    LL lifeCycle;
    LL powerableBuildings;
    char specialEffect;
    LL impact;
    // Define resource methods
};

// Create turn struct
struct Turn{
    // Define turn properties
    LL turnNumber;
    LL minBuilds;
    LL maxBuilds;
    LL profitPerBuild;
};

struct PurchasedResource{
    Resource r;
    // num of turns 
    LL age;
};

struct EfficientResource{
    LL pos;
    long double ef;
};


LL totalResourceCost(LL lifeTime, LL activationCost, LL costPerTurn, LL remainingTurns){
    if(remainingTurns < lifeTime)
        return activationCost + (remainingTurns * costPerTurn);
    else
        return activationCost + (lifeTime * costPerTurn);
}

// calculate efficency of a single resource
double calculateEfficiencyBasic(LL totalCost, LL numBuildings, LL percent){
    double k = ((double)numBuildings / (double)totalCost);
    return ((double)percent / 100.0) * k + k;
}

LL min (LL a, LL b){
    if(a < b) 
        return a;
    else 
        return b;
}

LL profit(int n , int tr){
    return n * tr;
}

// Choose file to read
string chooseFile(int num){
    string fileName;
    switch(num){
        case 0:
            fileName = "Inputs/0-demo.txt";
            break;
        case 1:
            fileName = "Inputs/1-thunberg.txt";
        case 2:
            fileName = "Inputs/2-attenborough.txt";
            break;
        case 4:
            fileName = "Inputs/4-maathai.txt";
            break;
        case 6:
            fileName = "Inputs/6-earle.txt";
            break;
        case 8:
            fileName = "Inputs/8-shiva.txt";
            break;
        default:
            cout << "ERROR: Invalid file number" << endl;
            break;
    }
    return fileName;
}

// Read input file amd add date to vectors that are passed  by reference
void readFile(vector<Resource> &resources, vector<Turn> &turnDetails)
{
    string fileName = chooseFile(0);
    fstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cerr << "Error opening " << fileName << endl;
        exit(1);
    }
    // Read input file
    inFile >> initialBudget;
    cout << "Initial Budget: " << initialBudget << endl;
    inFile >> totalResouceCount;
    inFile >> numberOfGameTurns;

    // Read resource data
    for(int i = 0; i < totalResouceCount; i++){
        Resource r;
        inFile >> r.identifier;
        inFile >> r.activationCost;
        inFile >> r.periodicCost;
        inFile >> r.upTime;
        inFile >> r.downTime;
        inFile >> r.lifeCycle;
        inFile >> r.powerableBuildings;
        inFile >> r.specialEffect;
        if(r.specialEffect == 'X'){
            r.impact = 0;
        }
        else{
            inFile >> r.impact;
        }
        resources.push_back(r);
    }

    // Read turn data
    for(int i = 0; i < numberOfGameTurns; i++){
        Turn t;
        t.turnNumber = i;
        inFile >> t.minBuilds;
        inFile >> t.maxBuilds;
        inFile >> t.profitPerBuild;
        turnDetails.push_back(t);
    }
    
    inFile.close();
}

void testReadingValues(const vector<Resource>& resources, const vector<Turn>& turnDetails) {
    cout << "Initial Budget: " << initialBudget << endl;
    cout << "Total Resource Count: " << totalResouceCount << endl;
    cout << "Number of Game Turns: " << numberOfGameTurns << endl;
    cout << "Resource Data: " << endl;
    for(int i = 0; i < totalResouceCount; i++){
        cout << resources[i].identifier << " " << resources[i].activationCost << " " << resources[i].periodicCost << " " << resources[i].upTime << " " << resources[i].downTime << " " 
        << resources[i].lifeCycle << " " << resources[i].powerableBuildings << " " << resources[i].specialEffect << " " << resources[i].impact << endl;
    }
    cout << "Turn Data: " << endl;
    for(int i = 0; i < numberOfGameTurns; i++){
        cout << turnDetails[i].turnNumber << " " << turnDetails[i].minBuilds << " " << turnDetails[i].maxBuilds << " " << turnDetails[i].profitPerBuild << endl;
    }
}


long double avgT (int currentTurn, vector<Turn> &turns, Resource r){
    int remainingTurns = turns.size() - currentTurn;
    int sum2 = 0;
    int sum = 0;
    int k, h;
    
    int dividendo = r.lifeCycle > remainingTurns ? remainingTurns : r.lifeCycle;
    int pos = currentTurn;

    while(remainingTurns > 0){
        // activationTurn--;
        k = r.upTime;
        while(k > 0){
            if(pos >= turns.size()){
                break;
            }
            sum += turns[pos].profitPerBuild;
            sum2 += turns[pos].minBuilds;
            pos++;
            k--;
        }
        pos += r.downTime;
        
        remainingTurns -= r.upTime + r.downTime;
    }

    return (sum/dividendo) * (sum2/dividendo);
}


long double avgTr (int currentTurn, vector<Turn> &turns, Resource r){
    int remainingTurns = turns.size() - currentTurn;
    int sum = 0;
    int k, h;
    
    int dividendo = r.lifeCycle > remainingTurns ? remainingTurns : r.lifeCycle;
    int pos = currentTurn;

    while(remainingTurns > 0){
        k = r.upTime;
        while(k > 0){
            if(pos >= turns.size()){
                break;
            }
            sum += turns[pos].profitPerBuild;
            pos++;
            k--;
        }
        pos += r.downTime;
        
        remainingTurns -= r.upTime + r.downTime;
    }

    return sum/dividendo;
}

int duration (Resource r,int currentTurn, int maxturns){
    int num = 0;
    int active = r.upTime;
    int inactive = r.downTime;
    int counter = 0;
    int remainingTurns = maxturns - currentTurn;
    
    if(r.lifeCycle < remainingTurns) remainingTurns = r.lifeCycle; 



    while(remainingTurns > 0){
        
        if(active > 0){
            num++;
            active--;
        }
        if(counter == r.downTime){
            active = r.upTime;
            counter = 0;
        }
        if(active == 0){
            counter++;
        }
        remainingTurns--;
    }

    return num;

}



/*
long double avgTr (int currentTurn, vector<Turn> &turns, Resource r){
    int remainingTurns = turns.size() - currentTurn;
    int sum = 0;
    int sum2 = 0;
    int k = r.upTime, h = r.downTime;
    bool up = true, down = false;
    
    //if(activationTurn > remainingTurns) activationTurn = remainingTurns;
    
    // int dividendo = activationTurn;
    int pos = currentTurn - 1;
    
    

    
    while(remainingTurns > 0){
       
    }

    return sum/dividendo;
}*/




double timeEfficency(Resource r, int currentTurn,int timemax){

    if((timemax - currentTurn) < r.upTime) return 1;
    return r.upTime/r.downTime;

}





long double avgTm(int current){
    return 0;
}

LL calculateBuildPoweredThisRound(vector<PurchasedResource> &purchasedResources, LL rscPurchasedThisTurn)
{
    LL buldingsPoweredThisRound = 0;
    for(int i = purchasedResources.size(); i > purchasedResources.size() - rscPurchasedThisTurn; i--)
    {
        buldingsPoweredThisRound += purchasedResources[i].r.powerableBuildings;
    }

    return buldingsPoweredThisRound;
}

/*LL totalResourceCost(LL lifeTime, LL activationCost, LL costPerTurn, LL remainingTurns){
    if(remainingTurns < lifeTime)
        return activationCost + (remainingTurns * costPerTurn);
    else
        return activationCost + (lifeTime * costPerTurn);
}*/

long double efficency(Resource r, vector<Turn> &turns, int currentTurn){

    LL remainingTurns = turns.size() - currentTurn;
    long double avgt = avgT(currentTurn,turns,r);
    LL dur = duration(r,currentTurn,turns.size());
    //impact

    int time = timeEfficency(r,currentTurn,turns.size());
    LL totalCost = totalResourceCost(r.lifeCycle,r.activationCost,r.periodicCost,remainingTurns);
    
    long double gain = dur * avgt;

    return (gain * time) / totalCost;
    

}

int efficenza2 (Resource r){
    if(r.specialEffect == 'E') return 0; 
    return r.powerableBuildings * r.impact;
}

vector<Resource> buyResources(vector<Turn> &turns, vector<Resource> availableResources, int currentTurn, LL budget){
    vector<Resource> resToBuy;
    vector<EfficentResource> effc;

    for(int i = 0; i < availableResources.size(); i++){
 		EfficentResource e;
 		e.id = i;
 		e.ef = efficency(availableResources[i], turns, currentTurn);
 		effc.push_back(e);
    }

    int p = 0;
    for(int i = 0; i < availableResources.size(); i++){
    	for (int k = 0; k < availableResources.size(); k++){
    		if(effc[i].ef < effc[k].ef)
    			p = k;
    	}
    	EfficentResource e = effc[p];
    	effc[p] = effc[i];
    	effc[i] = e;
    }

    int cnt = 0;
    while(budget > 0 || cnt > effc.size()){
    	LL cost = availableResources[effc[cnt].pos].activationCost;
    	if(budget >= cost){
    		budget -= cost;
    		resToBuy.push_back(availableResources[effc[cnt].pos]);
    	}
    	else
    		cnt++;
    }


    return resToBuy;
}



void gameLogic(LL& currentTurn, vector<Resource> &resources, vector<Turn> &turnDetails,
                vector<PurchasedResource>  &purchasedResources, fstream &outFile)
{
    outFile << currentTurn << " ";
    cout << currentTurn << " ";
    
    LL rscPurchasedThisTurn = 0;
    // Stage 1: Purchase resources (the less expensive the better)
    long double bestEfficiency = -999999;
    int bestIndex = -1;
    for (int i = 0; i < resources.size(); i++) {
        if(resources[i].activationCost <= currentBudget && i != 4)
        {
            if(efficency(resources[i],turnDetails,currentTurn) > bestEfficiency){
                bestEfficiency = efficency(resources[i],turnDetails,currentTurn);
                bestIndex = i;
            }
        }   
    }
    if (bestIndex != -1) {
        cout << "Found resource to purchase at " << bestIndex << endl;
        currentBudget -= resources[bestIndex].activationCost;
        PurchasedResource pr;
        pr.r = resources[bestIndex];
        pr.age = 0;
        purchasedResources.push_back(pr);
        rscPurchasedThisTurn++;
    }
    cout << "Current budget: " << currentBudget << endl;
    // Stage 2: Pay periodic costs
    for(int i = 0; i < purchasedResources.size(); i++){
        currentBudget -= purchasedResources[i].r.periodicCost;
    }
    // Stage 3: Calculate turn profit and update budget
    // First calculate the total number of buildings powered by the resources that were purchased this round
    LL buildingsPoweredThisRound = calculateBuildPoweredThisRound(purchasedResources, rscPurchasedThisTurn);
    cout << "Buildings powered this round: " << buildingsPoweredThisRound << endl;

    // If minBuilds reuirement is met then calculate profit
    if(buildingsPoweredThisRound >= turnDetails[currentTurn].minBuilds)
    {
        LL profit = min(buildingsPoweredThisRound, turnDetails[currentTurn].maxBuilds) * turnDetails[currentTurn].profitPerBuild;
        currentBudget += profit;
        cout << "Profit: " << profit << ", adding to budget" << endl;
        updateTotalProfit(profit);
    }

    // Print count of resources purchased this turn and their identifiers
    outFile << rscPurchasedThisTurn << " ";
    cout << rscPurchasedThisTurn << " ";
    
    // Loop over resources purchased this round and print their identifiers, start and end
    for(int i = purchasedResources.size(); i > purchasedResources.size() - rscPurchasedThisTurn; i--){
        outFile << purchasedResources[i].r.identifier << " ";
        cout << purchasedResources[i].r.identifier << " ";
    }

    // Go to next turn
    currentTurn++;
    
    outFile << endl;
    cout << endl;
}

int main()
{
    // Define output file
    fstream outFile;
    outFile.open("output.txt", ios::out);
    if(outFile.fail()){
        cerr << "Error opening output file" << endl;
        exit(1);
    }

    // Create a vector to store resources
    vector<Resource> resources;
    // Create a vector to store turn details
    vector<Turn> turnDetails;
    // Read input file
    readFile(resources, turnDetails);

    // testReadingValues(resources, turnDetails);
    
    LL currentTurn = 0;
    currentBudget = initialBudget;
    vector<PurchasedResource> purchasedResources;
    while(currentTurn < numberOfGameTurns && currentBudget > 0)
    {
        gameLogic(currentTurn, resources, turnDetails, purchasedResources, outFile);
    }

    outFile.close();
    return 0;
}