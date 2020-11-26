#include <iostream>
#include <list>
#include <math.h>
using namespace std;

// Returns true if n is prime, false otherwise
// First call should have i=2
bool isPrime(const int n, int i)
{
    bool isPrimeNum;
    if(n <= 1)
    {
        return false;
    }
    if(i > sqrt(n))
    {
        isPrimeNum = true;
        return isPrimeNum;
    }
    else
    {
        if(n % i == 0)
        {
            isPrimeNum == false;
            return isPrimeNum;
        }
        else
        {
            i++;
            isPrimeNum = isPrime(n, i);
            return isPrimeNum;
        }
    }
}

// Returns the list version of an integer n
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

// Returns the integer version of a list of integers
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

// Returns a list of lists of integers that contains all rotations of the initial list
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

// Prints a list of integers
void printList(list<int> l)
{
    for(int n : l)
    {
        cout << n << ", ";
    }
    return;
}

// Returns true if every integer in list l is considered special
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

// Returns the number of special numbers in the range 2 to n
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
        }
    }
    return (count + countSpecialPrimes(n-1));
}

int main(int argc, char* argv[])
{
    /*
    int l[6] = {10, 100, 257, 545, 814, 999};

    for(int i=0; i < 6; i++)
    {
        cout << countSpecialPrimes(l[i]) << endl;
    }
    */

    int test = 100; // Default value if no argument is provided

    if(argc > 1)
    {
        test = atoi(argv[1]);
    }

    cout << countSpecialPrimes(test) << endl;

    return 0;
}
