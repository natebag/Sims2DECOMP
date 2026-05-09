// 0x800D1C38 (60B) _c2DArray::RemoveArray(_c2DArray*)
// Linked-list unlink rooted at SDA global. m_next at offset 0 (first member).

class _c2DArray {
public:
    _c2DArray* m_next;          // +0
    static void RemoveArray(_c2DArray* p);
};

extern _c2DArray* g_2dArrayHead;   // SDA -31952(r13)

void _c2DArray::RemoveArray(_c2DArray* p)
{
    _c2DArray** pp = &g_2dArrayHead;
    if (*pp == 0) return;
    do {
        _c2DArray* cur = *pp;
        if (cur == p) {
            *pp = cur->m_next;
            return;
        }
        pp = &cur->m_next;
    } while (*pp != 0);
}
