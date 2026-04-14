// 0x8012C7DC cXPersonImpl::SetIdleLoopCount (8B)

struct cXPerson_SILC {
    char pad[0x540];
    short m_val;
    void SetIdleLoopCount(short v);
};

void cXPerson_SILC::SetIdleLoopCount(short v) {
    m_val = v;
}
