// 0x800CCD04 (80B) NeighborhoodImpl::LevelComplete(int)

struct NeighborhoodImpl_Base {
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual int GetMaxLevel() = 0;  // slot 3 → offset 24/28
};

struct NeighborhoodImpl_Impl : public NeighborhoodImpl_Base {
    char pad[128];
    short m_level;  // offset 132

    void LevelComplete(int level);
};

void NeighborhoodImpl_Impl::LevelComplete(int level) {
    if (level > GetMaxLevel()) {
        m_level = (short)level;
    }
}
