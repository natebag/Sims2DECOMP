// 0x800d9430 ObjDefinition::GetMultiTileOffsets(int *, int *) const (24B)

struct ObjDefinition {
    char pad[0x16];
    short m_field16;
    void GetMultiTileOffsets(int* outX, int* outY) const;
};

void ObjDefinition::GetMultiTileOffsets(int* outX, int* outY) const {
    *outX = m_field16 >> 8;
    *outY = *(unsigned char*)((char*)this + 0x17);
}
