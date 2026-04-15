// 0x800DD408 cXObjectImpl::IsContained (60B)
// Construct PlacementSpec from this on stack, check field@12 != 0

struct cXObjectImpl;

struct PlacementSpec {
    char pad[12];
    int m_container;  // +12
    char pad2[8];     // pad to 24 bytes for stack frame alignment
    PlacementSpec(cXObjectImpl* obj);
};

struct cXObjectImpl {
    int IsContained();
};

int cXObjectImpl::IsContained() {
    PlacementSpec p(this);
    return p.m_container != 0;
}
