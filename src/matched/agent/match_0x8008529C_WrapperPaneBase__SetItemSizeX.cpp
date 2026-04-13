// 0x8008529C WrapperPaneBase::SetItemSizeX(ItemType, int, float) (72B)
// FLAGS: -fno-schedule-insns
struct WrapperItem; void* WrapperPaneBase_GetItem(void* self, int type, int index);
struct VT { char pad[0x78]; short adj; short p; void (*fn)(void*, float); };
struct WI { char pad[0x1C]; VT* vt; };
struct WrapperPaneBase { void SetItemSizeX(int type, int index, float val); };
void WrapperPaneBase::SetItemSizeX(int type, int index, float val) {
    WI* item = (WI*)WrapperPaneBase_GetItem(this, type, index);
    VT* vt = item->vt;
    short adj = vt->adj;
    void (*fn)(void*, float) = vt->fn;
    fn((char*)item + adj, val);
}
