/* BIG INTEGER HEADER FILE FOR CPP */
/*
    Must Include Header Files
    #include <vector>
    #include <string>
    #include <algorithm>
*/


#ifndef BIGINTEGER_H
#define BIGINTEGER_H


std::vector<int> create_vector(std::string x)
{
    std::vector<int> first;

    for (int i = 0; i < x.length(); i++)
    {
        first.emplace_back(x[i] - '0');
    }

    return first;
}


void print_v(std::vector<int> x)
{
    for (std::vector<int>:: iterator it = x.begin(); it != x.end(); it++) {
        std::cout << *it;
    }
    return;
}


std::vector<int> big_add(std::vector<int> a, std::vector<int> b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    std::vector<int> Ans;
    long int carry = 0;

    // long int n = min(a.size(), b.size());
    long int n;
    a.size() > b.size() ? n = b.size() : n = a.size();

    for (int i = 0; i < n; i++)
    {
        long int val = a[i] + b[i] + carry;
        carry = val / 10;
        Ans.emplace_back(val % 10);
    }

    if (a.size() > n)
    {
        for (int i = n; i < a.size(); i++)
        {
            long int val = a[i] + carry;
            carry = val / 10;
            Ans.emplace_back(val % 10);
        }
    }
    if (b.size() > n)
    {
        for (int i = 0; i < b.size(); i++)
        {
            long int val = b[i] + carry;
            carry = val / 10;
            Ans.emplace_back(val % 10);
        }
    }

    while (carry)
    {
        Ans.emplace_back(carry % 10);
        carry = carry / 10;
    }

    reverse(Ans.begin(), Ans.end());
    return Ans;
}

std::vector<int> big_Sub(std::vector<int> a, std::vector<int> b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    std::vector<int> Ans;
    long int len = b.size();

    for (int i = 0; i < len; i++)
    {
        if (a[i] < b[i])
        {
            a[i + 1]--;
            Ans.emplace_back(10 + a[i] - b[i]);
        }

        else
        {
            Ans.emplace_back(a[i] = b[i]);
        }
    }
    if (a.size() > len)
    {

        for (int i = len; i < a.size(); i++)
        {
            if (a[i] < 0)
            {
                a[i + 1]--;
                Ans.emplace_back(10 + a[i]);
            }

            else
            {
                Ans.emplace_back(a[i]);
            }
        }
    }
    reverse(Ans.begin(), Ans.end());
    std::vector<int> result;
    int i = 0;
    while (Ans[i] == 0)
    {
        i++;
    }

    for (; i < Ans.size(); i++)
    {
        result.emplace_back(Ans[i]);
    }

    return result;
}

std::vector<int> big_division(std::vector<int> a)
{
    std::vector<int> Ans;
    long int rem = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (rem)
        {
            rem = rem * 10 + a[i];
            Ans.emplace_back(rem / 2);
            rem = rem % 2;
        }

        else
        {
            if (a[i] < 2)
            {
                rem = rem + a[i];
                Ans.emplace_back(0);
            }

            else
            {
                rem = a[i] % 2;
                Ans.emplace_back(a[i] / 2);
            }
        }
    }

    std::vector<int> result;
    int i = 0;
    while (Ans[i] == 0)
    {
        i++;
    }

    for (; i < Ans.size(); i++)
    {
        result.emplace_back(Ans[i]);
    }
    return result;
}

std::vector<int> big_multiply(std::vector<int> a, std::vector<int> b)
{
    int carry = 0;
    int len1 = a.size();
    int len2 = b.size();

    for (int i = 0; i < len1; i++)
    {
        long int prod = a[i] * b[i] + carry;
        carry = prod / 10;
        a[i] = prod % 10;
    }

    while (carry)
    {
        a.emplace_back(carry % 10);
        carry = carry / 10;
    }

    return a;
}

bool big_greater(std::vector<int> a, std::vector<int> b) {
    if (a.size() > b.size())
    {
        return true;
    }
    else if (b.size() > a.size()) {
        return false;
    }
    else if (a.size() == b.size()) {
        long int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                return true;
            }
            if (a[i] < b[i]) {
                return false;
            }
        }
    }

    return false;
}



bool big_less(std::vector<int> a, std::vector<int> b) {
    if (a.size() > b.size())
    {
        return false;
    }
    else if (b.size() > a.size()) {
        return true;
    }
    else if (a.size() == b.size()) {
        long int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                return false;
            }
            if (a[i] < b[i]) {
                return true;
            }
        }
    }

    return false;
}

bool big_equal(std::vector<int> a, std::vector<int> b) {
    if (a.size() > b.size())
    {
        return false;
    }
    else if (b.size() > a.size()) {
        return false;
    }
    else if (a.size() == b.size()) {
        long int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                return false;
            }
            if (a[i] < b[i]) {
                return false;
            }
        }
    }

    return true;
}

bool big_notEqual(std::vector<int> a, std::vector<int> b) {
    if (!big_equal(a, b)) {
        return true;
    }
    else {
        return false;
    }
}

bool big_greaterEqual(std::vector<int> a, std::vector<int> b) {
    if (big_equal(a, b)) {
        return true;
    }
    else if (big_greater(a, b)) {
        return true;
    }
    return false;
}

bool big_lessEqual(std::vector<int> a, std::vector<int> b) {
    if (big_equal(a, b)) {
        return true;
    }
    else if (big_less(a, b)) {
        return true;
    }
    return false;
}

void multiply(std::vector<int> &ans, int num)
{
    int carry = 0;
    long int prod;


    for (int i = 0; i < ans.size(); i++)
    {
        prod = ans[i] * num + carry;
        carry = prod / 10;
        ans[i] = prod % 10;
    }

    while (carry)
    {
        ans.emplace_back(carry % 10);
        carry = carry / 10;
    }
}


std::vector<int> big_factorial (int k)
{
    std::vector<int> ans;

    ans.emplace_back(1);

    for (int i = 2; i <= k; i++)
    {
        multiply(ans, i);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

std::vector<int> big_increment(std::vector<int> h)
{
    int n = h.size();
    std::vector<int> an;
    int carry = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int sum = h[i] + carry;
        an.emplace_back(sum % 10);
        carry = sum / 10;
    }

    if (carry)
        an.emplace_back(carry);

    reverse(an.begin(), an.end());
    return an;
}

std::vector<int> big_decrement(std::vector<int> h)
{
    int n = h.size();
    std::vector<int> an;
    int carry = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        int sub = h[i] - carry;
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else carry = 0;
        an.emplace_back(sub);

    }

    reverse(an.begin(), an.end());
    return an;
}


#endif