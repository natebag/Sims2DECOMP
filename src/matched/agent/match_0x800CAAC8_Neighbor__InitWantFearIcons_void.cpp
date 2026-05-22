// 0x800CAAC8 Neighbor::InitWantFearIcons(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; lwz 0,0x5bcc(9); cmpwi 0,0; beq 1f; li 31,0; 0:; mr 4,31; mr 3,30; li 5,3; addi 31,31,1; bl _s800CAAC8_0; cmplwi 31,6; ble 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800CAAC8_0();
extern "C" void f_800CAAC8() {}
