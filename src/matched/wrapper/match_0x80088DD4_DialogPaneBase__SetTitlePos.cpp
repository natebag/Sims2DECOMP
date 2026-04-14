/* DialogPaneBase::SetTitlePos(EVec2) at 0x80088DD4 (56B) */

struct TPosVt { char pad[0x38]; short m_off; int (*m_fn)(void *, int); };
struct TPosMid { char pad[0x1C]; TPosVt *m_vt; };
struct DialogPaneBase_STP { char pad[0x60]; TPosMid *m_title; void SetTitlePos(int pos); };

void DialogPaneBase_STP::SetTitlePos(int pos) {
    TPosMid *mid = m_title;
    TPosVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, int) = vt->m_fn;
    fn((char *)mid + off, pos);
}
