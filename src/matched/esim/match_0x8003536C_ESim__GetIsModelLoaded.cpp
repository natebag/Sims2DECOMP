// 0x8003536C ESim::GetIsModelLoaded (8B)

struct ESim_GetIsModelLoaded {
    char pad[0x638];
    int m_val;
    int GetIsModelLoaded();
};

int ESim_GetIsModelLoaded::GetIsModelLoaded() {
    return m_val;
}
