#include <iostream>
using namespace std;

int main()
{

    // char temp = 'C';

    // cout << "Character Value: " << temp << endl;
    // cout << "ASCII Value: " << static_cast<int>(temp) <<endl;

    // changing the case of the character
    string name = "abdul";

    // using foreach loop
    for (char ch : name)
    {
        cout << char(ch - 32);
    }

    // using simple for loop
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

    // counting the vowel and the consonents characters in the string
    string A = "How are you?";

    int vowelcount = 0;
    int cosonantcount = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            vowelcount++;
        }

        else if ((static_cast<int>(A[i]) >= 97 && static_cast<int>(A[i] <= 122)) || (static_cast<int>(A[i]) >= 65 && static_cast<int>(A[i]) <= 90))
        {
            cosonantcount++;
        }
    }

    cout << "Vowels: " << vowelcount << endl;
    cout << "Consonent Count: " << cosonantcount << endl;

    // Number of words in a string (Sentence)
    string sentence = "How are you?";

    int wordcount = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' && sentence[i - 1] != ' ')
        {
            wordcount++;
        }
    }

    cout << "Total Words in sentence :" << sentence << " : " << wordcount+1 << endl;

    return 0;
}