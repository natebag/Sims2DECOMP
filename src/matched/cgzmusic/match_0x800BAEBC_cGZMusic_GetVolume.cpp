// 0x800BAEBC cGZMusic::GetVolume (8B) — lwz r3, 20(r3)
struct cGZMusic {
    char pad[20];
    int m_volume;
    int GetVolume();
};
int cGZMusic::GetVolume() { return m_volume; }
