// 0x80035330 ESim::GetSimHead (8B)

struct ESim_GetSimHead {
    char pad[0x628];
    int m_val;
    int GetSimHead();
};

int ESim_GetSimHead::GetSimHead() {
    return m_val;
}
