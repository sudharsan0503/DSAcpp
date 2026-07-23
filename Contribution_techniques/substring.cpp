#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to solve a single test case
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // Array to store the last seen index of each lowercase character ('a' through 'z')
    // Initialized to -1 because no characters have been seen before the loop starts
    vector<int> last_seen(26, -1);
    long long total_score = 0;
    
    // Iterate through each character in the string
    for (int i = 0; i < n; i++) {
        int char_idx = s[i] - 'a'; // Convert character to an index from 0 to 25
        int prev = last_seen[char_idx]; // Fetch the index of its previous occurrence
        
        // Calculate the number of choices for the left and right boundaries
        long long left_choices = i - prev;
        long long right_choices = n - i;
        
        // Multiply choices to get the total valid substrings where s[i] is a unique contributor
        total_score += (left_choices * right_choices);
        
        // Update the history: the current index becomes the new 'prev' for future occurrences
        last_seen[char_idx] = i;
    }
    
    // Output the final accumulated score for the current test case
    cout << total_score << "\n";
}

int main() {
    // Optimize standard input/output streams for speed execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}