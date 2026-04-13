// 0x800EB378 cXObjectImpl::IsMultiTile (28B)

struct ObjData {
    char pad[0x14];
    short m_multiTile;
};

struct cXObjMT {
    char pad[0x88];
    ObjData* m_data;
    int IsMultiTile();
};

int cXObjMT::IsMultiTile() {
    int r = 1;
    if (m_data->m_multiTile == 0) r = 0;
    return r;
}
