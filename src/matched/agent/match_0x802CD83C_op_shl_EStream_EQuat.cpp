// 0x802CD83C (208B) operator<<(EStream&, EQuat&)
// Stream out 4 floats via vtable-slot-7-via-6-fillers Write call.
// Vtable at stream+0x18 (after 0x18 of non-virtual prefix data).

class EQuat {
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

EStream& operator<<(EStream& s, EQuat& q);

EStream& operator<<(EStream& s, EQuat& q) {
    s << q.x << q.y << q.z << q.w;
    return s;
}
