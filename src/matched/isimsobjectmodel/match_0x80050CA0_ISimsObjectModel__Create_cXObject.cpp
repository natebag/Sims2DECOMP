// 0x80050CA0 ISimsObjectModel::Create(cXObject (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; cmpwi 4,0; stw 4,0x328(31); stw 5,0x3c8(31); beq 0f; cmpwi 5,0; beq 0f; lwz 9,0x320(31); addi 0,31,800; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; mr 3,31; bl _s80050CA0_0; b 1f; 0:; lwz 9,0x0(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x120(31); cmpwi 0,0; beq 2f; lwz 9,0x0(31); lha 3,0x50(9); lwz 0,0x54(9); add 3,31,3; mtspr 8,0; blrl; 2:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80050CA0_0();

struct ISimsObjectModel {
    void Create_cXObject();
};

void ISimsObjectModel::Create_cXObject() {
}
