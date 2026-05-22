// Test: explicit copy ctor to work around SN ProDG bug
struct WStrRef {
    int m_ptr;
    WStrRef() {}
    WStrRef(const WStrRef& o) : m_ptr(o.m_ptr) {}
};
WStrRef getit(int x) {
    WStrRef r;
    r.m_ptr = x;
    return r;
}
