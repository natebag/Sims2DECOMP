// 0x802E7884 (96 bytes) - EAnimController::~EAnimController(int)
void ENodeList_RemoveAll(void* nodelist);
void EResource_DelRef(void* obj);
void __builtin_delete(void* p);

class EAnimController {
public:
    char pad_00[36];
    void* m_field_24;
    char pad_28[32];
    int m_node_list_at_48;

    void Deallocate();
    void dtor(int flag);
};

void EAnimController::dtor(int flag) {
    Deallocate();
    ENodeList_RemoveAll(&m_node_list_at_48);
    if (m_field_24 != 0) {
        EResource_DelRef(m_field_24);
        m_field_24 = 0;
    }
    if (flag & 1) {
        __builtin_delete(this);
    }
}
