#include <iostream>
using namespace std;
int main() {
   int arr[10];
   for (int i = 0; i < 10; i++) {
       arr[i] = i + 1;
   }
   for (int i = 0; i < 10; i++) {
       cout << "\nArr[" << i << "] = " << arr[i];
   }

   return 0;
}