// 0x8021CCC0 InteractorModule::PlacementObject::SetShaderToValidState(bool) (84B)

namespace InteractorModule {

struct SSVSVt {
    char pad[0x520];
    short m_off;            // 0x520
    char _p[2];
    void* (*m_fn)(void*);   // 0x524
};

struct SSVSInner {
    char pad[0x4];
    SSVSVt* m_vt;           // 0x4
};

extern void SetShaderState(void* obj, bool flag);

class PlacementObject {
public:
    SSVSInner* m_inner;     // 0x00
    void SetShaderToValidState(bool b);
};

void PlacementObject::SetShaderToValidState(bool b) {
    SSVSInner* o = m_inner;
    if (o == 0) return;
    SSVSVt* vt = o->m_vt;
    short off = vt->m_off;
    void* (*fn)(void*) = vt->m_fn;
    void* r = fn((char*)o + off);
    SetShaderState(r, b);
}

}
