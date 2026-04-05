// FLAGS: -fno-elide-constructors
void *WPB_GetItem(void *, int, int);

struct VtSlot_SetItemSizeY { char pad[0x88]; short m_delta; char _p[2]; void (*m_fn)(void *, float); };
struct ItemSub_SetItemSizeY { char pad[0x1C]; VtSlot_SetItemSizeY *m_vt; };

struct WPB_SetItemSizeY {
    void SetItemSizeY(int type, int idx, float val);
};

void WPB_SetItemSizeY::SetItemSizeY(int type, int idx, float val) {
    ItemSub_SetItemSizeY *item = (ItemSub_SetItemSizeY *)WPB_GetItem(this, type, idx);
    VtSlot_SetItemSizeY *vt = item->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, float) = vt->m_fn;
    fn((char *)item + delta, val);
}
