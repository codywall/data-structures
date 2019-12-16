/*
P10: Recursion
Cody Wall
15 December 2019
Merge Sort
Binary Search (Iterative & Recursive)
Factorial (Iterative and Recursive)
Triangle (Iterative and Recursive)
Implement the compound interest iterative method recursively
*/

#include <iostream>
#include <iomanip>
using namespace std;

class Recursion {
public:
    int triangleIterative(int num) {
        int total = 0;
        while (num > 0) {
            total = total + num;
            num--;
        }
        return total;
    }

    int triangleRecursive(int num) {
        if (num == 1)
            return 1;
        else
            return (num + triangleRecursive(num - 1));
    }

    int factorialIterative(int num) {
        int total = 1;
        while (num > 0) {
            total = total * num;
            num--;
        }
        return total;
    }

    int factorialRecursive(int num) {
        if (num == 0)
            return 1;
        else
            return num * factorialRecursive(num - 1);
    }

    void binarySearchIterative(int guess, int numToGuess, int count, int upperLimit, int lowerLimit) {
        //assumes that 1) guess is betwen upper and lower limit
        //assumes that 2) numToGuess is between upper and lower limit
        while (true) {
            if (guess == numToGuess) {
                cout << endl << "You guessed it in " << count << " iterative tries" << endl;
                break;
            } else if (guess > numToGuess) {
                upperLimit = guess;
                guess = (upperLimit + lowerLimit) / 2;
            } else if (guess < numToGuess) {
                lowerLimit = guess;
                guess = (upperLimit + lowerLimit) / 2;
            }
            count++;
        }
    }

    void binarySearchRecursive(int guess, int numToGuess, int count, int upperLimit, int lowerLimit) {
        //assumes that 1) guess is between upper and lower limit
        //assumes that 2) numToGuess is between upper and lower limit
        if (guess == numToGuess)
            cout << endl << "You guessed it in " << count << " recursive tries" << endl;
        else if (guess > numToGuess) {
            upperLimit = guess;
            guess = (upperLimit + lowerLimit) / 2;
            binarySearchRecursive(guess, numToGuess, count, upperLimit, lowerLimit);
        } else if (guess < numToGuess) {
            lowerLimit = guess;
            guess = (upperLimit + lowerLimit) / 2;
            binarySearchRecursive(guess, numToGuess, count, upperLimit, lowerLimit);

        }
    }

    void compoundInterestIterative(double monthlyDeposit, double interest,
                                   int years)
    {
        double total = 0, payments = 0, interestEarned;
        cout << endl;
        for (int year = 1; year <= years; year++)
        {
            total += monthlyDeposit * 12;
            total = total + total * (interest / 100);
            payments += monthlyDeposit * 12;
            interestEarned = total - payments;
            cout << "At end of year " << setw(2) << year;
            cout << " : total savings " << setw(7) << total;
            cout << " : total payments " << setw(5) << payments;
            cout << " : interestEarned " << interestEarned;
            cout << endl;
        }
    }

    void compoundInterestRecursive(double monthlyDeposit, double interest, int years, int year,
                                   double total, double payments, double interestEarned)
    {
        if (year == years + 1)
            return;
        else
        {
            total += monthlyDeposit * 12;
            total = total + total * (interest / 100);
            payments += monthlyDeposit * 12;
            interestEarned = total - payments;
            cout << "At end of year " << setw(2) << year;
            cout << " : total savings " << setw(7) << total;
            cout << " : total payments " << setw(5) << payments;
            cout << " : interestEarned " << interestEarned;
            cout << endl;
            year = year + 1;
            compoundInterestRecursive(monthlyDeposit, interest, years, year, total, payments, interestEarned);
        }
    }
};

class DArray {
private:
    double *array;  //array of doubles
    int nElems;     //number of data items
public:
    DArray(int max)  //constructor
    {
        array = new double[max];
        nElems = 0;
    }
    void insert (double value)
    {
        array[nElems++] = value;
    }
    void display()                              //display array contents
    {
        for (int j = 0; j < nElems; j++)        //for each element
            cout << array[j] << " ";            //display it
            cout << endl;
    }

    void mergeSort()                                //called by main()
    {
        double *workSpace = new double[nElems];     //for each element,
        recMergeSort(workSpace, 0, nElems - 1);
    }

    void recMergeSort(double *workSpace, int lowerBound, int upperBound) {
        if (lowerBound == upperBound)
            return;
        else {
            int mid = (lowerBound + upperBound) / 2;
            recMergeSort(workSpace, lowerBound, mid);   //sort low half
            recMergeSort(workSpace, mid + 1, upperBound); // sort high half
            merge(workSpace, lowerBound, mid + 1, upperBound);
        }
    }

    void merge(double *workSpace, int lowPtr, int highPtr, int upperBound) {
        int j = 0;                  //workspace index
        int lowerBound = lowPtr;
        int mid = highPtr - 1;
        int n = upperBound - lowerBound + 1;    //# of items
        while (lowPtr <= mid && highPtr <= upperBound) {
            if (array[lowPtr] < array[highPtr])
                workSpace[j++] = array[lowPtr++];
            else
                workSpace[j++] = array[highPtr++];
        }
        while (lowPtr <= mid)
            workSpace[j++] = array[lowPtr++];
        while (highPtr <= upperBound)
            workSpace[j++] = array[highPtr++];
        for (j = 0; j < n; j++)
            array[lowerBound + j] = workSpace[j];
    }
};

int main() {
    Recursion *rec = new Recursion;
    cout << "triangleIterative(1): " << rec->triangleIterative(1) << endl;
    cout << "triangleIterative(2): " << rec->triangleIterative(2) << endl;
    cout << "triangleIterative(3): " << rec->triangleIterative(3) << endl;
    cout << "triangleIterative(4): " << rec->triangleIterative(4) << endl << endl;

    cout << "triangleRecursive(1): " << rec->triangleRecursive(1) << endl;
    cout << "triangleRecursive(2): " << rec->triangleRecursive(2) << endl;
    cout << "triangleRecursive(3): " << rec->triangleRecursive(3) << endl;
    cout << "triangleRecursive(4): " << rec->triangleRecursive(4) << endl << endl;

    cout << "factorialIterative(1): " << rec->factorialIterative(1) << endl;
    cout << "factorialIterative(2): " << rec->factorialIterative(2) << endl;
    cout << "factorialIterative(3): " << rec->factorialIterative(3) << endl;
    cout << "factorialIterative(4): " << rec->factorialIterative(4) << endl << endl;

    cout << "factorialRecursive(1): " << rec->factorialRecursive(1) << endl;
    cout << "factorialRecursive(2): " << rec->factorialRecursive(2) << endl;
    cout << "factorialRecursive(3): " << rec->factorialRecursive(3) << endl;
    cout << "factorialRecursive(4): " << rec->factorialRecursive(4) << endl << endl;

    rec->binarySearchIterative(5,2,1,100,1);
    rec->binarySearchIterative(5,2,1,100,1);

    cout << endl << "Recursive merge sort:" << endl;
    DArray *arr = new DArray(100);
    arr->insert(64);
    arr->insert(21);
    arr->insert(33);
    arr->insert(70);
    arr->insert(12);
    arr->insert(85);
    arr->insert(44);
    arr->insert(3);
    arr->insert(99);
    arr->insert(0);
    arr->insert(108);
    arr->insert(36);
    arr->display();
    arr->mergeSort();
    arr->display();

    cout << endl <<  "compoundInterestIterative: ";
    rec->compoundInterestIterative(200.00, 5, 20);
    cout << endl << "compoundInterestRecursive: " << endl;
    rec->compoundInterestRecursive(200.00, 5, 20, 1, 0, 0, 0);

    return 0;
}

/*
/Users/cody/Desktop/fall19/data-structures/p10/cmake-build-debug/p10
triangleIterative(1): 1
triangleIterative(2): 3
triangleIterative(3): 6
triangleIterative(4): 10

triangleRecursive(1): 1
triangleRecursive(2): 3
triangleRecursive(3): 6
triangleRecursive(4): 10

factorialIterative(1): 1
factorialIterative(2): 2
factorialIterative(3): 6
factorialIterative(4): 24

factorialRecursive(1): 1
factorialRecursive(2): 2
factorialRecursive(3): 6
factorialRecursive(4): 24


You guessed it in 3 iterative tries

You guessed it in 3 iterative tries

Recursive merge sort:
64 21 33 70 12 85 44 3 99 0 108 36
0 3 12 21 33 36 44 64 70 85 99 108

compoundInterestIterative:
At end of year  1 : total savings    2520 : total payments  2400 : interestEarned 120
At end of year  2 : total savings    5166 : total payments  4800 : interestEarned 366
At end of year  3 : total savings  7944.3 : total payments  7200 : interestEarned 744.3
At end of year  4 : total savings 10861.5 : total payments  9600 : interestEarned 1261.51
At end of year  5 : total savings 13924.6 : total payments 12000 : interestEarned 1924.59
At end of year  6 : total savings 17140.8 : total payments 14400 : interestEarned 2740.82
At end of year  7 : total savings 20517.9 : total payments 16800 : interestEarned 3717.86
At end of year  8 : total savings 24063.8 : total payments 19200 : interestEarned 4863.75
At end of year  9 : total savings 27786.9 : total payments 21600 : interestEarned 6186.94
At end of year 10 : total savings 31696.3 : total payments 24000 : interestEarned 7696.29
At end of year 11 : total savings 35801.1 : total payments 26400 : interestEarned 9401.1
At end of year 12 : total savings 40111.2 : total payments 28800 : interestEarned 11311.2
At end of year 13 : total savings 44636.7 : total payments 31200 : interestEarned 13436.7
At end of year 14 : total savings 49388.6 : total payments 33600 : interestEarned 15788.6
At end of year 15 : total savings   54378 : total payments 36000 : interestEarned 18378
At end of year 16 : total savings 59616.9 : total payments 38400 : interestEarned 21216.9
At end of year 17 : total savings 65117.7 : total payments 40800 : interestEarned 24317.7
At end of year 18 : total savings 70893.6 : total payments 43200 : interestEarned 27693.6
At end of year 19 : total savings 76958.3 : total payments 45600 : interestEarned 31358.3
At end of year 20 : total savings 83326.2 : total payments 48000 : interestEarned 35326.2

compoundInterestRecursive:
At end of year  1 : total savings    2520 : total payments  2400 : interestEarned 120
At end of year  2 : total savings    5166 : total payments  4800 : interestEarned 366
At end of year  3 : total savings  7944.3 : total payments  7200 : interestEarned 744.3
At end of year  4 : total savings 10861.5 : total payments  9600 : interestEarned 1261.51
At end of year  5 : total savings 13924.6 : total payments 12000 : interestEarned 1924.59
At end of year  6 : total savings 17140.8 : total payments 14400 : interestEarned 2740.82
At end of year  7 : total savings 20517.9 : total payments 16800 : interestEarned 3717.86
At end of year  8 : total savings 24063.8 : total payments 19200 : interestEarned 4863.75
At end of year  9 : total savings 27786.9 : total payments 21600 : interestEarned 6186.94
At end of year 10 : total savings 31696.3 : total payments 24000 : interestEarned 7696.29
At end of year 11 : total savings 35801.1 : total payments 26400 : interestEarned 9401.1
At end of year 12 : total savings 40111.2 : total payments 28800 : interestEarned 11311.2
At end of year 13 : total savings 44636.7 : total payments 31200 : interestEarned 13436.7
At end of year 14 : total savings 49388.6 : total payments 33600 : interestEarned 15788.6
At end of year 15 : total savings   54378 : total payments 36000 : interestEarned 18378
At end of year 16 : total savings 59616.9 : total payments 38400 : interestEarned 21216.9
At end of year 17 : total savings 65117.7 : total payments 40800 : interestEarned 24317.7
At end of year 18 : total savings 70893.6 : total payments 43200 : interestEarned 27693.6
At end of year 19 : total savings 76958.3 : total payments 45600 : interestEarned 31358.3
At end of year 20 : total savings 83326.2 : total payments 48000 : interestEarned 35326.2

Process finished with exit code 0
*/