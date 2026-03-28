/* cXObject::setMTObjectImpl(cXMTObjectImpl *) - 12 bytes */

struct cXObjectData {
    void* m_objectImpl;
    void* m_personImpl;
    void* m_mtObjectImpl;
};

class cXObject {
public:
    cXObjectData* m_data;

    void setMTObjectImpl(void* impl);
};

void cXObject::setMTObjectImpl(void* impl) {
    m_data->m_mtObjectImpl = impl;
}
