// 0x802D2530 operator<<(EStream&, EBound3&) (52 B)

class EVec3 {
public:
    float x, y, z;
};

class EStream {
public:
    char pad[0x18];
};

class EBound3 {
public:
    EVec3 min;
    EVec3 max;
};

EStream& operator<<(EStream& s, EVec3& v);

EStream& operator<<(EStream& s, EBound3& b) {
    return s << b.min << b.max;
}
