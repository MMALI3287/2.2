#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> activitySelection(vector<pair<int, int>> &activities)
{
    int n = activities.size();
    vector<pair<int, int>> selectedActivities;
    selectedActivities.push_back(activities[0]);
    int lastFinishTime = activities[0].second;
    for (int i = 1; i < n; i++)
    {
        if (activities[i].first >= lastFinishTime)
        {
            selectedActivities.push_back(activities[i]);
            lastFinishTime = activities[i].second;
        }
    }

    return selectedActivities;
}

int main()
{
    vector<pair<int, int>> activities = {
        {1, 4},
        {3, 5},
        {0, 6},
        {5, 7},
        {3, 8},
        {5, 9},
        {6, 10},
        {8, 11},
        {8, 12},
        {2, 13},
        {12, 14}};

    vector<pair<int, int>> selectedActivities = activitySelection(activities);

    cout << "Selected Activities : " << selectedActivities.size() << "\n";
    for (const auto &activity : selectedActivities)
    {
        cout << "Start Time: " << activity.first << ", Finish Time: " << activity.second << endl;
    }

    return 0;
}