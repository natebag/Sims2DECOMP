// 0x8012CA00 cXPersonImpl::GetLastMotiveUpdateTick (8B)

struct cXPerson_GetLastMotiveUpdateTick {
    char pad[0x538];
    int m_val;
    int GetLastMotiveUpdateTick();
};

int cXPerson_GetLastMotiveUpdateTick::GetLastMotiveUpdateTick() {
    return m_val;
}
