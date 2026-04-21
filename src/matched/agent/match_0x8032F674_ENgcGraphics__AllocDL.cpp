// 0x8032F674 (72B) ENgcGraphics::AllocDL(RCMode)
// Allocate 104B EDL via class operator new, ctor(1024), override m_vtable at offset 100.

typedef unsigned int size_t;

enum RCMode {};

class EDLData {
protected:
    char pad[100];
};

class EDL : public EDLData {
public:
    static void* operator new(size_t sz);
    void* m_vtable;
    EDL(int size);
};

extern char s_EDL_custom_vt[];   // at 0x8047C4D0

inline void* operator new(size_t, void* p) { return p; }

class ENgcGraphics {
public:
    EDL* AllocDL(RCMode mode);
};

EDL* ENgcGraphics::AllocDL(RCMode) {
    EDL* dl = (EDL*)EDL::operator new(sizeof(EDL));
    ::new((void*)dl) EDL(1024);
    dl->m_vtable = s_EDL_custom_vt;
    return dl;
}
