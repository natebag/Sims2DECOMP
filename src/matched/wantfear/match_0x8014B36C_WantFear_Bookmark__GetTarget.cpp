/* WantFear::Bookmark::GetTarget(void) const - 0x8014B36C (32 bytes) */

namespace WantFear {

struct Inner {
    char pad0[6];
    short m_short_6;
    char pad1[21];
    unsigned char m_flags;  // +29
};

class Bookmark {
public:
    short pad0;
    short m_short_2;
    Inner* m_inner;  // +4

    short GetTarget(void) const;
};

short Bookmark::GetTarget(void) const {
    Inner* p = m_inner;
    if ((p->m_flags & 2) != 0) {
        return m_short_2;
    }
    return p->m_short_6;
}

}
