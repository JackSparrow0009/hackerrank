/*
 * Challenges: https://www.hackerrank.com/challenges/drawing-book/problem
 */
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    int res1 = p / 2;
    int res2 = (n - p + 1) / 2;

    if (n % 2 == 1) {
      res2 = (n - p) / 2;
    }

    if (res1 > res2) return res2;
    return res1;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = pageCount(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

