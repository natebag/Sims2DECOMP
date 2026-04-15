/* _c2DArray::AddArray(_c2DArray *) - 0x800D1C28 (16 bytes) */

extern class _c2DArray* g__c2DArrayHead;

class _c2DArray {
public:
    _c2DArray* m_next;  // +0

    static void AddArray(_c2DArray* self);
};

void _c2DArray::AddArray(_c2DArray* self) {
    self->m_next = g__c2DArrayHead;
    g__c2DArrayHead = self;
}
