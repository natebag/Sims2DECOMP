/* cXMTObjectImpl::GetFirstMultiTileObject() at 0x800C7D14 (48B) */

struct cXMTNode_GFMTO {
    int m_pad;
    void* m_obj;  // offset 4
};

struct cXMTObjectImpl_GFMTO {
    int m_pad;
    void* m_field_4;     // offset 4
    int m_pad2;
    cXMTNode_GFMTO* m_nodeList;  // offset 12
    void* GetFirstMultiTileObject();
};

void* cXMTObjectImpl_GFMTO::GetFirstMultiTileObject() {
    cXMTNode_GFMTO* node = m_nodeList;
    cXMTNode_GFMTO* result = node;
    if (!result) {
        result = (cXMTNode_GFMTO*)this;
        if (!result) return 0;
    }
    return result->m_obj;
}
