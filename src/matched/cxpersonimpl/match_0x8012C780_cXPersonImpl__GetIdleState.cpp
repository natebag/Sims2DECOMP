// 0x8012C780 cXPersonImpl::GetIdleState (8B)

struct cXPerson_GetIdleState {
    char pad[0x8];
    short m_val;
    short GetIdleState();
};

short cXPerson_GetIdleState::GetIdleState() {
    return m_val;
}
