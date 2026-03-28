// 0x8001EA9C (8 bytes) — lwz r3, 0x3CC(r3); blr

class ESimsCam {
public:
    char _pad[0x3CC];
    int m_mode;

    int GetMode() const;
};

int ESimsCam::GetMode() const {
    return m_mode;
}
