#include "util.hpp"

namespace calendario {

  bool es_bisiesto(int anyo) {
    return (anyo % 4 == 0) && (anyo % 100 !=0) || (anyo % 400 == 0);
  }
}