/* _c2DArray::AddArray(_c2DArray *) - 16 bytes */

struct _c2DArray;

static _c2DArray *s_arrayListHead;

struct _c2DArray {
    _c2DArray *m_next;

    static void AddArray(_c2DArray *arr);
};

void _c2DArray::AddArray(_c2DArray *arr) {
    arr->m_next = s_arrayListHead;
    s_arrayListHead = arr;
}
