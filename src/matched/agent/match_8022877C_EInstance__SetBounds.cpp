struct EVec3 {
    float x, y, z;
};

struct EBound3 {
    EVec3 min;
    EVec3 max;
};

extern void SetBoundsOnModel(void *model, void *inst, EBound3 *bounds);

struct EInstance {
    void *m_vtable;
    void *m_model;
    char pad[0x34];
    EVec3 m_boundsMin;
    EVec3 m_boundsMax;

    void SetBounds(EBound3 &bounds);
};

void EInstance::SetBounds(EBound3 &bounds) {
    if (m_model != 0) {
        SetBoundsOnModel(m_model, this, &bounds);
    } else {
        m_boundsMin = bounds.min;
        m_boundsMax = bounds.max;
    }
}
