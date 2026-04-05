// FLAGS: -fno-elide-constructors
void *WPB_GetItem(void *, int, int);

struct VtSlot_SetItemPos { char pad[0x38]; short m_delta; char _p[2]; void (*m_fn)(void *, void *); };
struct ItemSub_SetItemPos { char pad[0x1C]; VtSlot_SetItemPos *m_vt; };

struct WPB_SetItemPos {
    void SetItemPos(int type, int idx, void *vec);
};

void WPB_SetItemPos::SetItemPos(int type, int idx, void *vec) {
    ItemSub_SetItemPos *item = (ItemSub_SetItemPos *)WPB_GetItem(this, type, idx);
    VtSlot_SetItemPos *vt = item->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, void *) = vt->m_fn;
    fn((char *)item + delta, vec);
}
