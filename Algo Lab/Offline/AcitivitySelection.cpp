#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> activitySelection(vector<pair<int, int>> &activities)
{
    vector<pair<int, int>> selectedActivities;

    sort(activities.begin(), activities.end(), [](const auto &a, const auto &b)
         { return a.second < b.second; });

    selectedActivities.push_back(activities[0]);

    for (size_t i = 1; i < activities.size(); ++i)
    {
        if (activities[i].first >= selectedActivities.back().second)
        {
            selectedActivities.push_back(activities[i]);
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