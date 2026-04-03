// 0x8001EA6C (8 bytes) — addi r3, r3, 0x10; blr

class ESimsCam {
public:
    char _pad[0x10];
    int m_win;

    void* GetWin();
};

void* ESimsCam::GetWin() {
    return &m_win;
}
