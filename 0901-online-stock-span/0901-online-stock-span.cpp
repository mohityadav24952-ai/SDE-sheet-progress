#include <stack>
#include <vector>
#include <utility>

using namespace std;

class StockSpanner {
private:
    // Stack of pairs to store {price, index}
    stack<pair<int, int>> s; 
    // Vector 'v' jo tumhare notes ki tarah NGL indices store karega
    vector<int> v;           

public:
    StockSpanner() {
        // Constructor me kuch karne ki zaroorat nahi hai, automatic init ho jayega
    }
    
    int next(int price) {
        // Jo vector ka size hai, wahi hamara current index 'i' hai
        int i = v.size(); 
        
        // --- EXACTLY TUMHARI IMAGE WAALA LOGIC ---
        
        if (s.size() == 0) {
            v.push_back(-1);
        } 
        else if (s.size() > 0 && s.top().first > price) {
            v.push_back(s.top().second);
        } 
        else if (s.size() > 0 && s.top().first <= price) {
            
            while (s.size() > 0 && s.top().first <= price) {
                s.pop();
            }
            
            if (s.size() == 0) {
                v.push_back(-1);
            } else {
                v.push_back(s.top().second);
            }
        }
        
        // Current price aur uske index ko stack mein push karo
        s.push({price, i});
        
        // --- END OF IMAGE LOGIC ---
        
        // Notes ke bottom-right corner waala logic: v[i] = i - v[i]
        // Yahan hum direct current element ka span nikal kar return kar rahe hain
        int span = i - v[i]; 
        
        return span;
    }
};