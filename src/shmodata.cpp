#include "shmodata.h"

namespace shmo {

std::ostream& operator<<(std::ostream& o, const ShmoResults& r) {
  auto print_vector = [&](auto v) {
    o << "\t[\n";
    for (int i = 0; i < r.time.size(); ++i) {
      o << "\t  " << v[i] << ",\n";
    }
    o << "\t]\n";
  };

  o << "time:\n";
  print_vector(r.time);
  o << "\n";

  o << "position:\n";
  print_vector(r.position);
  o << "\n";

  return o;
}

}  // namespace shmo
