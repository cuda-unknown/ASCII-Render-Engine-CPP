#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void rendercircle(int width,int height,float radius ){
      float centerX=width/2.0;
      float centerY=height/2.0;

      for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            float dx=x-centerX;
            float dy=y-centerY;
            float distance=sqrt(dx*dx+dy*dy);

            if(distance<radius){
                cout<<"#";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int width=40;
    int height=20;
    int radius=8.0;
    rendercircle(width,height,radius);
    return 0;
}