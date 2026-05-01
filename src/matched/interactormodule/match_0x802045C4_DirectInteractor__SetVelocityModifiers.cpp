// 0x802045C4 InteractorModule::DirectInteractor::SetVelocityModifiers(void) (92B)

namespace InteractorModule {

struct SVMVt {
    char pad[0x188];
    short m_off;            // 0x188
    char _p[2];
    void* (*m_fn)(void*);   // 0x18C
};

struct SVMInner {
    char pad[0x4];
    SVMVt* m_vt;            // 0x4
};

struct SVMResult {
    char pad[0xB8];
    float m_field_b8;       // 0xB8
};

extern float GetSomeFloat(void* arg);

class DirectInteractor {
public:
    char pad[0x4];
    void* m_arg;            // 0x04
    char pad2[0x70 - 0x8];
    SVMInner* m_inner;      // 0x70

    void SetVelocityModifiers();
};

void DirectInteractor::SetVelocityModifiers() {
    SVMInner* o = m_inner;
    if (o == 0) return;
    SVMVt* vt = o->m_vt;
    short off = vt->m_off;
    void* (*fn)(void*) = vt->m_fn;
    SVMResult* r = (SVMResult*)fn((char*)o + off);
    float v = GetSomeFloat(m_arg);
    r->m_field_b8 = v;
}

}
