#include <bits/stdc++.h>
using namespace std;


// GEO TEMPLATE ////////////////////////////////////////////////////////////////

typedef long long LL;

struct pt {
	LL x, y;
	pt(LL x = 0, LL y = 0) :
		x(x), y(y) {}
};
istream& operator >>(istream& in, pt &A) { return in >> A.x >> A.y; }
ostream& operator <<(ostream& out, pt A) { return out << '(' << A.x << ',' << A.y << ')'; }

pt operator +(pt A, pt B) { return pt(A.x + B.x, A.y + B.y); }
pt operator -(pt A, pt B) { return pt(A.x - B.x, A.y - B.y); }
LL operator ^(pt A, pt B) { return A.x*B.y - A.y*B.x; }

////////////////////////////////////////////////////////////////////////////////

#define SQ(a) (a)*(a)

struct fr {
    LL n, d = 1;
    fr(LL x) : n(x) {}
    fr(LL x, LL y) {
        LL g = y ? __gcd(abs(x), abs(y)) : 1;
        n = x / g;
        d = y / g;
        if (n < 0 && d < 0) n = -n, d = -d;
        if (n < 0 || d < 0) n = -abs(n), d = abs(d);
    }
};

bool operator ==(fr a, fr b) { return a.n * b.d == b.n * a.d; }
bool operator !=(fr a, fr b) { return !(a == b); }
LL d(pt a, pt b) { return SQ(a.x - b.x) + SQ(a.y - b.y); }

int sgn(LL x) { return (x > 0) - (x < 0); }

string solve(int n) {
    vector<pt> a(n);
    vector<pt> b(n);
    for (pt& i : a) cin >> i;
    for (pt& i : b) cin >> i;

    fr scaling2(d(a[0], a[1]), d(b[0], b[1]));

    LL Areaa = 0, Areab = 0;
    for (int i = 0; i < n; ++i) {
        if (fr(d(a[0], a[i]), d(b[0], b[i])) != scaling2) return "dissimilar";
        if (fr(d(a[1], a[i]), d(b[1], b[i])) != scaling2) return "dissimilar";

        LL p = (a[i] - a[(i + 2) % n]) ^ (a[(i + 1) % n] - a[(i + 2) % n]);
        LL q = (b[i] - b[(i + 2) % n]) ^ (b[(i + 1) % n] - b[(i + 2) % n]);
        Areaa += p;
        Areab += q;
    }

    if (sgn(Areaa) != sgn(Areab)) return "dissimilar";

    return "similar";
}

int main() {
    for (int n; cin >> n && n;)
        cout << solve(n) << "\n";
}
