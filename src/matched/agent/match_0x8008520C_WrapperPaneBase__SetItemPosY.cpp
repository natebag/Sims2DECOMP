// FLAGS: -fno-elide-constructors
void *WPB_GetItem(void *, int, int);

struct VtSlot_SetItemPosY { char pad[0x58]; short m_delta; char _p[2]; void (*m_fn)(void *, float); };
struct ItemSub_SetItemPosY { char pad[0x1C]; VtSlot_SetItemPosY *m_vt; };

struct WPB_SetItemPosY {
    void SetItemPosY(int type, int idx, float val);
};

void WPB_SetItemPosY::SetItemPosY(int type, int idx, float val) {
    ItemSub_SetItemPosY *item = (ItemSub_SetItemPosY *)WPB_GetItem(this, type, idx);
    VtSlot_SetItemPosY *vt = item->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, float) = vt->m_fn;
    fn((char *)item + delta, val);
}
