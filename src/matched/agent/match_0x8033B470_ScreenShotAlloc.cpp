/* ScreenShotAlloc at 0x8033B470 (64 bytes) */

typedef unsigned int u32;

u32 EAHeapGetSize(u32 ptr);
void* EAHeapAlloc(u32 size, u32 ptr, u32 align, u32 flags1, u32 flags2);

void* ScreenShotAlloc(u32 ptr)
{
    u32 size = EAHeapGetSize(ptr);
    return EAHeapAlloc(size, ptr, 32, 0, 0);
}
