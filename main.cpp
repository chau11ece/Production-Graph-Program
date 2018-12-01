/// Reads data and displays a bar graph showing productivity for each plant.

#include <iostream>
#include <cmath>

const int NUMBER_OF_PLANTS = 4;

using namespace std;

void input_data(int *array, int last_plant_number);
/// Precondt: last_plant_number is the declared size of the array.
/// Postcondt: for plant_number = 1 through last_plant_number:
/// array[plant_number -1] equals the total production for plant number plant_number.

void scale(int *array, int size);
/// Precondt: a[0] through a[size-1] each has a non-negative value.
/// Postcondt: a[i] has been changed to the number of 1000s (rounded to
/// an integer) that were originally in a[i], for all i such that 0 <= i <= size - 1.

void graph(const int *asterisk_count, int last_plant_number);
/// Precondt: asterisk_count[0] through asterisk_count[last_plant_number -1]
/// have nonegative values.
/// Postcondt: A bar graph has been displayed saying that plant numer N
/// has produced asterisk_count[N-1] 1000s of units, for each N such that
/// 1<= N << last_plant_number

void get_total(int &number);
/// Read nonnegative integers from the keyboard and places their total in sum.

int round_fnc(double number);
/// number >= 0;
/// Return number rounded to the nearest integer.

void print_asterisks(int numAst);

int main()
{
        int production[NUMBER_OF_PLANTS];
        cout << "This program displays a graph showing\n"
                << "production for each plant in the company.\n";

        /// 3 subtasks
        input_data(production, NUMBER_OF_PLANTS);
        scale(production, NUMBER_OF_PLANTS);
        graph(production, NUMBER_OF_PLANTS);

        return 0;
}

void input_data(int *array, int last_plant_number)
{
    for (int plant_number = 0; plant_number < last_plant_number; ++plant_number)
    {
        cout << endl
                << "Enter production data for plant number "
                << plant_number + 1 << endl;

        get_total(array[plant_number]);

    }
}

void get_total(int &sum)
{
        cout << "Enter number of units produced by each department.\n"
                << "Append a negative number to the end of the list.\n";

        sum = 0;
        int next;
        cin >> next;
        while (next >= 0)
        {
            sum += next;
            cin >> next;
        }

        cout << "Total = " << sum << endl;
}

void scale(int *array, int size)
{
    for (int index = 0; index < size; ++index)
        array[index] = round_fnc(array[index]/1000.0);
}

int round_fnc(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

void graph(const int *asterisk_count, int last_plant_number)
{
    cout << "\nUnits produced in thousands of units:\n";

    for (int index = 0; index < last_plant_number; ++index)
    {
        cout << "Plant #" << index +1 << " ";
        print_asterisks(asterisk_count[index]);
        cout << endl;
    }

}

void print_asterisks(int numAst)
{
    for (int i = 0; i < numAst; ++i)
        cout << " * ";
}
