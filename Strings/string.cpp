#include <iostream>
using namespace std;

int main()
{

    // char temp = 'C';

    // cout << "Character Value: " << temp << endl;
    // cout << "ASCII Value: " << static_cast<int>(temp) <<endl;

    // changing the case of the character
    string name = "abdul";

    // for (char ch : name)
    // {
    //     cout << char(ch -32);
    // }

    // Lower case -> Upper Case
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = name[i] - 32;
    }

    cout << "Upper Case: " << name << endl;

    // Upper case -> Lower case
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = name[i] + 32;
    }
    cout << "Lower Case: " << name << endl;

    // toggle the case of the character in a string
    string message = "HelLo dEar";
    cout << "Original Message: " << message << endl;

    for (int i = 0; message[i] != '\0'; i++)
    {
        // check if upper case
        if (static_cast<int>(message[i]) >= 65 && static_cast<int>(message[i]) <= 90)
        {
            message[i] = message[i] + 32;
        }

        // check if lower case alphabet
        else if (static_cast<int>(message[i]) >= 97 && static_cast<int>(message[i] <= 122))
        {
            message[i] = message[i] - 32;
        }
    }

    cout << "Toggled Alphabets Message: " << message << endl;

    return 0;
}