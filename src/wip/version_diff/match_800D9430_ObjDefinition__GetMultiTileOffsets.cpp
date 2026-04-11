/* ObjDefinition::GetMultiTileOffsets(int *, int *) const - 24 bytes */

struct ObjDefinition {
    char m_pad[0x16];
    short m_multiTileOffset;

    void GetMultiTileOffsets(int *x, int *y) const;
};

void ObjDefinition::GetMultiTileOffsets(int *x, int *y) const {
    *x = m_multiTileOffset >> 8;
    *y = m_multiTileOffset & 0xFF;
}
