#include <iostream>
#include "testlib.h"

using namespace std;

#define CASE_NUM 7

const int N_MAX = 500;
const int N_MIN = 300;

void start(int id) {

  ofstream out(format("60_kotatsu_dia_500_%02d.in", id).c_str());

  int H = rnd.next(N_MIN,N_MAX); //本来はH_MIN, H_MAXの様に変数ごとに上限下限を設定すべき。 
  int W = rnd.next(N_MIN,N_MAX);
  int A = rnd.next(N_MIN,N_MAX);
  int B = rnd.next(N_MIN,N_MAX);

  out << H << " " << W << " " << A << " " << B <<endl;

  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){

      if(i == 0 && j == 0) out << 'g';
      else if(i == H-1 && j == W-1) out << 's';
      else out << rnd.next("[.#*]");

    }

    out << endl;

  }

}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);
  for(int t = 0; t < CASE_NUM; ++t) {
    start(t);
  }
  return 0;
}
