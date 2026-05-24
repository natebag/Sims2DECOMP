// 0x800F45A8 ObjectModuleImpl::Init(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x14(31); cmpwi 0,0; bne 0f; lwz 0,0x2090(31); addi 3,31,8352; li 4,0; li 5,64; stw 0,0x2094(31); bl _s800F45A8_0; lwz 11,0x1c(31); li 0,1; stw 0,0x14(31); stw 11,0x20(31); lwz 9,0x0(31); lha 3,0x160(9); lwz 0,0x164(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s800F45A8_0();

struct ObjectModuleImpl {
    void Init();
};

void ObjectModuleImpl::Init() {
}
