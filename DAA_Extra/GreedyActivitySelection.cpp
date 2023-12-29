#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> activities;

int main()
{
    int n;
    cout << "Enter the number of Activities: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int start, finish;
        cout << "Enter the start and finish time of the activities: start finish: ";
        cin >> start >> finish;
        while (start >= finish)
        {
            cout << "Start time cannot be greater than or equal to finish time, enter again: ";
            cin >> start >> finish;
        }
        activities.push_back(make_pair(start, finish));
    }

    sort(activities.begin(), activities.end(), [](auto &left, auto &right)
         { return left.second < right.second; });

    int jobs = 0;
    vector<pair<int, int>> jobList;

    for (int i = 0; i < activities.size(); i++)
    {
        if (i == 0)
        {
            jobs++;
            jobList.push_back(activities[i]);
        }
        else
        {
            if (activities[i].first >= jobList.back().second)
            {
                jobs++;
                jobList.push_back(activities[i]);
            }
        }
    }

    cout << "The maximum number of jobs that can be done are: " << jobs << endl;
    cout << "The jobs that can be done are: ";
    for (auto job : jobList)
    {
        cout << "(" << job.first << "," << job.second << ") ";
    }
    cout << endl;

    return 0;
}
