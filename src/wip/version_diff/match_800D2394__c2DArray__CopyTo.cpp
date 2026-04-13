/* _c2DArray::CopyTo(_c2DArray *) - 44 bytes */

struct _c2DArray {
    void CopyTo(_c2DArray *dest);
    void CopyFrom(_c2DArray *src);
};

void _c2DArray::CopyTo(_c2DArray *dest) {
    dest->CopyFrom(this);
}
