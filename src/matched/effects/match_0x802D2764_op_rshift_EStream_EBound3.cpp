// 0x802D2764 operator>>(EStream&, EBound3&) (52B)

struct EVec3 { float x, y, z; };
struct EStream {};
EStream& operator>>(EStream& s, EVec3& v);

struct EBound3 {
    EVec3 min;
    EVec3 max;
};

EStream& operator>>(EStream& s, EBound3& b) {
    return operator>>(operator>>(s, b.min), b.max);
}
