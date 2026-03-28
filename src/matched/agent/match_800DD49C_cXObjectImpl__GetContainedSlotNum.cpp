/* cXObjectImpl::GetContainedSlotNum(void) - 44 bytes */

struct cXObjectImpl;

struct PlacementSpec {
    int m_type;
    int m_tileX;
    int m_tileY;
    cXObjectImpl *m_objImpl;
    short m_slotHi;
    short m_slot;
    int m_level;

    PlacementSpec(cXObjectImpl *obj);
};

struct cXObjectImpl {
    short GetContainedSlotNum(void);
};

short cXObjectImpl::GetContainedSlotNum(void) {
    PlacementSpec spec(this);
    return spec.m_slot;
}
