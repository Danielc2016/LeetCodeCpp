class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int size = (int) gas.size();
        int remainGas = 0, candidate = 0;
        int totalRemain = 0;
        for(int i = 0; i < size; i++)
        {
            remainGas += (gas[i] - cost[i]);
            totalRemain += (gas[i] - cost[i]);
            if(remainGas < 0)
            {
                candidate = i + 1;
                remainGas = 0;
            }
        }
        return totalRemain < 0 ? -1 : candidate;
    }
};

/*
implementation:
Greedy?:
linear -> start from index 0 and try to reach every next station
by using the remain gas:

gas station: 1 ,2, 3, 4, 5

cost: 3, 4, 5, 1, 2

first condition: gas[i] > cost[i]

for next condition:

   if remain gas cannot get to the next station(i):
      try to start from station(i+1)

exit condition:
    if no station works: return -1
   

*/
