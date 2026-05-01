// 0x802D26F8 operator>>(EStream&, EVec2&) (108 B)

class EVec2 {
public:
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
    virtual void Read(void* data, int size) = 0;
};

inline EStream& operator>>(EStream& s, float& f) {
    s.Read(&f, 4);
    return s;
}

EStream& operator>>(EStream& s, EVec2& v) {
    s >> v.x >> v.y;
    return s;
}
