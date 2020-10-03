#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " = " << x << endl

#define deb2(x, y) cout << #x << " = " << x << "\n" \
                        << #y << "=" << y << endl

#define debwe(x) cout << #x << " = " << x
#define check(x) cout << "--------" << x << endl

#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define printvec(v)       \
    for (auto x : v)      \
        cout << x << " "; \
    cout << endl

pair<int, int> give_pair(int n, int m, int d)
{
    pair<int, int> res;
    int c = 0;
    int i = 0;
    int top = 0, down = n - 1, left = 0, right = m - 1;
    while (top <= down && left <= right)
    {
        if (d == 0)
        {
            if (c == 0)
            {
                c++;
                for (i = left; i <= right - 1; i++)
                {
                    res = mp(top, i);
                }
            }
            else
            {
                for (i = left - 1; i <= right - 1; i++)
                {
                    res = mp(top, i);
                }
            }
            top++;
        }
        else if (d == 1)
        {
            if (c == 0)
            {
                c++;
                for (i = top; i <= down - 1; i++)
                {
                    res = mp(i, right);
                }
            }
            else
            {
                for (i = top - 1; i <= down - 1; i++)
                {
                    res = mp(i, right);
                }
            }
            right--;
        }
        else if (d == 2)
        {
            if (c == 0)
            {
                c++;
                for (i = right; i >= left + 1; i--)
                {
                    res = mp(down, i);
                }
            }
            else
            {
                for (i = right + 1; i >= left + 1; i--)
                {
                    res = mp(down, i);
                }
            }
            down--;
        }
        else
        {
            if (c == 0)
            {
                c++;
                for (i = down; i >= top + 1; i--)
                {
                    res = mp(i, left);
                }
            }
            else
            {
                for (i = down + 1; i >= top + 1; i--)
                {
                    res = mp(i, left);
                }
            }
            left++;
        }
        d++;
        d = d % 4;
    }
    return res;
}

vvi subroutine(vector<pair<pair<int, int>, int>> &v, int &n, int &m)
{

    vvi temp(n, vi(m));
    for (auto x : v)
    {
        temp[x.first.first][x.first.second] = x.second;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << temp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return temp;
}

void output(vector<pair<pair<int, int>, int>> &v, int &n, int &m, int &d, pii &ini)
{
    vector<pair<pair<int, int>, pair<int, int>>> final;
    pair<int, int> res;
    pair<int, int> res2;
    int top = 0, down = n - 1, left = 0, right = m - 1;
    int c = 0;
    int i = 0;
    while (top <= down && left <= right)
    {
        if (d == 0)
        {
            if (c == 0)
            {
                c++;
                for (i = left; i <= right - 1; i++)
                {
                    // cout << "(" << top << "," << i << ") ";
                    res = mp(top, i);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            else
            {
                for (i = left - 1; i <= right - 1; i++)
                {
                    // cout << "(" << top << "," << i << ") ";
                    res = mp(top, i);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            top++;
        }
        else if (d == 1)
        {
            if (c == 0)
            {
                c++;
                for (i = top; i <= down - 1; i++)
                {
                    // cout << "(" << i << "," << right << ") ";
                    res = mp(i, right);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            else
            {
                for (i = top - 1; i <= down - 1; i++)
                {
                    // cout << "(" << i << "," << right << ") ";
                    res = mp(i, right);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            right--;
        }
        else if (d == 2)
        {
            if (c == 0)
            {
                c++;
                for (i = right; i >= left + 1; i--)
                {
                    // cout << "(" << down << "," << i << ") ";
                    res = mp(down, i);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            else
            {
                for (i = right + 1; i >= left + 1; i--)
                {
                    // cout << "(" << down << "," << i << ") ";
                    res = mp(down, i);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            down--;
        }
        else
        {
            if (c == 0)
            {
                c++;
                for (i = down; i >= top + 1; i--)
                {
                    // cout << "(" << i << "," << left << ") ";
                    res = mp(i, left);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            else
            {
                for (i = down + 1; i >= top + 1; i--)
                {
                    // cout << "(" << i << "," << left << ") ";
                    res = mp(i, left);
                    for (auto x : v)
                    {
                        if (x.first.first == res.first && x.first.second == res.second)
                        {
                            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
                            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
                            break;
                        }
                    }
                }
            }
            left++;
        }
        d++;
        d = d % 4;
    }
    d--;
    if (d == -1)
    {
        d = 3;
    }
    for (auto x : v)
    {
        if (x.first.first == ini.first && x.first.second == ini.second)
        {
            // cout << x.first.first << " " << x.first.second << " " << x.second << " " << 4 - d;
            final.pb(mp(mp(x.first.first, x.first.second), mp(x.second, 4 - d)));
            break;
        }
    }

    reverse(final.begin(), final.end());
    for (auto it : final)
    {
        cout << it.first.first << " " << it.first.second << " " << it.second.first << " " << it.second.second << endl;
    }
}

int main()
{
    int dir[] = {0, 1, 2, 3};
    int n, m, size;
    cin >> n >> m >> size;
    vector<pair<pair<int, int>, int>> v;

    for (int i = 0; i < size; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.pb(mp(mp(a, b), c));
    }

    int ind1, ind2;
    cin >> ind1 >> ind2;
    pii ini = mp(ind1, ind2);

    vvi arr = subroutine(v, n, m);
    int match;
    for (auto x : dir)
    {
        pii ans = give_pair(n, m, x);
        match = x;
        if (ans.first == ini.first + 1 && ans.second == ini.second)
        {
            match = x;
            break;
        }
    }
    output(v, n, m, match, ini);
}

/*

4 4 5
0 0 8
1 1 6
1 2 5
2 3 9
3 2 7
1 1

4 4 5
0 0 8
1 1 6
1 2 5
2 3 9
3 2 7
2 2

5 5 5
0 0 8
1 1 6
1 2 5
2 3 9
3 2 7
2 2

5 4 5
0 0 8
1 1 6
1 2 5
2 3 9
3 2 7
1 1


3 3 1
2 1 1
1 1
*/