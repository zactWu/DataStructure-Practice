//
// Created by zact on 2019/12/7.
//

#ifndef PROJECT9_GRAPH_H
#define PROJECT9_GRAPH_H

#include "vector.h"
#include <string>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <memory.h>
#define MAX_SEMESTER 100
#define MAX_NEXT 10000

using namespace std;

string temp, INPUT_PATH="../input.txt", OUTPUT_PATH="../output.txt";
ifstream inf(INPUT_PATH);
ofstream outf(OUTPUT_PATH);

struct course{
    string code;
    string name;
    int hours = 0;
    int semester = 0;
    string s_hours, s_semester;
    Vector<string> pre_course;
    friend ifstream& operator>> (ifstream& out, course& cur_course) {
        string buffer;
        string temp_str;
        getline(inf, buffer);
        stringstream ss;
        ss << buffer;
        ss >> cur_course.code >> cur_course.name >> cur_course.s_hours >> cur_course.s_semester;
        stringstream check1(cur_course.s_hours), check2(cur_course.s_semester);
        if (!(check1 >> cur_course.hours) || !(check2 >> cur_course.semester)) {
            cerr << "输入有误！" << endl;
            exit(1);
        }
        while (ss >> temp_str) cur_course.pre_course.push_back(temp_str);
        return out;
    }
};

Vector<course> courses;
Vector<course> order_courses[MAX_SEMESTER];
Vector<int> next_course[MAX_NEXT];
int ind[10000], hours[1000], semCount[10000];
bool used[10000];
int maxSem=0, totalHours=0, curTotalHours=0;
int jumpDay[11]={0,1,3,5,2,4,1,3,5,2,4};
int jumpTime[5]={0,1,3,6,8};
int weektime[6][5]={{0,0,0,0,0},
                    {0,2,3,2,3},
                    {0,2,3,2,3},
                    {0,2,3,2,3},
                    {0,2,3,2,3},
                    {0,2,3,2,3}};
bool avai[6][5];
int table[15][15];
int atleast[1000];

class graph{
public:
    void build();
    int TopoSearch(int sem, int count);
    void output();
};

void graph::build(){
    cout << endl;
    cout << "是否使用默认路径？(Y/n)";
    cin >> temp;
    if (temp == "n") {
        cout << "请输入文件路径： " ;
        cin >> INPUT_PATH;
        inf.open(INPUT_PATH);
        if (!inf) {
            cerr << endl << "路径无效，使用默认路径！ " <<endl;
            INPUT_PATH="../input.txt";
            inf.open(INPUT_PATH);
        }
    }
    while (!inf.eof()) {
        course bufCourse;
        inf >> bufCourse;
        if (bufCourse.semester > maxSem) maxSem = bufCourse.semester;
        courses.push_back(bufCourse);
        totalHours += bufCourse.hours;
        ++semCount[bufCourse.semester];
    }
    for (int i = 0; i < courses.get_size(); ++i) {
        ind[i] = courses[i].pre_course.get_size();
        for (int j=0; j< courses.get_size(); ++j)
            for (int k=0; k<courses[j].pre_course.get_size(); ++k)
                if (courses[j].pre_course[k]==courses[i].code) {
                    next_course[i].push_back(j);
                    break;
                }
    }
}

int graph::TopoSearch(int sem, int count) {
    if(count == courses.get_size()) output();
    if (sem == maxSem +1) return 0;
    if (curTotalHours + (maxSem-sem+1)*50 < totalHours) return 0;
    if (hours[sem]>50) return 0;

    for (int i=0; i<courses.get_size(); ++i)
        if (courses[i].semester==0 || courses[i].semester==sem)
            if (ind[i]==0 && !used[i] && sem>=atleast[i]) {
                int tempLeast[1000];
                for (int j=0; j<next_course[i].get_size(); ++j) {
                    --ind[next_course[i][j]];
                    tempLeast[next_course[i][j]]=atleast[next_course[i][j]], atleast[next_course[i][j]]=sem+1;
                }
                used[i] = true; curTotalHours+=courses[i].hours; hours[sem]+=courses[i].hours;
                semCount[sem]-=(courses[i].semester==sem)?1:0;
                order_courses[sem].push_back(courses[i]);
                TopoSearch(sem, count+1);
                used[i] = false; curTotalHours-=courses[i].hours; hours[sem]-=courses[i].hours;
                semCount[sem]+=(courses[i].semester==sem)?1:0;
                order_courses[sem].Delete(order_courses[sem].get_size() - 1);
                for (int j=0; j<next_course[i].get_size(); ++j) {
                    ++ind[next_course[i][j]];
                    atleast[next_course[i][j]] = tempLeast[next_course[i][j]];
                }
            }
    if (semCount[sem]==0) TopoSearch(sem+1, count);
    return 0;
}

void graph::output() {
    for (int i=1; i<=maxSem; ++i) {
        memset(&table[0][0],0,sizeof(table));
        memset(avai,0,sizeof(avai));
        outf <<endl<< "第 " << i << " 学期: "<<endl ;
        if (i==6) {

        }
        for (int j = 0; j < order_courses[i].get_size(); ++j) {
            for (int d=1; d<=11; ++d)
                for (int t=4; t>=1; --t) {
                    if (!avai[jumpDay[d]][t] && weektime[jumpDay[d]][t] == 3 && order_courses[i][j].hours >= 3) {
                        avai[jumpDay[d]][t] = true;
                        order_courses[i][j].hours -= 3;
                        for (int k = 0; k < weektime[jumpDay[d]][t]; ++k) table[jumpDay[d]][jumpTime[t] + k] = j + 1;
                        break;
                    }

                    if (!avai[jumpDay[d]][t] && weektime[jumpDay[d]][t] == 2 && order_courses[i][j].hours >= 2) {
                        avai[jumpDay[d]][t] = true;
                        order_courses[i][j].hours -= 2;
                        for (int k = 0; k < weektime[jumpDay[d]][t]; ++k) table[jumpDay[d]][jumpTime[t] + k] = j + 1;
                        break;
                    }
                }
        }
        for (int j = 0; j < order_courses[i].get_size(); ++j)
            while (order_courses[i][j].hours>0)
                for (int k = 1; k<=50; ++k)
                    if (table[(k/10)+1][k%10+1]==0) {
                        table[(k/10)+1][k%10+1]=j;
                        --order_courses[i][j].hours;
                        break;
                    }
        for (int p=1; p<=10; ++p) {
            for (int j = 1; j <= 5; ++j)
                if (table[j][p]==0) outf << setw(5) << setiosflags(ios::left) << "无  ";
                else outf << setw(5) << setiosflags(ios::left) << order_courses[i][table[j][p]-1].name << "  ";
            outf << endl;
        }
        outf << endl;
    }
    cout << endl << "课表保存成功！ " <<endl;
    inf.close();
    outf.close();
    system("pause");
    exit(0);
}

#endif //PROJECT9_GRAPH_H
