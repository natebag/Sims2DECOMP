/* DialogPaneBase::SetBodyPosX(float) at 0x80088F58 (56B) */

struct BPosXVt { char pad[0x48]; short m_off; int (*m_fn)(void *, float); };
struct BPosXMid { char pad[0x1C]; BPosXVt *m_vt; };
struct DialogPaneBase_SBPX { char pad[0x64]; BPosXMid *m_body; void SetBodyPosX(float x); };

void DialogPaneBase_SBPX::SetBodyPosX(float x) {
    BPosXMid *mid = m_body;
    BPosXVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, float) = vt->m_fn;
    fn((char *)mid + off, x);
}
