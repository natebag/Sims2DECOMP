// 0x8039E240 (100b) - TEST
// Constructor with vtable + embedded object init

extern int VTable_8039E240[];
extern void EmbeddedObj_Ctor(void* ptr, void* param);
extern void EmbeddedObj_SetType(void* ptr, int type);

class TargetClass {
public:
    int* m_vtable;
    char _pad[4];
    char m_embedded[16];
    
    TargetClass(void* param1, void* param2);
};

TargetClass::TargetClass(void* param1, void* param2) {
    this->m_vtable = VTable_8039E240;
    EmbeddedObj_Ctor(this->m_embedded, param2);
    EmbeddedObj_SetType(this->m_embedded, 2);
}
