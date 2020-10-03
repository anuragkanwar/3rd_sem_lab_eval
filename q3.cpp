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

map<int, int> ans;
struct Node
{
    int data;
    Node *next;
    Node *prv;
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = nullptr;
        tail = nullptr;
    }

    void ins(list<int> &obj)
    {
        int ekbar = 0;
        for (auto x : obj)
        {
            if (ekbar == 0)
            {
                ekbar++;
                ans[x] = 0;
            }
            else
            {
                ans[x] = 1;
            }
            Node *temp = new Node;
            temp->data = x;
            temp->next = nullptr;

            if (head == nullptr)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = temp;
            }
        }
    }

    Node *search(int tar)
    {

        Node *move = head;
        while (move != nullptr)
        {

            if (tar == move->data)
            {
                return move;
            }
            else
            {
                move = move->next;
            }
        }
        return nullptr;
    }

    void disp()
    {
        Node *move = head;
        while (move != nullptr)
        {
            cout << move->data << " ";
            move = move->next;
            if (move == head)
            {
                break;
            }
        }
        cout << endl;
    }

    void change(int data, int frw, int &ans1)
    {
        Node *move = head;
        Node *move1 = head;
        move1 = search(data);
        if (move1 == nullptr)
        {
            return;
        }
        move = move1;

        while (frw--)
        {

            if (move->next == nullptr)
            {
                ans1 = 1;
                move->next = head;
                move = head;
                ans[head->data] = 1;
            }
            else
            {
                move = move->next;
            }
        }

        ans[move1->next->data]--;
        move1->next = move;
        ans[move->data]++;
    }
};

int main()
{
    List obj2;
    list<int> obj;
    auto it = obj.begin();
    auto it1 = obj.begin();
    auto it2 = obj.begin();
    int n;
    cin >> n;
    int a3 = -1, a4 = -1;
    vector<pair<pair<char, int>, pair<pair<int, int>, int>>> data;
    fo(i, n)
    {
        a3 = -1;
        a4 = -1;
        char ch;
        int a1, a2;

        cin >> ch;
        if (ch == 'I')
        {
            cin >> a1;
            if (a1 == 0)
            {
                cin >> a2;
            }
            else if (a1 == 1)
            {
                cin >> a2 >> a3;
            }
            else
            {
                cin >> a2 >> a3 >> a4;
            }
        }
        else
        {
            cin >> a1 >> a2;
        }

        data.pb(mp(mp(ch, a1), mp(mp(a2, a3), a4)));
    }
    int ek_bar = 0;
    int ans1 = 0;
    int a, b, c;
    char lol;
    for (auto y : data)
    {
        string x;
        char ch = y.first.first;
        switch (ch)
        {
        case 'I':
        {

            switch (y.first.second)
            {
            case 0:

                obj.push_back(y.second.first.first);
                break;
            case 1:

                it = find(obj.begin(), obj.end(), y.second.first.first);
                if (it == obj.end())
                {
                    it2 = find(obj.begin(), obj.end(), y.second.first.second);
                    it2;
                    obj.insert(it2, y.second.first.first);
                }
                else
                {
                    it++;
                    obj.insert(it, y.second.first.second);
                }
                break;
            case 2:

                it1 = find(obj.begin(), obj.end(), y.second.first.first);
                it2 = find(obj.begin(), obj.end(), y.second.first.second);
                int half = 0;
                for (auto it = it1; it != it2; it++)
                {
                    half++;
                }
                half /= 2;
                half++;
                it1 = find(obj.begin(), obj.end(), y.second.first.first);
                while (half--)
                {
                    it1++;
                }
                obj.insert(it1, y.second.second);
            }
            break;
        }
        break;
        case 'U':
            if (ek_bar == 0)
            {
                obj2.ins(obj);
                ek_bar++;
            }
            obj2.change(y.first.second, y.second.first.first, ans1);

            // for (auto x : ans)
            // {
            //     cout << x.first << " " << x.second << endl;
            // }
            // cout << endl;
            break;
        }
    }
    if (ek_bar == 0)
    {
        obj2.ins(obj);
        ek_bar++;
    }
    cout << ans1 << endl;
    map<int, int> m;
    m = ans;
    ans.clear();
    for (auto x : m)
    {
        if (x.second > 1)
        {
            ans.insert(x);
        }
    }

    if (ans.size() == 0)
    {
        cout << ans.size() << endl;
        obj2.disp();
    }
    else
    {
        cout << ans.size() << endl;
        for (auto x : ans)
        {
            cout << x.first << " ";
        }
        cout << endl;
        for (auto x : ans)
        {
            cout << x.second << " ";
        }
        cout << endl;
    }
}

/*

10
I 0 1
I 0 7 
I 1 6 7
I 1 1 2
I 2 1 7 3
I 2 3 6 5
I 2 1 7 4
U 2 3
U 2 2
U 1 6

3
I 0 1
I 1 1 7
I 2 1 7 3


8
I 0 1
I 0 7 
I 1 6 7
I 1 1 2
I 2 1 7 3
I 2 3 6 5
I 2 1 7 4
U 7 1

7
I 0 1
I 0 2
I 0 3
I 0 4
U 4 1
U 3 2
U 2 2



20
I 0 1 
I 0 2
I 0 60
I 0 61
I 0 50
I 0 49
I 0 48
I 0 6
I 0 17
I 0 98
I 0 99
I 0 9
I 1 99 19
I 1 15 98 
I 0 10
I 0 14
U 61 4
U 2 3
U 99 2
U 15 3

4
I 0 1
I 0 2
I 0 3
U 3 1

*/