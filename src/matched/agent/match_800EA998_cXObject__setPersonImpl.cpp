/* cXObject::setPersonImpl(cXPersonImpl *) - 12 bytes */

struct cXObjectData {
    void* m_objectImpl;
    void* m_personImpl;
};

class cXObject {
public:
    cXObjectData* m_data;

    void setPersonImpl(void* impl);
};

void cXObject::setPersonImpl(void* impl) {
    m_data->m_personImpl = impl;
}
