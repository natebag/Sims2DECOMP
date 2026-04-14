// 0x80069114 SAnimator2::GetPlayerControl (24B)
struct SAnimator2 {
    char pad[0x61C];
    int m_flags;
};
int SAnimator2_GetPlayerControl(SAnimator2* self) {
    int result = 0;
    if (self->m_flags & 1) {
        result = 1;
    }
    return result;
}
