#include <bits/stdc++.h>
#include <map>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    map<long, long long> factory_boxes;
    long long factories, boxes_goal;

    cin>>factories>>boxes_goal;

    for(long long i = 0; i < factories; i++) {
        long price;
        long long boxes;
        cin>>price>>boxes;
        if (factory_boxes.find(price) == factory_boxes.end()) {
            factory_boxes.insert({price, boxes});
        } else {
            factory_boxes.at(price) += boxes;
        }
    }

    long long price_sum = 0, box_sum = 0;

    for (auto box : factory_boxes) {
        if (box_sum + box.second < boxes_goal) {
            price_sum += box.first * box.second;
        } else {
            price_sum += box.first * (boxes_goal - box_sum);
            break;
        }
        box_sum += box.second;
    }

    cout<<price_sum<<endl;

    return 0;
}
