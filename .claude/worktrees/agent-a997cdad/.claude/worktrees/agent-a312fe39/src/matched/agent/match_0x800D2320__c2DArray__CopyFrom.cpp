/* _c2DArray::CopyFrom(_c2DArray *) - 0x800D2320 (116 bytes) */

extern "C" void *memmove(void *, const void *, unsigned int);

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

    void CopyFrom(_c2DArray *src);
};

void _c2DArray::CopyFrom(_c2DArray *src)
{
    if (src == 0) return;
    if (src->m_elemSize != m_elemSize) return;
    if (m_xSize != src->m_xSize) return;
    if (m_ySize != src->m_ySize) return;
    int total = m_xSize * m_ySize * m_elemSize;
    if (total <= 0) return;
    memmove(m_arrays->m_data, src->m_arrays->m_data, total);
}
