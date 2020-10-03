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

void disp(vector<pair<char, int>> &freq)
{
    for (auto x : freq)
    {
        cout << x.first << " " << x.second << " ";
    }
    cout << endl;
}

void change(vector<pair<char, int>> &freq, int tar)
{
    auto ind1 = freq.end();
    auto ind2 = freq.end();

    for (auto it = freq.begin(); it != freq.end(); it++)
    {
        if (tar == it->second)
        {
            if (ind1 == freq.end())
            {
                ind1 = it;
                ind2 = it;
            }
            else
            {
                ind2 = it;
            }
        }
    }

    if (ind2 != freq.end() && ind1 != freq.end())
    {

        vector<pair<char, int>> replace;
        for (auto it = ind1; it != ind2; it++)
        {
            replace.pb(*it);
        }

        for (auto x : replace)
        {
            auto it = find(freq.begin(), freq.end(), x);
            if (it != freq.end() && it->second != tar)
            {
                freq.erase(it);
            }
        }

        for (auto x : replace)
        {
            if (x.second > tar)
            {
                freq.push_back(x);
            }
            if (x.second < tar)
            {
                freq.insert(freq.begin(), x);
            }
        }
    }
    disp(freq);
}

int main()
{
    string str;
    int n;
    getline(cin, str);
    cin >> n;
    vi arr(n);
    fo(i, n)
    {
        cin >> arr[i];
    }

    vector<pair<char, int>> freq;

    for (auto x : str)
    {
        int flag = 0;
        for (auto it = freq.begin(); it != freq.end(); it++)
        {
            if (x == it->first)
            {
                flag = 1;
                it->second++;
                break;
            }
        }
        if (!flag)
        {
            freq.pb(mp(x, 1));
        }
    }

    disp(freq);

    for (auto x : arr)
    {
        change(freq, x);
    }
}

/*

nomatterhowbusyyoumaythinkyouareyoumustfindtimeforreadingorsurrenderyourselftoselfchosenignorance
3
3 1 6

*/