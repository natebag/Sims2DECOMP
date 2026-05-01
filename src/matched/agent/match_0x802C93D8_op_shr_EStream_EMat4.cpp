// 0x802C93D8 operator>>(EStream&, EMat4&) (124 B)

class EMat4 {
public:
    float m[4][4];
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

EStream& operator>>(EStream& s, EMat4& m) {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            s >> m.m[i][j];
        }
    }
    return s;
}
