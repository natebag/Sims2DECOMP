/* DialogPaneBase::SetTitlePosY(float) at 0x80088E44 (56B) */

struct TPosYVt { char pad[0x58]; short m_off; int (*m_fn)(void *, float); };
struct TPosYMid { char pad[0x1C]; TPosYVt *m_vt; };
struct DialogPaneBase_STPY { char pad[0x60]; TPosYMid *m_title; void SetTitlePosY(float y); };

void DialogPaneBase_STPY::SetTitlePosY(float y) {
    TPosYMid *mid = m_title;
    TPosYVt *vt = mid->m_vt;
    short off = vt->m_off;
    int (*fn)(void *, float) = vt->m_fn;
    fn((char *)mid + off, y);
}
