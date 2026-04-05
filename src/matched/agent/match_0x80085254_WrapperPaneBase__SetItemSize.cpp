// FLAGS: -fno-elide-constructors
void *WPB_GetItem(void *, int, int);

struct VtSlot_SetItemSize { char pad[0x68]; short m_delta; char _p[2]; void (*m_fn)(void *, void *); };
struct ItemSub_SetItemSize { char pad[0x1C]; VtSlot_SetItemSize *m_vt; };

struct WPB_SetItemSize {
    void SetItemSize(int type, int idx, void *vec);
};

void WPB_SetItemSize::SetItemSize(int type, int idx, void *vec) {
    ItemSub_SetItemSize *item = (ItemSub_SetItemSize *)WPB_GetItem(this, type, idx);
    VtSlot_SetItemSize *vt = item->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, void *) = vt->m_fn;
    fn((char *)item + delta, vec);
}
