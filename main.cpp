#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
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
    cout<<"Enter resolution (size of screen):";
    cin>>size;

    char**screen=new char*[size];
    for(int i=0;i<size;i++){
        screen[i]=new char[size];
    }

    int type;
    cout << "Enter 1 for Solid, 2 for Hollow: ";
    cin >> type;
    bool hollowChoice = (type == 2);

    string shape;
    cout << "What shape do you want? (circle/square): ";
    cin >> shape;

    if (shape == "circle") {
        float r;
        cout << "Enter radius: ";
        cin >> r;
        rendercircle(screen,size, r, hollowChoice);
    } else if(shape=="square"){
            int side;
            cout<<"give side:"<<" ";
            cin>>side;
            rendersquare(screen,size,side,hollowChoice);
        }
    printScreen(screen,size);
    for(int i=0;i<size;i++){
        delete[] screen[i];
    }
    delete[] screen;

    return 0;
}