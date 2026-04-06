// 0x80054DD8 (60b) — VERIFIED MATCH
// EIObjectMan::AttachObject(ISimInstance_ptr)

class ISimInstance;

class EIObjectMan {
public:
    int m_count;
    char _pad[4];
    
    void AttachObject(ISimInstance* obj);
};

extern void ObjectList_Add(char* list, int count, ISimInstance* obj, int zero);

void EIObjectMan::AttachObject(ISimInstance* obj) {
    int count = this->m_count;
    this->m_count = count + 1;
    ObjectList_Add((char*)this + 4, count, obj, 0);
}
