typedef unsigned char u8;

void addToList(u8*, int);

void ERC_AddDisplayListReference(u8* self, u8* edl) {
    u8* inner = *(u8**)self;
    addToList(inner + 0x3C, (int)edl);
    u8* inner2 = *(u8**)self;
    addToList(inner2 + 0x30, 0);
}
