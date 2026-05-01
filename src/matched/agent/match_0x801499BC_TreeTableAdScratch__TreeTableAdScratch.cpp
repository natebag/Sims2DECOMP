// 0x801499BC TreeTableAdScratch::TreeTableAdScratch(void) (44 B)

extern char vt_TreeTableAdScratch[];

class TreeTableAdScratch {
public:
    void* m_vtable;       // 0x00
    short m_field_4;      // 0x04
    short m_field_6;      // 0x06
    short m_field_8;      // 0x08
    int m_field_c;        // 0x0c
    TreeTableAdScratch(void);
};

TreeTableAdScratch::TreeTableAdScratch(void)
    : m_vtable(vt_TreeTableAdScratch)
    , m_field_4(0)
    , m_field_6(0)
    , m_field_8(0)
    , m_field_c(0)
{}
