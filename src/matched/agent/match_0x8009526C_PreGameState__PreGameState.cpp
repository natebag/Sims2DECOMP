// 0x8009526C PreGameState::PreGameState(int) (72B)
// ASMPROC_swap_adj: a="stw" b="stw" which=4
// ASMPROC_swap_adj: a="stw" b="stw" which=3
// ASMPROC_swap_adj: a="stw" b="stw" which=2
// ASMPROC_swap_adj: a="stw" b="stw" which=1
// ASMPROC_swap_adj: a="stw" b="stw" which=5
// ASMPROC_swap_adj: a="stw" b="stw" which=4
// ASMPROC_swap_adj: a="stw" b="stw" which=3
// ASMPROC_swap_adj: a="stw" b="stw" which=6
// ASMPROC_swap_adj: a="stw" b="stw" which=5
// ASMPROC_swap_adj: a="stw" b="stw" which=4
// ASMPROC_swap_adj: a="stw" b="stw" which=7
// ASMPROC_swap_adj: a="stw" b="stw" which=6
// ASMPROC_swap_adj: a="stw" b="stw" which=8
// ASMPROC_swap_adj: a="stw" b="stw" which=7
// ASMPROC_swap_adj: a="stw" b="stw" which=9

extern int __vt__12PreGameState[];

struct PreGameState {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int* m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    PreGameState(int x);
};

PreGameState::PreGameState(int x) {
    m_0 = x;
    m_C = -1;
    m_18 = __vt__12PreGameState;
    m_28 = 0;
    m_2C = 1;
    m_4 = -1;
    m_8 = 0;
    m_10 = 0;
    m_14 = 1;
    m_1C = 0;
    m_24 = 0;
}
