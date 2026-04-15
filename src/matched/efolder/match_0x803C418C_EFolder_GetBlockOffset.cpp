// 0x803C418C EFolder::GetBlockOffset(int) const (20B)

struct EFolder {
    int* m_base;
    int GetBlockOffset(int idx) const;
};

int EFolder::GetBlockOffset(int idx) const {
    return m_base[idx + 1];
}
