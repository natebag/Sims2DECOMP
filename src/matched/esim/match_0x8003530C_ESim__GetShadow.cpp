// 0x8003530C ESim::GetShadow (8B)

struct ESim_GetShadow {
    char pad[0x3E0];
    int m_val;
    int GetShadow();
};

int ESim_GetShadow::GetShadow() {
    return m_val;
}
