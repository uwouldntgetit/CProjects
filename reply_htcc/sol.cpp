#include <iostream>

#define LL long long int;


vector<Resource> buyResources(vector<Turn> &turns, vector<Resource> availableResources, int currentTurn, LL budget){
    vector<Resources> toBuy = new vector<Resources>;
    vector<EfficentResource> efficiency = new vector<EfficientResource>;

    for(int i = 0; i < availableResources.size(); i++){
 		EfficentResource e;
 		e.id = i;
 		e.ef = efficency(availableResources[i], turns, currentTurn);
 		efficiency.push_back(e);
    }

    int p = 0;
    for(int i = 0; i < availableResources.size(); i++){
    	for (int k = 0; k < availableResources.size(); k++){
    		if(efficiency[i].ef < efficiency[k].ef)
    			p = k;
    	}
    	EfficentResource e = efficiency[p];
    	efficiency[p] = efficiency[i];
    	efficiency[i] = e;
    }

    int cnt = 0;
    while(budget > 0 || cnt > efficiency.size()){
    	LL cost = availableResources[efficiency[cnt].pos].activationCost;
    	if(budget >= cost){
    		budget -= cost;
    		toBuy.psuh_back(availableResources[efficiency[cnt].pos]);
    	}
    	else
    		cnt++;
    }


    return toBuy;
}