/* cXObjectImpl::IsContained(void) - 60 bytes */

struct cXObjectImpl;

struct PlacementSpec {
    int m_type;
    int m_tileX;
    int m_tileY;
    cXObjectImpl *m_objImpl;
    int m_slot;
    int m_level;

    PlacementSpec(cXObjectImpl *obj);
};

struct cXObjectImpl {
    int IsContained(void);
};

int cXObjectImpl::IsContained(void) {
    PlacementSpec spec(this);
    return spec.m_objImpl != 0;
}
