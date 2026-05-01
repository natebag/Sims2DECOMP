// Match attempt: operator<<(EStream&, EVec2&)
// Address: 0x802D24B0 | Size: 128 bytes

struct EVec2 {
    float x, y;
};

class EStream {
public:
    char pad[0x18];
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Filler3() = 0;
    virtual void Filler4() = 0;
    virtual void Filler5() = 0;
    virtual void Filler6() = 0;
    virtual void Write(void* data, int size) = 0;
};

inline EStream& operator<<(EStream& s, float f) {
    s.Write(&f, 4);
    return s;
}

EStream& operator<<(EStream& s, EVec2& v) {
    s << v.x << v.y;
    return s;
}
