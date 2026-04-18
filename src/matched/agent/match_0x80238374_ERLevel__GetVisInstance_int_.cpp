// 0x80238374 (20B) ERLevel::GetVisInstance(int)

struct ERLevel_GVI {
    char pad[0x2C2CC];
    int m_array[1];
    int GetVisInstance(int idx);
};

int ERLevel_GVI::GetVisInstance(int idx) {
    return m_array[idx];
}
