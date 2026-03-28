/* __static_initialization_and_destruction_0 at 0x800235E8 (136B) */

extern int ESimsDataManager_vtable[];

void ESimsDataManager_ctor(void*);
void SomeClass_ctor(void*);
void SomeClass_dtor(void*, int);
void ESimsDataManager_dtor(void*, int);

extern char g_simsDataManager[];
extern char g_someObj[];

void __static_initialization_and_destruction_0_800235E8(int initialize, int priority) {
    if (priority != 0xFFFF) return;
    if (initialize != 0) {
        ESimsDataManager_ctor(g_simsDataManager);
        char* obj = g_someObj;
        SomeClass_ctor(obj);
        *(int*)(obj + 0x28) = (int)ESimsDataManager_vtable;
    } else {
        SomeClass_dtor(g_someObj, 0);
        ESimsDataManager_dtor(g_simsDataManager, 2);
    }
}
