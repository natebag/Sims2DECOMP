/* _c2DArray::ClearBytes(signed char) - 0x800D1E78 (76 bytes) */

extern "C" void *memset(void *, int, unsigned int);

struct _c2DArrayData {
    void *m_data;
};

struct _c2DArray {
    void **_vtable;
    int m_ySize;
    int m_xSize;
    _c2DArrayData *m_arrays;
    int _pad_010;
    int m_elemSize;

    void ClearBytes(signed char val);
};

void _c2DArray::ClearBytes(signed char val)
{
    if (m_xSize <= 0) return;
    if (m_ySize <= 0) return;
    memset(m_arrays->m_data, val, m_xSize * m_ySize * m_elemSize);
}
