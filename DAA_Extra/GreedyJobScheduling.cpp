#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}

pair<int, int> jobScheduling(vector<pair<int, int>> &jobs){
    
    sort(jobs.begin(), jobs.end(), compare);
    int maxDeadline = (*max_element(jobs.begin(), jobs.end(), [](pair<int, int> a, pair<int, int> b)
                                    { return a.second < b.second; })).second;
    vector<int> jobList(maxDeadline + 1, 0);
    int jobsDone = 0, profit = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        for (int j = jobs[i].second; j > 0; j--)
        {
            if (jobList[j] == 0)
            {
                jobList[j] = 1;
                jobsDone++;
                profit += jobs[i].first;
                break;
            }
        }
    }
    return {jobsDone, profit};
}

int main()
{
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++)
    {
        int profit, deadline;
        cout << "Enter the profit and deadline of the job " << i + 1 << ": ";
        cin >> profit >> deadline;
        jobs[i] = {profit, deadline};
    }
    pair<int, int> result = jobScheduling(jobs);
    cout << "The maximum profit that can be earned is: " << result.second << endl;
    cout << "The jobs that can be done are: " << result.first << endl;
    return 0;
}
