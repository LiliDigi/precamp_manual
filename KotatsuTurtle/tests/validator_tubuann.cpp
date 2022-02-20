#include "testlib.h"
#include<cassert>
#include<set>
#include<vector>
#include<cstdlib>
#include<iostream>
using namespace std;

static const int W_MIN=1;
static const int W_MAX=1000;
static const int COST_MIN=1;
static const int COST_MAX=1000;


int main(){
    registerValidation();
    int scnt=0,gcnt=0;
    int H=inf.readInt(W_MIN, W_MAX);
    inf.readSpace();
    int W=inf.readInt(W_MIN, W_MAX);
    inf.readSpace();
    int A=inf.readInt(COST_MIN, COST_MAX);
    inf.readSpace();
    int B=inf.readInt(COST_MIN, COST_MAX);
    assert(H+W>=3);
    inf.readEoln();
    for(int i=0;i<H;i++){
        for(int t=0;t<W;t++){
            char c;
            assert(scanf("%c",&c)==1);
            assert(c=='*' || c=='.' || c=='#' || c=='s' || c=='g');
            if(c=='s'){scnt++;}
            else if(c=='g'){gcnt++;}
        }
        inf.readEoln();
    }
    assert(scnt==1 && gcnt==1);
    inf.readEof();

  return 0;
}
