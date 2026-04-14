// 0x800F9668 ObjectModuleImpl::GetTileObjectID (124B)

struct CTilePt;
extern int tileConv13(CTilePt*);
extern int tileConv14(CTilePt*);

struct ObjectModuleImpl {
    char pad[0x34];
    short m_tileObjectIDs[64][64];
};

short ObjectModuleImpl_GetTileObjectID(ObjectModuleImpl* self, CTilePt& tile) {
    int x = tileConv13(&tile);
    int y = tileConv14(&tile);
    if (x > 63 || y > 63 || x < 0 || y < 0) return 0;
    return self->m_tileObjectIDs[y][x];
}
