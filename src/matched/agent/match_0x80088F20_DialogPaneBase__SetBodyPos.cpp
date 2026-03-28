/* DialogPaneBase::SetBodyPos(EVec2) at 0x80088F20 (56B) */

struct BPosVt { char pad[0x38]; short m_off; int (*m_fn)(void *, int); };
struct BPosMid { char pad[0x1C]; BPosVt *m_vt; };
struct DialogPaneBase_SBP { char pad[0x64]; BPosMid *m_body; void SetBodyPos(int pos); };

void DialogPaneBase_SBP::SetBodyPos(int pos) {
    BPosMid *mid = m_body;
    BPosVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, int) = vt->m_fn;
    fn((char *)mid + off, pos);
}
