/* _c2DArray::CopyTo(BString &) - 60 bytes */

struct BString { int m_data; };

struct _c2DArray {
    void CopyTo(BString &bstr);
    void CopyTo(_c2DArray *dest);
    static _c2DArray *GetArray(BString &bstr);
};

void _c2DArray::CopyTo(BString &bstr) {
    _c2DArray *dest = GetArray(bstr);
    CopyTo(dest);
}
