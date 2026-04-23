#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Activity {
    int start;
    int finish;
};

vector<Activity> selectActivities(vector<Activity> activities) {
    // Sort by finish time so greedy picks can be optimal.
    sort(activities.begin(), activities.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });

    vector<Activity> selected;
    if (activities.empty()) {
        return selected;
    }

    selected.push_back(activities[0]);
    int lastFinish = activities[0].finish;

    // Keep picking the next activity that does not overlap.
    for (int i = 1; i < static_cast<int>(activities.size()); i++) {
        if (activities[i].start >= lastFinish) {
            selected.push_back(activities[i]);
            lastFinish = activities[i].finish;
        }
    }

    return selected;
}

int main() {
    // Each pair is {start, finish} time of an activity.
    vector<Activity> activities = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9}
    };

    vector<Activity> selected = selectActivities(activities);
    cout << "Selected activities (start, finish):\n";
    for (const auto & act : selected) {
        cout << "(" << act.start << ", " << act.finish << ")\n";
    }

    return 0;
}
