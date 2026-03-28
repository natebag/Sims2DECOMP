/* cXObjectImpl::TagGraphicsField(void) - 12 bytes */

class cXObjectImpl {
public:
    char pad[0xE8];
    int m_graphicsFieldTag;

    void TagGraphicsField(void);
};

void cXObjectImpl::TagGraphicsField(void) {
    m_graphicsFieldTag = 1;
}
