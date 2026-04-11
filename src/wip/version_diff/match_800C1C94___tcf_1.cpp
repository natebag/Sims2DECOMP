/* __tcf_1 - 40 bytes */

struct CTilePt {
    int m_data[2];
    ~CTilePt(void);
};

static CTilePt s_tilePt;

void __tcf_1(void) {
    s_tilePt.~CTilePt();
}
