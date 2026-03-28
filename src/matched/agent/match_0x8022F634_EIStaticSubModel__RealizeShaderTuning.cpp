/* EIStaticSubModel::RealizeShaderTuning(void) at 0x8022F634 (52B) */

struct Vt_EIStaticSubModel_RealizeShaderTuning { char pad[0xA0]; short m_off; int (*m_fn)(void *); };
struct S_EIStaticSubModel_RealizeShaderTuning { Vt_EIStaticSubModel_RealizeShaderTuning *m_vt; void func(); };

void S_EIStaticSubModel_RealizeShaderTuning::func() {
    Vt_EIStaticSubModel_RealizeShaderTuning *vt = m_vt;
    short off = vt->m_off;
        vt->m_fn((char *)this + off);
}
