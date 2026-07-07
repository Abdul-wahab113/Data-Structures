#include <iostream>
#include <string>

using namespace std;

// =========================================================================
// SECTION 1: Character Basics & ASCII Values
// =========================================================================
// Time Complexity: O(1) | Space Complexity: O(1)
void demonstrateCharacterBasics()
{
    char temp = 'C';
    cout << "Character Value: " << temp << endl;
    cout << "ASCII Value: " << static_cast<int>(temp) << endl;
}

// =========================================================================
// SECTION 2: Changing the Case of a String
// =========================================================================
void demonstrateCaseConversion()
{
    string name = "abdul";

    // --- Task 2.1: Print Uppercase Using Range-Based for Loop (Temporary) ---
    // Time Complexity: O(n) | Space Complexity: O(1)
    // Note: Prints uppercase characters directly without modifying the original string.
    for (char ch : name)
    {
        cout << char(ch - 32);
    }
    cout << endl;

    // --- Task 2.2: Convert to Uppercase In-Place Using Standard for Loop ---
    // Time Complexity: O(n) | Space Complexity: O(1)
    // Lowercase to Uppercase: Subtract 32 from ASCII value
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = name[i] - 32;
    }
    cout << "Upper Case: " << name << endl;

    // --- Task 2.3: Convert to Lowercase In-Place Using Standard for Loop ---
    // Time Complexity: O(n) | Space Complexity: O(1)
    // Uppercase to Lowercase: Add 32 to ASCII value
    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = name[i] + 32;
    }
    cout << "Lower Case: " << name << endl;
}

// =========================================================================
// SECTION 3: Toggling the Case of Characters in a String
// =========================================================================
// Time Complexity: O(n) | Space Complexity: O(1)
void demonstrateToggleCase()
{
    string message = "HelLo dEar";
    cout << "Original Message: " << message << endl;

    for (int i = 0; message[i] != '\0'; i++)
    {
        // Check if uppercase alphabet
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            message[i] = message[i] + 32;
        }
        // Check if lowercase alphabet
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            message[i] = message[i] - 32;
        }
    }
    cout << "Toggled Alphabets Message: " << message << endl;
}

// =========================================================================
// SECTION 4: Counting Vowels and Consonants
// =========================================================================
// Time Complexity: O(n) | Space Complexity: O(1)
void countVowelsAndConsonants()
{
    string A = "How are you?";
    int vowelcount = 0;
    int cosonantcount = 0;

    for (int i = 0; A[i] != '\0'; i++)
    {
        // Check if character is a vowel (both lowercase and uppercase)
        if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' ||
            A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
        {
            vowelcount++;
        }
        // Check if character is a consonant (alphabetic character but not a vowel)
        else if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z'))
        {
            cosonantcount++;
        }
    }
    cout << "Vowels: " << vowelcount << endl;
    cout << "Consonent Count: " << cosonantcount << endl;
}

// =========================================================================
// SECTION 5: Counting the Number of Words in a Sentence
// =========================================================================
// Time Complexity: O(n) | Space Complexity: O(1)
void countWords()
{
    string sentence = "How are you?";
    int wordcount = 0;

    // Counts spaces that are preceded by a non-space character to avoid consecutive space bugs.
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' && sentence[i - 1] != ' ')
        {
            wordcount++;
        }
    }
    cout << "Total Words in sentence :" << sentence << " : " << wordcount + 1 << endl;
}

void checkPalindrome()
{
    string str = "madam";
    bool ispalindrome = true;

    for (int i = 0, j = str.size() - 1; i < j; i++, j--)
    {
        if (str[i] != str[j])
        {
            ispalindrome = false;
            break;
        }
    }

    if (ispalindrome)
    {
        cout << "Palindrome found" << endl;
    }

    else
    {
        cout << "Not a palindrome" << endl;
    }
}
int main()
{
    // Execute each demonstration function
    demonstrateCharacterBasics();
    cout << endl;

    demonstrateCaseConversion();

    demonstrateToggleCase();
    cout << endl;

    countVowelsAndConsonants();
    cout << endl;

    countWords();
    cout << endl;

    checkPalindrome();
    cout << endl;

    return 0;
}
