// 0x800BA668 cGZSnd::GetVolume (8B) — lwz r3, 32(r3)
struct cGZSnd {
    char pad[32];
    int m_volume;
    int GetVolume();
};
int cGZSnd::GetVolume() { return m_volume; }
