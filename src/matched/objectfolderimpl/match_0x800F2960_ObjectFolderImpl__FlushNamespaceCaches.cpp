// FLAGS: -fno-elide-constructors
typedef unsigned char u8;

void clearCache(u8*, u8*);

void ObjectFolderImpl_FlushNamespaceCaches(u8* self) {
    u8* cache = self + 0x6C0;
    if (*(int*)(cache + 8) != 0) {
        u8* node = *(u8**)(cache + 4);
        clearCache(cache, *(u8**)(node + 4));
        u8* node2 = *(u8**)(cache + 4);
        *(u8**)(node2 + 8) = node2;
        u8* node3 = *(u8**)(cache + 4);
        *(int*)(node3 + 4) = 0;
        u8* node4 = *(u8**)(cache + 4);
        *(u8**)(node4 + 12) = node4;
        *(int*)(cache + 8) = 0;
    }
}
