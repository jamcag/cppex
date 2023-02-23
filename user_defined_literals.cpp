#include <iostream>

class distance {
public:
    distance(double distance_m) : distance_m_{distance_m} {}
    friend std::ostream& operator<<(std::ostream& os, const distance& dist);
private:
    double distance_m_;
};

std::ostream& operator<<(std::ostream& os, const distance& dist) {
    os << dist.distance_m_;
    return os;
}

namespace distance_literals {
    distance operator""_km(long double km) {
        return distance(1000*km);
    }

    distance operator""_cm(long double cm) {
        return distance(cm / 100);
    }
}

int main() {
    using namespace distance_literals;
    auto d = 1._km;
    auto d2 = 1._cm;
    std::cout << d << "\n";
    std::cout << d2 << "\n";
}
