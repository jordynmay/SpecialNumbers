#include <iostream>
#include <list>
using namespace std;

bool isPrime(const int n, int i) // First call should have i=2
{
    bool isPrimeNum;
    if(n <= 1)
    {
        return false;
    }
    //cout << "is i>n/2? " << (i>(n/2)) << endl;
    if(i > n/2)
    {
        //cout << "\treturning prime" << endl;
        isPrimeNum = true;
        return isPrimeNum;
    }
    else
    {
        if(n % i == 0)
        {
            //cout << "\treturning not prime" << endl;
            isPrimeNum == false;
            return isPrimeNum;
        }
        else
        {
            i++;
            //cout << "n, i is: " << n << ", " << i << endl;
            isPrimeNum = isPrime(n, i);
            return isPrimeNum;
        }
    }
}

list<int> intToList(int n, list<int> nList)
{
    if(n <= 0)
    {
        return nList;
    }
    else
    {
        int digit = n % 10;
        int nextN = static_cast<int>(n/10);
        nList.push_front(digit);
        return intToList(nextN, nList);
    }
}

// First call should have n=0
int listToInt(int n, list<int> nList)
{
    if(nList.size() == 0)
    {
        return n;
    }
    else
    {
        int digit = nList.front();
        nList.pop_front();
        n = (n*10) + digit;
        return listToInt(n, nList);
    }   
}

// First call should have i=1
list<list<int>> rotateList(list<int> nList, list<list<int>> listList, int i)
{
    if(i > nList.size())
    {
        return listList;
    }
    else
    {
        listList.push_back(nList);
        int firstElem = nList.front();
        nList.pop_front();
        nList.push_back(firstElem);
        i++;
        return rotateList(nList, listList, i);
    }
}

void printList(list<int> l)
{
    for(int n : l)
    {
        cout << n << ", ";
    }
    return;
}

// First call should have i = 1
bool isSpecial(list<list<int>> l)
{
    bool retVal = false;
    if(l.size() <= 0)
    {
        return true;
    }
    else
    {
        int check = listToInt(0,l.front());
        l.pop_front();
        retVal = isPrime(check, 2);
        return (retVal && isSpecial(l));
    }
}

int countSpecialPrimes(int n)
{
    int count = 0;
    if(n <= 0)
    {
        return 0;
    }
    else
    {
        bool isSpec = false;
        list<int> l = intToList(n, {});
        list<list<int>> l2 = rotateList(l, {}, 1);
        isSpec = isSpecial(l2);
        if(isSpec)
        {
            count++;
            cout << n << ", ";
        }
    }
    return (count + countSpecialPrimes(n-1));
}

int main()
{
    int num1 = 1;
    int num2 = 197;

    //cout << num1 << " is prime? ";
    //printf(isPrime(num1, 2) ? "YES\n" : "NO\n");
    //cout << num2 << " is prime? ";
    //printf(isPrime(num2, 2) ? "YES\n" : "NO\n");

    list<int> nList = intToList(num2, {});
    //printList(nList);
    //cout << endl;

    int backToInt = listToInt(0, nList);
    //cout << "List back to int is: " << backToInt << endl;


    list<list<int>> allRots = rotateList(nList, {}, 1);
    /*for(list<int> n : allRots)
    {
        cout << "(";
        printList(n);
        cout << ")";
    }
    cout << endl;*/


    int numPrimes = countSpecialPrimes(100);
    cout << endl << "COUNT OF SPECIAL PRIMES: " << numPrimes << endl;

    return 0;
}