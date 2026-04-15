// 0x800F9620 ObjectModuleImpl::GetObjectFromID (72B)

struct ArrayElem {
    void* field_0;
    void* field_4;
};

class ObjectModuleImpl {
    char pad[0x2090];
    ArrayElem** m_objectArrayBegin;
    ArrayElem** m_objectArrayEnd;
public:
    void* GetObjectFromID(int id);
};

void* ObjectModuleImpl::GetObjectFromID(int id) {
    int count;
    int idx;
    register void* result = 0;
    ArrayElem* ptr;
    if (id <= 0) return 0;
    count = ((int)m_objectArrayEnd - (int)m_objectArrayBegin) >> 2;
    if (id > count) return 0;
    idx = id - 1;
    ArrayElem** volatile base = m_objectArrayBegin;
    ptr = base[idx];
    if (ptr == 0) return result;
    return ptr->field_4;
}
