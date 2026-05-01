// 0x802D2338 (208B) operator<<(EStream&, EVec4&)
// Twin of EQuat version (byte-identical compiled code).

class EVec4 {
public:
    float x, y, z, w;
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

EStream& operator<<(EStream& s, EVec4& v);

EStream& operator<<(EStream& s, EVec4& v) {
    s << v.x << v.y << v.z << v.w;
    return s;
}
