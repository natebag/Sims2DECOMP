/* cHitControlGroup::cHitControlGroup(int) - 0x801167B4 - 20 bytes */
/* mr r9, r3; li r0, 0x400; stw r4, 0(r9); stw r0, 4(r9); blr */

class cHitControlGroup {
public:
    int m_id;
    int m_flags;

    cHitControlGroup(int);
};

cHitControlGroup::cHitControlGroup(int id) {
    m_id = id;
    m_flags = 0x400;
}
