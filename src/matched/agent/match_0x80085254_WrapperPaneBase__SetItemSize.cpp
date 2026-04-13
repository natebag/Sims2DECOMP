// 0x80085254 WrapperPaneBase::SetItemSize(ItemType, int, EVec2&) (72B)
// FLAGS: -fno-schedule-insns
struct WrapperItem; void* WrapperPaneBase_GetItem(void* self, int type, int index);
struct VT { char pad[0x68]; short adj; short p; void (*fn)(void*, void*); };
struct WI { char pad[0x1C]; VT* vt; };
struct WrapperPaneBase { void SetItemSize(int type, int index, void* pos); };
void WrapperPaneBase::SetItemSize(int type, int index, void* pos) {
    WI* item = (WI*)WrapperPaneBase_GetItem(this, type, index);
    VT* vt = item->vt;
    short adj = vt->adj;
    void (*fn)(void*, void*) = vt->fn;
    fn((char*)item + adj, pos);
}
