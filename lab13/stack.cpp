#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Function to reverse a string using stack
string reverseString(const string& input) {
stack<char> charStack;
// Push all characters of the string onto the stack
for (char ch : input) {
charStack.push(ch);
}
// Pop characters from the stack and form the reversed string
string reversed = "";
while (!charStack.empty()) {
reversed += charStack.top(); // Append the top element
charStack.pop(); // Remove the top element
}
return reversed;
}
int main() {
string input;
// Take input from the user
cout << "Enter a string to reverse: ";
getline(cin, input);
// Reverse the string using the stack
string reversed = reverseString(input);
// Display the result
cout << "Reversed string: " << reversed << endl;
return 0;
}