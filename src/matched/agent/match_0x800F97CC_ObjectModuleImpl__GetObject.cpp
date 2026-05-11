// 0x800F97CC ObjectModuleImpl::GetObject (84B)
// T1 reattempt — drop `register` hint + lwzx swap_operands canonicalization defeat
// ASMPROC_swap_operands: match="lwzx 3,9,11" pos=1,2

struct ArrayElem {
    void* field_0;
    void* field_4;
};

class ObjectModuleImpl {
    char pad[0x2090];
    void** m_objectArrayBegin;
    char pad2[0xC];
    ArrayElem* m_fixedObjects[16];
public:
    ArrayElem* GetObject(int index);
};

ArrayElem* ObjectModuleImpl::GetObject(int index) {
    int tmp = index - 0x4000;
    if ((unsigned int)tmp <= 15) {
        ArrayElem* ptr = m_fixedObjects[tmp];
        ArrayElem* result = 0;
        if (ptr != 0) {
            result = (ArrayElem*)ptr->field_4;
        }
        return result;
    }
    ArrayElem* ptr = ((ArrayElem**)m_objectArrayBegin)[index];
    ArrayElem* result = 0;
    if (ptr != 0) {
        result = (ArrayElem*)ptr->field_4;
    }
    return result;
}
