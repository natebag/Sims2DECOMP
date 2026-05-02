// 0x802E7884 (96B) EAnimController::~EAnimController(void)
// Variant L: SI deleting-dtor — Deallocate + ENodeList::RemoveAll(@+0x48) + conditional EResource::DelRef + __builtin_delete branch.

void EAnimController_Deallocate(void* obj);
void ENodeList_RemoveAll(void* nodelist);
void EResource_DelRef(void* obj);
void __builtin_delete(void* p);

struct EAnimController {
    char pad_00_23[36];
    void* m_field_24;
    char pad_28_47[32];
    int m_node_list_at_48;
    void dtor(int flag);
};

void EAnimController::dtor(int flag) {
    EAnimController_Deallocate(this);
    ENodeList_RemoveAll(&m_node_list_at_48);
    if (m_field_24 != 0) {
        EResource_DelRef(m_field_24);
        m_field_24 = 0;
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
