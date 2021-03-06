#include <array>
#include <map>

using namespace std;

map<array<int, 4>, int> boxdraw_map =
  map<array<int, 4>, int> { 
  {array<int, 4> {0, 0, 0, 0}, 32},
  {array<int, 4> {1, 0, 1, 0}, 9472},
  {array<int, 4> {2, 0, 2, 0}, 9473},
  {array<int, 4> {0, 1, 0, 1}, 9474},
  {array<int, 4> {0, 2, 0, 2}, 9475},
  {array<int, 4> {1, 0, 0, 1}, 9484},
  {array<int, 4> {2, 0, 0, 1}, 9485},
  {array<int, 4> {1, 0, 0, 2}, 9486},
  {array<int, 4> {2, 0, 0, 2}, 9487},
  {array<int, 4> {0, 0, 1, 1}, 9488},
  {array<int, 4> {0, 0, 2, 1}, 9489}, 
  {array<int, 4> {0, 0, 1, 2}, 9490},
  {array<int, 4> {0, 0, 2, 2}, 9491},
  {array<int, 4> {1, 1, 0, 0}, 9492}, 
  {array<int, 4> {2, 1, 0, 0}, 9493},
  {array<int, 4> {1, 2, 0, 0}, 9494},
  {array<int, 4> {2, 2, 0, 0}, 9495},
  {array<int, 4> {0, 1, 1, 0}, 9496},
  {array<int, 4> {0, 1, 2, 0}, 9497},
  {array<int, 4> {0, 2, 1, 0}, 9498},
  {array<int, 4> {0, 2, 2, 0}, 9499},
  {array<int, 4> {1, 1, 0, 1}, 9500}, 
  {array<int, 4> {2, 1, 0, 1}, 9501},
  {array<int, 4> {1, 2, 0, 1}, 9502},
  {array<int, 4> {1, 1, 0, 2}, 9503},
  {array<int, 4> {1, 2, 0, 2}, 9504},
  {array<int, 4> {2, 2, 0, 1}, 9505},
  {array<int, 4> {2, 1, 0, 2}, 9506},
  {array<int, 4> {2, 2, 0, 2}, 9507},
  {array<int, 4> {0, 1, 1, 1}, 9508},
  {array<int, 4> {0, 1, 2, 1}, 9509}, 
  {array<int, 4> {0, 2, 1, 1}, 9510},
  {array<int, 4> {0, 1, 1, 2}, 9511},
  {array<int, 4> {0, 2, 1, 2}, 9512},
  {array<int, 4> {0, 2, 2, 1}, 9513},
  {array<int, 4> {0, 1, 2, 2}, 9514},
  {array<int, 4> {0, 2, 2, 2}, 9515},
  {array<int, 4> {1, 0, 1, 1}, 9516}, 
  {array<int, 4> {1, 0, 2, 1}, 9517},
  {array<int, 4> {2, 0, 1, 1}, 9518},
  {array<int, 4> {2, 0, 2, 1}, 9519}, 
  {array<int, 4> {1, 0, 1, 2}, 9520},
  {array<int, 4> {1, 0, 2, 2}, 9521},
  {array<int, 4> {2, 0, 1, 2}, 9522},
  {array<int, 4> {2, 0, 2, 2}, 9523},
  {array<int, 4> {1, 1, 1, 0}, 9524},
  {array<int, 4> {1, 1, 2, 0}, 9525}, 
  {array<int, 4> {2, 1, 1, 0}, 9526},
  {array<int, 4> {2, 1, 2, 0}, 9527},
  {array<int, 4> {1, 2, 1, 0}, 9528},
  {array<int, 4> {1, 2, 2, 0}, 9529},
  {array<int, 4> {2, 2, 1, 0}, 9530},
  {array<int, 4> {2, 2, 2, 0}, 9531},
  {array<int, 4> {1, 1, 1, 1}, 9532},
  {array<int, 4> {1, 1, 2, 1}, 9533},
  {array<int, 4> {2, 1, 1, 1}, 9534},
  {array<int, 4> {2, 1, 2, 1}, 9535},
  {array<int, 4> {1, 2, 1, 1}, 9536},
  {array<int, 4> {1, 1, 1, 2}, 9537},
  {array<int, 4> {1, 2, 1, 2}, 9538},
  {array<int, 4> {1, 2, 2, 1}, 9539},
  {array<int, 4> {2, 2, 1, 1}, 9540}, 
  {array<int, 4> {1, 1, 2, 2}, 9541}, 
  {array<int, 4> {2, 1, 1, 2}, 9542},
  {array<int, 4> {2, 2, 2, 1}, 9543},
  {array<int, 4> {2, 1, 2, 2}, 9544}, 
  {array<int, 4> {1, 2, 2, 2}, 9545},
  {array<int, 4> {2, 2, 1, 2}, 9546},
  {array<int, 4> {2, 2, 2, 2}, 9547},
  {array<int, 4> {0, 0, 1, 0}, 9588},
  {array<int, 4> {0, 1, 0, 0}, 9589},
  {array<int, 4> {1, 0, 0, 0}, 9590},
  {array<int, 4> {0, 0, 0, 1}, 9591},
  {array<int, 4> {0, 0, 2, 0}, 9592}, 
  {array<int, 4> {0, 2, 0, 0}, 9593}, 
  {array<int, 4> {2, 0, 0, 0}, 9594},
  {array<int, 4> {0, 0, 0, 2}, 9595}, 
  {array<int, 4> {2, 0, 1, 0}, 9596}, 
  {array<int, 4> {0, 1, 0, 2}, 9597},
  {array<int, 4> {1, 0, 2, 0}, 9598},
  {array<int, 4> {0, 2, 0, 1}, 9599} };
  

