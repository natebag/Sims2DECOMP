/* CTilePt::CTilePt(void) at 0x800B45D0 (12B) */

struct CTilePt {
    char m_x;
    char m_y;
    char m_level;

    CTilePt(void);
};

CTilePt::CTilePt(void) {
    m_level = 0;
}
