/* cXObjectImpl::IsPartOfMe(cXObject *) - 0x800DF210 (20 bytes) */

struct cXObject;

struct cXObjectImpl {
    int m_pad0;
    cXObject *m_self;

    int IsPartOfMe(cXObject *obj);
};

int cXObjectImpl::IsPartOfMe(cXObject *obj) {
    return obj == m_self;
}
