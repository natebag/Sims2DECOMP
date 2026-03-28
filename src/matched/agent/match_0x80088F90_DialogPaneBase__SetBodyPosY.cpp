/* DialogPaneBase::SetBodyPosY(float) at 0x80088F90 (56B) */

struct BPosYVt { char pad[0x58]; short m_off; int (*m_fn)(void *, float); };
struct BPosYMid { char pad[0x1C]; BPosYVt *m_vt; };
struct DialogPaneBase_SBPY { char pad[0x64]; BPosYMid *m_body; void SetBodyPosY(float y); };

void DialogPaneBase_SBPY::SetBodyPosY(float y) {
    BPosYMid *mid = m_body;
    BPosYVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, float) = vt->m_fn;
    fn((char *)mid + off, y);
}
