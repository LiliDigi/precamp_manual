#include <iostream>
#include <string>
#include <cassert>

#include "testlib.h"

using namespace std;

const int MIN_N = 1;
const int MAX_N = 1000;

int main(){

    registerValidation();

    int H = inf.readInt(MIN_N, MAX_N, format("H")); //本来はH_MIN, H_MAXの様に変数ごとに上限下限を設定すべき。
    inf.readSpace();

    int W = inf.readInt(MIN_N, MAX_N, format("W"));
    inf.readSpace();

    int A = inf.readInt(MIN_N, MAX_N, format("A"));
    inf.readSpace();

    int B = inf.readInt(MIN_N, MAX_N, format("B"));

    ensuref(isEoln(inf.readChar()), to_string(__LINE__).c_str()); //これは1文字charで読み込んでEolnか判定している。エラーを特定する為に使用した。

    if(H + W < 3) assert(0); //assertは避けられるなら避けてtestlib.hの機能を使った方がいいらしい。

    int how_many_s=0;
    int how_many_g=0;

    for(int i = 0; i < H; i++){

        string s = inf.readToken(format("[sg.#*]{%d}", W), format("s[%d]", i+1)); // formatの[]内の文字のみで構成されているかどうかチェックしている。また長さがWであるかどうかをチェックしている。

        for(int j = 0; j < s.size(); j++){

            if(s[j] == 's') how_many_s++;
            else if(s[j] == 'g') how_many_g++;

        }

        ensuref(isEoln(inf.readChar()), to_string(__LINE__).c_str());

    }

    if(!(how_many_s == 1 && how_many_g == 1)) assert(0);

    inf.readEof();

    return 0;

}
