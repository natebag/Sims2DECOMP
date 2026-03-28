/* 0x80079B90 (136 bytes) - CUnlockDisplayObject::SetOrient(EMat4 &) */

struct Pair { int a, b; };

struct EMat4 {
    Pair rows[8];
};

class CUnlockDisplayObject {
public:
    char pad[0x24];
    EMat4 *m_orient;
    void SetOrient(EMat4 &orient);
};

void CUnlockDisplayObject::SetOrient(EMat4 &orient) {
    EMat4 *dst = m_orient;
    dst->rows[0] = orient.rows[0];
    dst->rows[1] = orient.rows[1];
    dst->rows[2] = orient.rows[2];
    dst->rows[3] = orient.rows[3];
    dst->rows[4] = orient.rows[4];
    dst->rows[5] = orient.rows[5];
    dst->rows[6] = orient.rows[6];
    dst->rows[7] = orient.rows[7];
}
