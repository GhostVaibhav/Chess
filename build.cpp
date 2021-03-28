#include<bits/stdc++.h>
using namespace std;
int main(int argc,char* argv[]) {
    for(int i = 1 ; i < argc ; i++) {
        string fileName = argv[1];
        string cmd;
        cmd = "g++ -Isrc/include -c " + fileName + ".cpp";
        system(cmd.c_str());
        cmd = "g++ " + fileName + ".o -o " + fileName + " -Lsrc/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system icon.res";
        system(cmd.c_str());
        cmd = "del " + fileName + ".o";
        system(cmd.c_str());
        cmd = "move " + fileName + ".exe Builds > NUL";
        system(cmd.c_str());
        cmd = "cd Builds && call " + fileName + ".exe";
        system(cmd.c_str());
        system("cls");
    }
    return 0;
}