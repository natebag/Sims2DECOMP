// 0x8003535C ESim::GetPlumbBobState (8B)

struct ESim_GetPlumbBobState {
    char pad[0x3EC];
    int m_val;
    int GetPlumbBobState();
};

int ESim_GetPlumbBobState::GetPlumbBobState() {
    return m_val;
}
