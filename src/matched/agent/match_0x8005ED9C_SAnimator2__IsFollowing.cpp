/* SAnimator2::IsFollowing(void) at 0x8005ED9C (24B) */

struct SAnimator2 {
    char pad[0x10];
    int m_isFollowing;

    int IsFollowing(void);
};

int SAnimator2::IsFollowing(void) {
    if (m_isFollowing != 0) return 1;
    return 0;
}
