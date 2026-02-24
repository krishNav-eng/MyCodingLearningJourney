#include <bits/stdc++.h>
using namespace std;


/*
LOGIC:
    Set totalTime (which is the time required to be in the line to buy required number of tickets) = 0;
    Set targetTickets (required number of tickets to buy) = tickets[k];

    Iterate through the tickets :
        Check if current person's index is before k, then add min(tickets[i], t)
*/


class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int totalTime=0;
        int targetTickets=tickets[k];
        for(int i=0;i<tickets.size();i++) {
            if(i<=k) totalTime+=min(tickets[i], targetTickets);
            else totalTime+=min(tickets[i], targetTickets-1);
        }
        return totalTime;
    }
};


/*
LOGIC: Using Queue:
    Create a Queue storing the index of the person as they but tickets one by one.
    Create a integer to store time elapsed.
    Loop while queue is not empty:
        1. Get the index of the person in the front of queue. (=i)
        2. If that person's index == k and tickets[i] == 0 return the time and break the infinte loop.
        3. Else decrement the person's tickets count by 1.

*/

class QueueSolution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        queue<int> q;
        for(int i=0;i<tickets.size();i++) {
            q.push(i);
        }
        while(!q.empty()){
            time++;
            int personIdx=q.front();
            q.pop();
            tickets[personIdx]--;
            if(personIdx==k && tickets[k]==0) break;
            if(tickets[personIdx]>0) q.push(personIdx);
        }
        return time;
    }
}