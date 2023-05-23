
#include <string>
using namespace std;
#include <iostream>

// Returns the product of two non-negative integers, m and n,
// using only repeated addition.
int multiplyTwoNumbers(unsigned int m, unsigned int n);

// Returns the number of occurrences of digit in the decimal
// representation of num. digit is an int between 0 and 9
// inclusive.
int tabulationStation(int num, int digit);

// Returns a string where the same characters next each other in
// string n are separated by "55" (you can assume the input
// string will not have 5’s)
string highFives(string n);

// str contains a single pair of parentheses, return a new
// string made of only the parentheses and whatever those
// parentheses contain
string jheriCurls(string str);

// Return true if the total of any combination of elements in
// the array a equals the value of the target.
bool aggregationNation(const int a[], int size, int target);

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise
bool onMyWayHome(string maze[], int nRows, int nCols,
                 int sr, int sc, int er, int ec);

int main() {
    cout << multiplyTwoNumbers(0, 0) << endl;
    cout << multiplyTwoNumbers(1, 0) << endl;
    cout << multiplyTwoNumbers(0, 1) << endl;
    cout << multiplyTwoNumbers(6, 7) << endl << endl;
    
    cout << tabulationStation(0, 0) << endl;
    cout << tabulationStation(18838, 8) << endl;
    cout << tabulationStation(55555, 3) << endl;
    cout << tabulationStation(55555, 5) << endl;
    cout << tabulationStation(-222, 2) << endl;
    cout << tabulationStation(765387, 7) << endl << endl;
    
    cout << highFives("djs") << endl;
    cout << highFives("") << endl;
    cout << highFives(" ") << endl;
    cout << highFives("goodbye") << endl;
    cout << highFives("yyuu") << endl;
    cout << highFives("aaaa") << endl << endl;
    
    cout << jheriCurls("abc{ghj}789") << endl;
    cout << jheriCurls("{x}7") << endl;
    cout << jheriCurls("4agh{y}") << endl;
    cout << jheriCurls("4agh{}") << endl;
    cout << jheriCurls("{}") << endl << endl;

    int a[] = {2, 4, 8};
    int b[] = {};
   cout << boolalpha;
    cout << aggregationNation(a, 3, 10) << endl; // => true
    cout << aggregationNation(a, 3, 6) << endl; // => true
    cout << aggregationNation(a, 3, 11) << endl; // => false
    cout << aggregationNation(a, 3, 0) << endl; // => true
    cout << aggregationNation(a, 3, 14) << endl; // => true
    cout << aggregationNation(b, 0, 0) << endl; // => true
    int c[] = {-3, 5, 2};
    cout << aggregationNation(c, 3, 4) << endl; // => true
    cout << aggregationNation(c, 2, 2) << endl; // => true
    cout << aggregationNation(c, 2, -4) << endl; // => false
    
    string maze[10] = {
     "XXXXXXXXXX",
     "X.......@X",
     "XX@X@@.XXX",
     "X..X.X...X",
     "X..X...@.X",
     "X....XXX.X",
     "X@X....XXX",
     "X..XX.XX.X",
     "X...X....X",
     "XXXXXXXXXX"
     };

     if (onMyWayHome(maze, 10, 10, 6, 4, 1, 1))
     cout << "Solvable!" << endl;
     else
     cout << "Out of luck!" << endl;
    return 0;
}


int multiplyTwoNumbers(unsigned int m, unsigned int n)
{
    if (m == 0 || n == 0) {
        return 0;
    }
    return multiplyTwoNumbers(m-1, n-1) + m + n -1;
}


int tabulationStation(int num, int digit)
{
    if (num == 0) {
        return 0;
    }
    if (num < 0){
        num *= -1;
    }
    return (num%10 == digit) + tabulationStation(num/10,digit);
}



string highFives(string n)
{
    if (n == ""){
        return "";
    }
    string part1 = n.substr(0,1);
    string part2 = n.substr(1);
    if (part1 == part2.substr(0,1)){
        part1= part1 + "55";
    }
    return part1 + highFives(part2);
}


string jheriCurls(string str)
{
    if (str[0] == '{' && str[str.length() -1] == '}'){
        return str;
    }
    if (str[0] != '{'){
        str = str.substr(1);
    }
    if (str[str.length()-1] != '}'){
        str = str.substr(0, str.length()-1);
    }
    return jheriCurls (str);
}


bool aggregationNation(const int a[], int size, int target)
{
    if (target == 0){
        return true;
    }
    if (size == 0 && target != 0){
        return false;
    }
    return aggregationNation(a+1, size-1, target - a[0]) ||
    aggregationNation(a+1, size-1, target);
}


bool onMyWayHome(string maze[], int nRows, int nCols,
                 int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec){
        return true;
    }
    maze[sr][sc] = '#';
    if (maze[sr-1][sc] == '.'){
        if (onMyWayHome(maze, nRows, nCols, sr-1, sc, er, ec)){
            return true;
        }
    }
    if (maze[sr+1][sc] == '.'){
        if (onMyWayHome(maze, nRows, nCols, sr+1, sc, er, ec)){
            return true;
        }
    }
    if (maze[sr][sc-1] == '.'){
        if (onMyWayHome(maze, nRows, nCols, sr, sc-1, er, ec)){
            return true;
        }
    }
    if (maze[sr][sc+1] == '.'){
        if (onMyWayHome(maze, nRows, nCols, sr, sc+1, er, ec)){
            return true;
        }
    }
    return false;
}
