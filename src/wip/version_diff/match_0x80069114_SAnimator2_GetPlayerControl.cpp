// 0x80069114 SAnimator2::GetPlayerControl (24b)

struct SAnimator2 {
    int m_flags;
    bool GetPlayerControl();
};

bool SAnimator2::GetPlayerControl() {
    return (m_flags & 0x0001) != 0;
}
