// https://icpc.kattis.com/problems/rangers

#include <bits/stdc++.h>
using namespace std;

#define SQ(a) (a)*(a)

struct pt {
    int x;
    int y;
    int z;
    pt() {}
    pt(int x, int y, int z) : x(x), y(y), z(z) {} 
    int sq() { return x*x + y*y + z*z; }
    int sum() { return x + y + z; }
};

pt operator +(pt A, pt B) { return pt(A.x + B.x, A.y + B.y, A.z + B.z); }
pt operator -(pt A, pt B) { return pt(A.x - B.x, A.y - B.y, A.z - B.z); }
pt operator *(pt A, pt B) { return pt(A.x * B.x, A.y * B.y, A.z * B.z); }
pt operator *(int K, pt A) { return pt(A.x * K  , A.y * K  , A.z * K  ); }
istream& operator>>(istream& in, pt& P) { return in >> P.x >> P.y >> P.z; }

pair<double, double> sols(pt Pa, pt Va, pt Pb, pt Vb) {
    int A = Va.sq() - Vb.sq();
    int B = 2 * ((Pa * Va) - (Pb * Vb)).sum();
    int C = Pa.sq() - Pb.sq();
    int D = B * B - 4 * A * C;

    if (A == 0 || D < 0)
        return {-1, -1};

    double s1 = (1.0 * (-B + sqrt(D)) / (2 * A));
    double s2 = (1.0 * (-B - sqrt(D)) / (2 * A));
    if (s1 <= 0) s1 = -1;
    if (s2 <= 0) s2 = -1;

    return {s1, s2};
}

double dist(pt P, pt V, double t) {
    return  SQ(V.x * t + P.x) +
            SQ(V.y * t + P.y) +
            SQ(V.z * t + P.z);
}

vector<int> mst(int n, vector<pt>& P, vector<pt>& V, double t) {
    vector<int> p(n);
    vector<bool> vis(n);
    vector<double> d(n, 1e15);
    d[0] = 0, p[0] = -1, vis[0] = true;
    int prv = 0;
    for (int cnt = 0; cnt < n - 1; ++cnt) {
        int id = -1;
        double mn = 1e15;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            double tmp = dist(P[i] - P[prv], V[i] - V[prv], t);
            if (tmp < d[i])
                d[i] = tmp, p[i] = prv;
            if (d[i] < mn)
                mn = d[i], id = i;
        }
        vis[id] = true;
        prv = id;
    }
    return p;
}

int solve(int n) {
    vector<pt> P(n);
    vector<pt> V(n);
    for (int i = 0; i < n; ++i)
        cin >> P[i] >> V[i];

    vector<double> times;
    times.push_back(0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                auto [s1, s2] = sols(P[j]-P[i], V[j]-V[i], P[k]-P[i], V[k]-V[i]);
                if (s1 != -1) {
                    times.push_back(s1);
                    times.push_back(s1 + 1e-6);
                    times.push_back(s1 - 1e-6);
                }
                if (s2 != -1) {
                    times.push_back(s2);
                    times.push_back(s2 + 1e-6);
                    times.push_back(s2 - 1e-6);
                }
            }
        }
    }

    sort(times.begin(), times.end());
    times.resize(unique(times.begin(), times.end()) - times.begin());

    vector<int> prv = mst(n, P, V, times[0]);
    int ans = 1;
    for (int i = 1; i < times.size(); ++i) {
        vector<int> cur = mst(n, P, V, times[i]);
        ans += (cur != prv);
        prv = cur;
    }

    return ans;
}

int main() {
    for (int i = 1, n; cin >> n && n != -1; ++i)
        cout << "Case " << i << ": " << solve(n) << "\n";
}
