// 0x80069174 SAnimator2::IsStalled (24b)
// Pattern: SDA global load + compare

struct SAnimator2 {
    bool IsStalled();
};

bool SAnimator2::IsStalled() {
    extern char g_sda_stallFlag[4];  // SDA external forces r13-relative
    return *(int*)g_sda_stallFlag != 0;
}
