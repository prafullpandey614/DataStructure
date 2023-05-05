class Solution {
public:
    // Helper function to check if a character is a vowel
    bool isVowel(char c){
        char t = tolower(c);
        return t == 'a' or t == 'e' or t=='i' or t=='o' or t=='u';
    }
    
    int maxVowels(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;

        int ans = 0;  // Initialize the maximum number of vowels to 0
        int temp = 0;  // Initialize a temporary count of vowels in the current window

        // Loop through the string with a sliding window approach
        while(end < n){
            // If the current character is a vowel, increment the temporary count
            if(isVowel(s[end])){
               temp++;
           }
          
           // If the window size is equal to k+1, slide the window by moving the start pointer
           if(end-start == k ){
               if(isVowel(s[start])){
                   temp--;  // Decrement the temporary count if the first character in the window is a vowel
               }
               start++;  
           }
           
           ans = max(ans, temp);  // Update the maximum number of vowels found so far
           end++;  // Move the end pointer to expand the window
        }
        
        return ans; 
    }
};
