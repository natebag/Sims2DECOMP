// 0x80050B00 ISimsObjectModel::SetInitalObjectState(void) (312 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 11,0x328(31); lwz 9,0x4(11); lwz 0,0x524(9); lha 3,0x520(9); mtspr 8,0; add 3,11,3; blrl; addi 3,3,40; li 4,0; bl _s80050B00_0; lha 30,0x0(3); lwz 0,0x3e4(31); cmpw 0,30; beq 3f; lwz 5,-32416(13); mr 4,30; mr 3,31; bl _s80050B00_1; li 0,0; stw 30,0x3e4(31); stw 0,0x4a0(31); mr 29,3; lwz 9,0x420(31); lwz 4,0x0(29); cmpw 9,4; beq 0f; stw 4,0x420(31); cmpwi 4,0; beq 0f; mr 3,31; bl _s80050B00_2; 0:; mr 3,31; bl _s80050B00_3; mr 3,31; bl _s80050B00_4; lwz 0,0x460(31); cmpwi 0,0; beq 1f; mr 3,31; mr 4,29; bl _s80050B00_5; 1:; mr 3,31; mr 4,29; bl _s80050B00_6; mr 3,31; mr 4,29; li 5,0; bl _s80050B00_7; addi 11,31,1056; lwz 9,0x10(29); lwz 0,0x10(11); cmpw 0,9; beq 2f; cmpwi 9,0; beq 2f; stw 9,0x10(11); mr 3,31; lwz 0,0xc(29); stw 0,0xc(11); lwz 5,0x10(29); lwz 4,0xc(29); bl _s80050B00_8; 2:; lwz 9,0x0(31); lha 3,0x60(9); lwz 0,0x64(9); add 3,31,3; mtspr 8,0; blrl; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80050B00_0();
extern "C" void _s80050B00_1();
extern "C" void _s80050B00_2();
extern "C" void _s80050B00_3();
extern "C" void _s80050B00_4();
extern "C" void _s80050B00_5();
extern "C" void _s80050B00_6();
extern "C" void _s80050B00_7();
extern "C" void _s80050B00_8();

struct ISimsObjectModel {
    void SetInitalObjectState();
};

void ISimsObjectModel::SetInitalObjectState() {
}
