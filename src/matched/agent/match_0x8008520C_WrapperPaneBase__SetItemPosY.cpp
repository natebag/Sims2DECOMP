// 0x8008520C WrapperPaneBase::SetItemPosY(ItemType, int, float) (72B)
// FLAGS: -fno-schedule-insns
struct WrapperItem; void* WrapperPaneBase_GetItem(void* self, int type, int index);
struct VT { char pad[0x58]; short adj; short p; void (*fn)(void*, float); };
struct WI { char pad[0x1C]; VT* vt; };
struct WrapperPaneBase { void SetItemPosY(int type, int index, float val); };
void WrapperPaneBase::SetItemPosY(int type, int index, float val) {
    WI* item = (WI*)WrapperPaneBase_GetItem(this, type, index);
    VT* vt = item->vt;
    short adj = vt->adj;
    void (*fn)(void*, float) = vt->fn;
    fn((char*)item + adj, val);
}
