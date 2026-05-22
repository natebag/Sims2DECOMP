// 0x800A76FC (92 bytes)
// QuickStringSet::GetLocString(int idx) const
// Testing with default flags (includes -fno-elide-constructors) + explicit ctors
// to see register allocation WITHOUT scheduling disabled

typedef unsigned short wchar_t;

struct WStrRef {
    wchar_t* ptr;
    WStrRef() {}
    WStrRef(const WStrRef& o) : ptr(o.ptr) {}
};

struct QuickBuf {
    WStrRef* m_data;
};

struct QuickStringSet {
    int _vtable;
    QuickBuf* m_field_04;
    int m_field_08;
    wchar_t* m_pDB;
    int m_field_10;

    WStrRef GetLocString(int idx) const;
};

WStrRef QuickStringSet::GetLocString(int idx) const {
    WStrRef result;
    QuickBuf* buf = m_field_04;
    if (buf == 0) {
        result.ptr = m_pDB;
        return result;
    }
    if (idx <= 0) {
        result.ptr = m_pDB;
        return result;
    }
    WStrRef* data = buf->m_data;
    int count = 0;
    if (data != 0) count = ((int*)data)[-1];
    if (idx > count) {
        result.ptr = m_pDB;
        return result;
    }
    result = data[idx - 1];
    return result;
}
