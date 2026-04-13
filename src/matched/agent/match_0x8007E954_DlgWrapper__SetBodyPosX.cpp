// 0x8007E954 DlgWrapper::SetBodyPosX(float) (60B)
struct InnerVT2 { char pad[0x1C]; void* m_vt2; };
struct InnerVT { char pad[0x48]; short adj; short p; void (*fn)(void*, float); };
struct Inner { char pad[0x64]; InnerVT2* m_vt; };
struct DlgWrapper { char pad[0xAC]; Inner* m_inner; void SetBodyPosX(float x); };
void DlgWrapper::SetBodyPosX(float x) {
    Inner* inner = m_inner;
    InnerVT2* vt2 = inner->m_vt;
    InnerVT* vt = (InnerVT*)vt2->m_vt2;
    short adj = vt->adj;
    void (*fn)(void*, float) = vt->fn;
    fn((char*)vt2 + adj, x);
}
