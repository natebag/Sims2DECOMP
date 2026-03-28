/* DialogPaneBase::SetTitlePosX(float) at 0x80088E0C (56B) */

struct TPosXVt { char pad[0x48]; short m_off; int (*m_fn)(void *, float); };
struct TPosXMid { char pad[0x1C]; TPosXVt *m_vt; };
struct DialogPaneBase_STPX { char pad[0x60]; TPosXMid *m_title; void SetTitlePosX(float x); };

void DialogPaneBase_STPX::SetTitlePosX(float x) {
    TPosXMid *mid = m_title;
    TPosXVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, float) = vt->m_fn;
    fn((char *)mid + off, x);
}
