// FLAGS: -msdata=eabi -G 8
#include "types.h"

// Forward declarations
struct ELevelDrawData {
    char pad[152];  // ERC at offset 152
    void* GetERC(); // Returns ERC at offset 152
};

struct EOrderTableData {
    char pad[36];
    void* sim;  // ESim pointer at offset 36
};

struct ERC {
    char pad[168];
    int field_168;
    int field_172;
    int field_180;
};

struct EInstance_vtable {
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual void V8();
    virtual void V9();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual void V13();
    virtual void V14();
    virtual void V15();
    virtual void V16();
    virtual void V17();
    virtual void V18();
    virtual void V19();
    virtual void V20();
    virtual void V21();
    virtual void V22();
    virtual void V23();
    virtual void V24();
    virtual void V25();
    virtual void V26();
    virtual void V27();
    virtual void V28();
    virtual void V29();
    virtual void V30();
    virtual void V31();
    virtual void V32();
    virtual void V33();
    virtual void V34();
    virtual void V35();
    virtual void V36();
    virtual void V37();
    virtual void V38();
    virtual void V39();
    virtual void V40();
    virtual void V41();
    virtual void V42();
    virtual void V43();
    virtual void V44();
    virtual void V45();
    virtual void V46();
    virtual void V47();
    virtual void V48();
    virtual void V49();
    virtual void V50();
    virtual void V51();
    virtual void V52();
    virtual void V53();
    virtual void V54();
    virtual void V55();
    virtual void V56();
    virtual void V57();
    virtual void V58();
    virtual void V59();
    virtual void V60();
    virtual void V61();
    virtual void V62();
    virtual void V63();
    virtual void V64();
    virtual void V65();
    virtual void V66();
    virtual void V67();
    virtual void V68();
    virtual void V69();
    virtual void V70();
    virtual void V71();
    virtual void V72();
    virtual void V73();
    virtual void V74();
    virtual void V75();
};

struct EInstance {
    EInstance_vtable* vtable;
};

struct ESim {
    char pad[112];
    EInstance* instance;  // at offset 112
    char pad2[976-116];
    void* field_976;  // at offset 976
    char pad3[1320-980];
    int field_1320;  // at offset 1320
};

// 0x80032D68 (204B)
// ESim::CensorOrderTableCallback(ELevelDrawData &, EOrderTableData *)
void CensorOrderTableCallback(ELevelDrawData& levelData, EOrderTableData* orderData) {
    ERC* rc = (ERC*)((char*)&levelData + 152);  // Get ERC from levelData at offset 152
    
    ESim* sim = (ESim*)orderData->sim;
    if (sim->field_1320 == 0) {
        rc->field_168 = 0;
        rc->field_172 = 0;
        rc->field_180 = 0;
        return;
    }
    
    // More complex logic with virtual calls goes here...
    // This is a simplified placeholder
}
