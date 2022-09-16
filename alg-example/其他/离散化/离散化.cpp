//
// Created by 走线大师 on 2022/9/15.
//

class Discretization {
private:
    vector<int> IDX;
public:
    Discretization() {
        IDX.clear();
    }
    void clear() {
        IDX.clear();
    }
    void add_num(int x) {
        IDX.push_back(x);
    }
    void run() {
        sort(IDX.begin(), IDX.end());
        IDX.erase(unique(IDX.begin(), IDX.end()), IDX.end());
    }
    int get_trans(int x) {
        return lower_bound(IDX.begin(), IDX.end(), x) - IDX.begin();
    }
    int get_orig(int id) {
        return IDX[id];
    }
    int size() {
        return IDX.size();
    }
};