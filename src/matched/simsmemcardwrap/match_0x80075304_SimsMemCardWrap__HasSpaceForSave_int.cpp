// 0x80075304 SimsMemCardWrap::HasSpaceForSave(int, bool &, unsigned int *) (144 B)

struct ENgcMemoryCardVtable { char pad[0x80]; short off; };
struct ENgcMemoryCard { ENgcMemoryCardVtable* vtable; void IsEnoughFiles(int slot, int one, void* result); };
extern ENgcMemoryCard* g_memCard;
extern int SimsMemCardWrap_GetSpaceRequiredForSave();

typedef int (*HasSpaceFn)(void*, int, int, void*);

void SimsMemCardWrap_HasSpaceForSave(int slot, int* result, unsigned int* out) {
    if (out != 0) {
        *out = 0;
    }
    g_memCard->IsEnoughFiles(slot, 1, result);
    if (*result != 0) {
        ENgcMemoryCard* card = g_memCard;
        ENgcMemoryCardVtable* vt = card->vtable;
        short off = vt->off;
        char* vt2 = (char*)vt + 128;
        void* self = (char*)card + off;
        int space = SimsMemCardWrap_GetSpaceRequiredForSave();
        HasSpaceFn fn = *(HasSpaceFn*)(vt2 + 4);
        fn(self, slot, space, result);
    }
}
