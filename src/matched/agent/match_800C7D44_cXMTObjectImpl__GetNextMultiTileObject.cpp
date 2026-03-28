/* cXMTObjectImpl::GetNextMultiTileObject(void) - 0x800C7D44 (24 bytes) */

struct cXObject;

struct cXMTObjectImplNode {
    int m_pad0;
    cXObject *m_object;
};

struct cXMTObjectImpl {
    int m_pad0;
    int m_pad4;
    cXMTObjectImplNode *m_next;

    cXObject *GetNextMultiTileObject(void);
};

cXObject *cXMTObjectImpl::GetNextMultiTileObject(void) {
    cXMTObjectImplNode *n = m_next;
    cXObject *result = 0;
    if (n != 0) {
        result = n->m_object;
    }
    return result;
}
