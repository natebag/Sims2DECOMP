/* cXObject::setPortalImpl(cXPortalImpl *) - 12 bytes */

struct cXObjectData {
    void* m_objectImpl;
    void* m_personImpl;
    void* m_mtObjectImpl;
    void* m_portalImpl;
};

class cXObject {
public:
    cXObjectData* m_data;

    void setPortalImpl(void* impl);
};

void cXObject::setPortalImpl(void* impl) {
    m_data->m_portalImpl = impl;
}
