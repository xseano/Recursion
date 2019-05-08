#include <iostream>
#include <fstream>
#include <vector>
#define VALUES_LEN 30

using namespace std;

// function declarations
vector<float> values(vector<float> numbers, int position);
float average(vector<float> numbers, float total, int position);

int main()
{
    string fileName;

    float avg;
    vector<float> numbers;

    numbers = values(numbers, 0); // initialize the vector of numbers

    avg = average(numbers, 0.0, 0); // recursively calculate the average of each number in the vector
    cout << avg << endl;
}

/**
 * @brief Obtains values from the file, stores it in a vector
 *
 * @param numbers the empty vector to populate
 * @param position number that represents position of next data in vector
 *
 * @return vector that represents the floats
 */
vector<float> values(vector<float> numbers, int position)
{
    if (position < VALUES_LEN) // check position
    {
        float num;
        cin >> num;

        numbers.push_back(num);
        position++; // increment the position

        return values(numbers, position); // recursive function
    }
    else
    {
        return numbers; // tail recursion
    }
}

/**
 * @brief Calculates the total average of all stored values
 *
 * @param numbers the populated vector
 * @param total the sum of all values in the vector
 * @param position number that represents position of next data in vector
 *
 * @return total that represents the total of floats' average
 */
float average(vector<float> numbers, float total, int position)
{
    if (position < VALUES_LEN) // check position
    {
        total += numbers[position];
        position++; // increment the position

        return average(numbers, total, position); // recursive function
    }
    else
    {
        total /= VALUES_LEN;
        return total; // tail recursion
    }
}