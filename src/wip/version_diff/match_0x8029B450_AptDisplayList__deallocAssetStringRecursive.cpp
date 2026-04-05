// VERSION_DIFF: stack frame size differs (DOL 152B vs compiled 16B)
// C++ logic is correct
// 0x8029B450 (84 bytes)
/* AptDisplayList::deallocAssetStringRecursive(void) */

// Forward declarations
extern void AptDisplayList_deallocAssetString(void* item);  /* 0x80290B58 */

struct AptDisplayList_DeallocAsset {
    void* m_vtable;
    
    void deallocAssetStringRecursive(void);
};

void AptDisplayList_DeallocAsset::deallocAssetStringRecursive(void) {
    void* vt = m_vtable;
    void* next = ((void**)vt)[0x54/4];  /* offset 0x54 */
    while (next != 0) {
        AptDisplayList_deallocAssetString(next);
        next = ((void**)next)[0x54/4];
    }
}
