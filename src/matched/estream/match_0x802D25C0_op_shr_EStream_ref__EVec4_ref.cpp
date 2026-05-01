// Match attempt: operator>>(EStream&, EVec4&)
// Address: 0x802D25C0 | Size: 172 bytes

struct EVec4 {
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
    virtual void Read(void* data, int size) = 0;
    virtual void Write(void* data, int size) = 0;
};

inline EStream& operator>>(EStream& s, float& f) {
    s.Read(&f, 4);
    return s;
}

EStream& operator>>(EStream& s, EVec4& v) {
    s >> v.x >> v.y >> v.z >> v.w;
    return s;
}
