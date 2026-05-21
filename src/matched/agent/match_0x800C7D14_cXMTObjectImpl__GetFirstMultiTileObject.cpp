// 0x800C7D14 cXMTObjectImpl::GetFirstMultiTileObject() (48B)

class cXMTObject;

class cXMTObjectImpl {
public:
    int m_pad0;
    cXMTObject* m_first;
    int m_pad8;
    cXMTObjectImpl* m_root;
    cXMTObject* GetFirstMultiTileObject();
};

cXMTObject* cXMTObjectImpl::GetFirstMultiTileObject() {
    cXMTObjectImpl* r = m_root;
    if (r != 0 || this != 0) {
        return (r ? r : this)->m_first;
    }
    return 0;
}
