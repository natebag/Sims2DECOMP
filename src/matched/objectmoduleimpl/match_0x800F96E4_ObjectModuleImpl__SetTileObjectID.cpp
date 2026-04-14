// 0x800F96E4 ObjectModuleImpl::SetTileObjectID (104B)

struct CTilePt;
extern int tileConv15(CTilePt*);
extern int tileConv16(CTilePt*);

struct ObjectModuleImpl {
    char pad[0x34];
    short m_tileObjectIDs[64][64];
};

void ObjectModuleImpl_SetTileObjectID(ObjectModuleImpl* self, CTilePt& tile, short id) {
    int x = tileConv15(&tile);
    int y = tileConv16(&tile);
    if ((unsigned int)x > 63 || (unsigned int)y > 63) return;
    self->m_tileObjectIDs[y][x] = id;
}
