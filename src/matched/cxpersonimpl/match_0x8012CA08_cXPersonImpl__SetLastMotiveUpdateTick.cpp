// 0x8012CA08 cXPersonImpl::SetLastMotiveUpdateTick (8B)

struct cXPerson_SetLastMotiveUpdateTick {
    char pad[0x538];
    int m_val;
    void SetLastMotiveUpdateTick(int v);
};

void cXPerson_SetLastMotiveUpdateTick::SetLastMotiveUpdateTick(int v) {
    m_val = v;
}
