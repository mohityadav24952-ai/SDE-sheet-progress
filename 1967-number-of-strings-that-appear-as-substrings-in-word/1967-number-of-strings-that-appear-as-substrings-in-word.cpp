// // ===================== STRING STL CHEATSHEET =====================

// // 1. Length of string
// s.size();              // Returns length
// s.length();            // Same as size()

// // 2. Find substring
// s.find(sub);           // Returns starting index, else string::npos

// // 3. Extract substring
// s.substr(start, len);  // Returns substring

// // 4. Append string
// s += t;
// s.append(t);           // Add t at end

// // 5. Insert string/char
// s.insert(pos, str);    // Insert at position

// // 6. Erase characters
// s.erase(pos, len);     // Delete len chars from pos

// // 7. Replace substring
// s.replace(pos, len, str); // Replace len chars with str

// // 8. Reverse string
// reverse(s.begin(), s.end());   // <algorithm>

// // 9. Sort string
// sort(s.begin(), s.end());      // <algorithm>

// // 10. Compare strings
// if(s == t) {}                  // Equality
// s.compare(t);                  // 0 if equal, <0 or >0 otherwise

// // ===================== BONUS (VERY USEFUL) =====================

// // Convert to lowercase
// tolower(ch);                   // Character only
// transform(s.begin(), s.end(), s.begin(), ::tolower);

// // Convert to uppercase
// toupper(ch);
// transform(s.begin(), s.end(), s.begin(), ::toupper);

// // Check character type
// isalnum(ch);   // Letter or digit
// isalpha(ch);   // Letter
// isdigit(ch);   // Digit
// islower(ch);   // Lowercase
// isupper(ch);   // Uppercase
// isspace(ch);   // Space/tab/newline

// // Count occurrences
// count(s.begin(), s.end(), 'a');   // <algorithm>

// // Remove consecutive duplicates
// s.erase(unique(s.begin(), s.end()), s.end());

// // Lexicographical next permutation
// next_permutation(s.begin(), s.end());

// // ===============================================================



class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n1 = patterns.size();
        int n2 = word.length();
         int c =0 ;

        for(int i=0 ; i<n1 ; i++){
            if(word.find(patterns[i]) < n2){
                c++ ;
            }
        }

        return c;
    }
};

