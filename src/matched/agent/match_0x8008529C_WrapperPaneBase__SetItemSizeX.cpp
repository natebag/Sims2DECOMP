// FLAGS: -fno-elide-constructors
void *WPB_GetItem(void *, int, int);

struct VtSlot_SetItemSizeX { char pad[0x78]; short m_delta; char _p[2]; void (*m_fn)(void *, float); };
struct ItemSub_SetItemSizeX { char pad[0x1C]; VtSlot_SetItemSizeX *m_vt; };

struct WPB_SetItemSizeX {
    void SetItemSizeX(int type, int idx, float val);
};

void WPB_SetItemSizeX::SetItemSizeX(int type, int idx, float val) {
    ItemSub_SetItemSizeX *item = (ItemSub_SetItemSizeX *)WPB_GetItem(this, type, idx);
    VtSlot_SetItemSizeX *vt = item->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, float) = vt->m_fn;
    fn((char *)item + delta, val);
}
