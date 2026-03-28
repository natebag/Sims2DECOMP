/* cXObject::setObjectImpl(cXObjectImpl *) - 12 bytes */

struct cXObjectData {
    void* m_objectImpl;
};

class cXObject {
public:
    cXObjectData* m_data;

    void setObjectImpl(void* impl);
};

void cXObject::setObjectImpl(void* impl) {
    m_data->m_objectImpl = impl;
}
