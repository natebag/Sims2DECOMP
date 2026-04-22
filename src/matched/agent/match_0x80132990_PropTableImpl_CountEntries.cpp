// 0x80132990 PropTableImpl::CountEntries(void) const (28B)
//
// DOL emits:
//   lwz r9, 4(r3)      ; r9 = this->m_data (offset 4, behind the vtable)
//   li r3, 0            ; tentative return 0 (scheduled early)
//   lwz r9, 0(r9)       ; r9 = *m_data — TArray-style data pointer
//   cmpwi r9, 0         ; if null, the array is empty
//   beqlr
//   lwz r3, -4(r9)      ; return count stored at data[-1] (TArray header)
//   blr
//
// Source pattern: PropTableImpl holds a TArray-like nested container.
// m_data is a TArray<PropEntry>* whose data pointer is the first field;
// element count is stored at ((int*)data_ptr)[-1].

struct PropTableArray {
    int* m_data;        // pointer to first element; count at m_data[-1]
};

struct PropTableImpl {
    void* vtable;
    PropTableArray* m_array;
    int CountEntries() const;
};

int PropTableImpl::CountEntries() const {
    PropTableArray* arr = m_array;
    int result = 0;
    int* data = arr->m_data;
    if (data != 0) result = data[-1];
    return result;
}
