// 0x8001EA8C (8 bytes) — lwz r3, 0x8(r3); blr

class ESimsCam {
public:
    int _pad0;
    int _pad4;
    int m_bMoved;  // 0x008

    int GetbMoved() const;
};

int ESimsCam::GetbMoved() const {
    return m_bMoved;
}
