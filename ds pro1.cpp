// ds pro1.cpp - Decimal to binary using a stack
#include <iostream>
#include <stack>
#include <string>

using namespace std;

string decimalToBinary(long long n) {
   if (n == 0) return "0";
   bool negative = n < 0;
   unsigned long long x = negative ? (unsigned long long)(-n) : (unsigned long long)n;
   stack<int> st;
   while (x > 0) {
      st.push(static_cast<int>(x % 2));
      x /= 2;
   }
   string result;
   if (negative) result.push_back('-');
   while (!st.empty()) {
      result.push_back(char('0' + st.top()));
      st.pop();
   }
   return result;
}

int main() {
   cout << "Enter an integer: ";
   long long value;
   if (!(cin >> value)) return 0;
   string bin = decimalToBinary(value);
   cout << "Binary: " << bin << '\n';
   return 0;
}