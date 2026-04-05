// FLAGS: -fno-elide-constructors
void *WPB_GetItem(void *, int, int);

struct VtSlotX { char pad[0x48]; short m_delta; char _p[2]; void (*m_fn)(void *, float); };
struct ItemSub { char pad[0x1C]; VtSlotX *m_vt; };

struct WPB_SIPX {
    void SetItemPosX(int type, int idx, float val);
};

void WPB_SIPX::SetItemPosX(int type, int idx, float val) {
    ItemSub *item = (ItemSub *)WPB_GetItem(this, type, idx);
    VtSlotX *vt = item->m_vt;
    short delta = vt->m_delta;
    void (*fn)(void *, float) = vt->m_fn;
    fn((char *)item + delta, val);
}
