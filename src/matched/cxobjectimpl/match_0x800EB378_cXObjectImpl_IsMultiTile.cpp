// 0x800EB378 cXObjectImpl::IsMultiTile (28B)
// Loads field@136, checks short@20 of that for non-zero

struct cXObjectImpl {
    char pad[136];
    void* m_multiTileData;  // +136
    int IsMultiTile();
};

int cXObjectImpl::IsMultiTile() {
    short* p = (short*)m_multiTileData;
    int result = 1;
    if (p[10] != 0) return result;
    return 0;
}
