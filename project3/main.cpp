#include <iostream>
#include "stack.h"
#define MaxLen 6
#define MaxHei 6
using namespace std;


char map[7][7] = {
        '#','#','#','#','#','#','#',
        '#','0','#','0','0','0','#',
        '#','0','#','0','#','#','#',
        '#','0','0','0','#','0','#',
        '#','0','#','0','0','0','#',
        '#','0','#','0','#','0','#',
        '#','#','#','#','#','#','#'
};

char answer_map[7][7] = {
        '#','#','#','#','#','#','#',
        '#','0','#','0','0','0','#',
        '#','0','#','0','#','#','#',
        '#','0','0','0','#','0','#',
        '#','0','#','0','0','0','#',
        '#','0','#','0','#','0','#',
        '#','#','#','#','#','#','#'
};

class step{
public:
    int x,y;
    step(int new_x,int new_y);
    step();

};

step::step(int new_x,int new_y) {
    x = new_x;
    y = new_y;
}

step::step() {
    x = y = 0;
}

step pre{0,0};
stack<step> path;

bool FindPath(step cur){
    if(cur.x == 5 && cur.y == 5){
        return true;
    }
    if(cur.y - 1 >= 0 && map[cur.x][cur.y - 1] == '0'){
        map[cur.x][cur.y] = 'x';
        if(FindPath({cur.x, cur.y - 1})){
            path.push(cur);
            return true;
        }
    }
    if(cur.y + 1 <= MaxLen && map[cur.x][cur.y + 1] == '0'){
        map[cur.x][cur.y] = 'x';
        if(FindPath({cur.x, cur.y + 1})){
            path.push(cur);
            return true;
        }
    }
    if(cur.x - 1 >= 0 && map[cur.x - 1][cur.y] == '0'){
        map[cur.x][cur.y] = 'x';
        if(FindPath({cur.x - 1, cur.y})){
            path.push(cur);
            return true;
        }
    }
    if(cur.x + 1 <= MaxHei && map[cur.x + 1][cur.y] == '0'){
        map[cur.x][cur.y] = 'x';
        if(FindPath({cur.x + 1, cur.y})){
            path.push(cur);
            return true;
        }
    }
    else {
        map[cur.x][cur.y] = 'x';
        return false;
    }
    return false;
}


int main() {
    cout<<"迷宫地图:"<<endl;
    cout << "		0列		1列		2列		3列		4列		5列		6列" << endl;
    for (int i = 0; i <= MaxHei; ++i) {
        cout<<i<<"行"<<"		";
        for (int j = 0; j <= MaxLen; ++j) {
            cout<<map[i][j]<<"		";
        }
        cout<<endl;
    }
    FindPath({1,1});

    if(path.IsEmpty()){//判读是否有路
        cout<<"无路径可走！"<<endl;
        return 0;
    }
    cout<<endl;
    cout << "迷宫路径:" << endl;
    while (!path.IsEmpty()) {
        cout << "<" << path.get_top().x << "," << path.get_top().y << ">" << " --> ";
        answer_map[path.get_top().x][path.get_top().y] = 'x';
        path.pop();
    }
    answer_map[5][5] = 'x';
    cout << "<5,5>" << endl;
    cout<<endl;
    cout<<"走法地图:"<<endl;
    cout << "		0列		1列		2列		3列		4列		5列		6列" << endl;
    for (int i = 0; i <= MaxHei; ++i) {
        cout<<i<<"行"<<"		";
        for (int j = 0; j <= MaxLen; ++j) {
            cout<<answer_map[i][j]<<"		";
        }
        cout<<endl;
    }

    return 0;
}
