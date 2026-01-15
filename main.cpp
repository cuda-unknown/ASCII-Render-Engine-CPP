#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
char screen[40][40]; 

void rotateframe(int size) {
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
void rendercircle(int size, float radius) {
    float centerX = size / 2.0;
    float centerY = size / 2.0;

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            screen[i][j] = ' ';
        }
    }

    for(int y = 0; y < size; y++) {
        for(int x = 0; x < size; x++) {
            float dx = x - centerX;
            float dy = y - centerY;

            float distance = sqrt(dx*dx + dy*dy);
            
            //hollow logic :

            if(abs(distance - radius) < 0.5) { 
                screen[y][x] = '#';
            } else {
                screen[y][x] = ' ';
            }
        }
    }

    rotateframe(size);
    
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << screen[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    int size=30;
    string shape;
    cout << "What shape do you want? (circle/square): ";
    cin >> shape;

    if (shape == "circle") {
        float r;
        cout << "Enter radius: ";
        cin >> r;
        rendercircle(size, r);
    } else {
        cout << "Shape not supported yet!" << endl;
    }

    return 0;
}