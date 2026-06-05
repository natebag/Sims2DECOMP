// 0x80234A70 ERLevel::DrawOrderTableSlot(EOrderTableData *) (116 B)

struct EOrderTableData { char pad[0x28]; EOrderTableData* next; };
struct ERCVtable { char pad[0x258]; short off; void (*fn)(void*, float); };
struct ERC { char pad[0x70]; ERCVtable* vtable; };
extern char lbl_803FF4FC[];
struct ERLevel {
    void DrawOrderTableEntry(EOrderTableData* data, ERC* rc);
    void DrawOrderTableSlot(EOrderTableData* data);
};

void ERLevel::DrawOrderTableSlot(EOrderTableData* data) {
    ERLevel* level = this;
    ERC* localRc = *(ERC**)((char*)level + 0x2A238);
    if (data != 0) {
        do {
            EOrderTableData* next = data->next;
            level->DrawOrderTableEntry(data, localRc);
            data = next;
        } while (data != 0);
    }
    ERCVtable* vt = localRc->vtable;
    float f = *(float*)lbl_803FF4FC;
    void* self = (char*)localRc + vt->off;
    vt->fn(self, f);
}
