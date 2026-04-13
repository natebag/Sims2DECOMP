// FLAGS: -fno-schedule-insns
// 0x800851C4 WrapperPaneBase::SetItemPosX(ItemType, int, float) (72B)

struct WrapperItem;
void* WrapperPaneBase_GetItem(void* self, int type, int index);

struct VT { char pad[0x48]; short adj; short p; void (*fn)(void*, float); };
struct WI { char pad[0x1C]; VT* vt; };

struct WrapperPaneBase {
    void SetItemPosX(int type, int index, float val);
};

void WrapperPaneBase::SetItemPosX(int type, int index, float val) {
    WI* item = (WI*)WrapperPaneBase_GetItem(this, type, index);
    VT* vt = item->vt;
    short adj = vt->adj;
    void (*fn)(void*, float) = vt->fn;
    fn((char*)item + adj, val);
}
