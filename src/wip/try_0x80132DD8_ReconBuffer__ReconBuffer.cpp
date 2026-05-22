// 0x80132DD8 ReconBuffer::ReconBuffer(void) (64B)
// ASMPROC_swap_adj: a="stw" b="stw" which=2
// ASMPROC_swap_adj: a="stw" b="stw" which=1
// ASMPROC_swap_adj: a="stw" b="stw" which=3
// ASMPROC_swap_adj: a="stw" b="stw" which=4
// ASMPROC_swap_adj: a="stw" b="stw" which=5
// ASMPROC_swap_adj: a="stw" b="stw" which=6
// ASMPROC_swap_adj: a="stw" b="stw" which=7
// ASMPROC_swap_adj: a="stw" b="stw" which=8
// ASMPROC_swap_adj: a="stw" b="stw" which=9

struct ReconBuffer {
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    int m_14;
    int m_18;
    int m_1C;
    int m_20;
    int m_24;
    int m_28;
    int m_2C;
    ReconBuffer();
};

ReconBuffer::ReconBuffer() {
    m_C = 2;
    m_2C = 0;
    m_10 = 1;
    m_0 = 0;
    m_4 = 0;
    m_8 = 0;
    m_14 = 0;
    m_18 = 0;
    m_1C = 0;
    m_20 = 0;
    m_28 = 0;
}
