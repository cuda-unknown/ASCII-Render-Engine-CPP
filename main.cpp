#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include <stdlib.h>
#include"solver.h"
using namespace std;

#define SHAPE_CHAR '#'
#define BLANK_CHAR ' '

inline void printScreen(char** screen, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}

void rotateframe(char**screen,int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            swap(screen[i][j], screen[j][i]);
        }
    }
    for(int i = 0; i < size; i++) {
        int start = 0;
        int end = size - 1;
        while(start < end) {
            swap(screen[i][start], screen[i][end]);
            start++;
            end--;
        }
    }
}
void rendersquare(char** screen, int size, int side=10, bool ishollow=true) {
    int centerX = size / 2;
    int centerY = size / 2;
    int halfSide = side / 2;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) screen[i][j] = BLANK_CHAR;
    }

    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            bool inX = (x >= centerX - halfSide && x <= centerX + halfSide);
            bool inY = (y >= centerY - halfSide && y <= centerY + halfSide);

            if (inX && inY) {
                if (ishollow) {
                    if (x == centerX - halfSide || x == centerX + halfSide || 
                        y == centerY - halfSide || y == centerY + halfSide) {
                        screen[y][x] = SHAPE_CHAR;
                    }
                } else {
                    screen[y][x] = SHAPE_CHAR;
                }
            }
        }
    }
}
void rendercircle(char**screen,int size, float radius=5.0,bool ishollow=true) {
    float centerX = size / 2.0;
    float centerY = size / 2.0;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            screen[i][j] = BLANK_CHAR;
        }
    }

    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            float dx = x - centerX;
            float dy = y - centerY;

            float distance = sqrt(dx*dx + dy*dy);
            
            //hollow logic :
            if (ishollow){
            if(abs(distance - radius) < 0.5)screen[y][x] = SHAPE_CHAR;
            }else {
                if(distance < radius) screen[y][x] = SHAPE_CHAR;
            }
        }   
    }   

    rotateframe(screen,size);
}
int main() {
    int size;
    cout << "Enter resolution (size of screen): ";
    cin >> size;

    char** screen = new char*[size];
    for(int i = 0; i < size; i++) screen[i] = new char[size];

    while (true) { 
        system("cls");
        cout << "=== ZEPHYRUS COMMAND CENTER ===" << endl;
        cout << "1. Render Square" << endl;
        cout << "2. Render Circle" << endl;
        cout << "3. Anagram Checker (LeetCode #242)" << endl;
        cout << "4. Ransom Note Logic (LeetCode #383)" << endl;
        cout << "5. Exit" << endl;
        cout << "===============================" << endl;
        cout << "Enter Choice: ";
        
        int choice;
        cin >> choice;
        if (choice == 5) break; 

        switch(choice) {
            case 1: 
            case 2: {
                int type;
                cout << "Enter 1 for Solid, 2 for Hollow: "; cin >> type;
                bool hollow = (type == 2);
                if(choice == 1) {
                    int side; cout << "Give side: "; cin >> side;
                    rendersquare(screen, size, side, hollow);
                } else {
                    float r; cout << "Enter radius: "; cin >> r;
                    rendercircle(screen, size, r, hollow);
                }
                printScreen(screen, size);
                break;
            }
            case 3: { 
                string s1, s2;
                cout << "String 1: "; cin >> s1;
                cout << "String 2: "; cin >> s2;
                if(isAnagram(s1, s2)) cout << "\n[SUCCESS] These are Anagrams!" << endl;
                else cout << "\n[FAILED] Not Anagrams." << endl;
                break;
            }
            case 4: {
                string note, mag;
                cout << "Ransom Note: "; cin >> note;
                cout << "Magazine: "; cin >> mag;
                if(canConstruct(note, mag)) cout << "\n[SUCCESS] Note can be formed!" << endl;
                else cout << "\n[FAILED] Not enough letters." << endl;
                break;
            }
        }

        cout << "\nPress Enter to return to menu...";
        cin.ignore();
        cin.get(); 
    }
    for(int i=0;i<size;i++){
        delete[] screen[i];
    }
    delete[] screen;

    return 0;
}