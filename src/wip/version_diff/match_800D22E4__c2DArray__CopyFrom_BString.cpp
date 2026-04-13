/* _c2DArray::CopyFrom(BString &) - 60 bytes */

struct BString { int m_data; };

struct _c2DArray {
    void CopyFrom(BString &bstr);
    void CopyFrom(_c2DArray *src);
    static _c2DArray *GetArray(BString &bstr);
};

void _c2DArray::CopyFrom(BString &bstr) {
    _c2DArray *src = GetArray(bstr);
    CopyFrom(src);
}
