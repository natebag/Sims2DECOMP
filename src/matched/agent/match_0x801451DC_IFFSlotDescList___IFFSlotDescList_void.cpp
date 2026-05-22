// 0x801451DC IFFSlotDescList::~IFFSlotDescList(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,19024; addi 11,31,84; stw 9,0x0(31); mr 30,4; lwz 9,0x54(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,72; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); lis 9,14563; ori 9,9,36409; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,72; cmplwi 4,128; ble 2f; bl _s801451DC_0; b 3f; 2:; bl _s801451DC_1; 3:; mr 3,31; mr 4,30; bl _s801451DC_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801451DC_0();
extern "C" void _s801451DC_1();
extern "C" void _s801451DC_2();
extern "C" void f_801451DC() {}
