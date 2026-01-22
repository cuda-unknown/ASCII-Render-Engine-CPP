#ifndef SOLVER_H
#define SOLVER_H

#include <string>
using namespace std;

// No class needed here, just the logic
bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    int count[26] = {0};
    for(int i = 0; i < s.length(); i++) {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }
    for(int ans : count) if(ans != 0) return false;
    return true;
}

bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.length() > magazine.length()) return false;
    int count[26] = {0};
    for(char c : magazine) count[c-'a']++;
    for(char c : ransomNote) {
        count[c-'a']--;
        if(count[c-'a'] < 0) return false;
    }
    return true;
}

#endif