// 0x8034FCBC ENgcTextureBase::~ENgcTextureBase(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; lis 9,-32697; lhz 0,0x16(31); addi 9,9,-12264; mr 29,4; stw 9,0x24(31); cmplwi 0,1; li 4,1; ble 0f; mr 4,0; 0:; mr 3,31; addi 5,1,8; addi 6,1,12; bl _s8034FCBC_0; lwz 9,-25904(13); lwz 0,-25900(13); lwz 11,0x78(31); addi 9,9,-1; subf 0,3,0; stw 9,-25904(13); stw 0,-25900(13); cmpwi 11,0; beq 1f; bl _s8034FCBC_1; lwz 4,0x78(31); bl _s8034FCBC_2; 1:; lis 30,-32692; lwz 4,0x74(31); addi 3,30,-7364; bl _s8034FCBC_3; lwz 4,0x90(31); addi 3,30,-7364; bl _s8034FCBC_4; li 0,0; addi 3,31,40; stw 0,0x90(31); li 4,2; stw 0,0x78(31); stw 0,0x74(31); bl _s8034FCBC_5; mr 3,31; li 4,0; bl _s8034FCBC_6; andi. 0,29,1; beq 2f; addi 3,30,-7364; mr 4,31; bl _s8034FCBC_7; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8034FCBC_0();
extern "C" void _s8034FCBC_1();
extern "C" void _s8034FCBC_2();
extern "C" void _s8034FCBC_3();
extern "C" void _s8034FCBC_4();
extern "C" void _s8034FCBC_5();
extern "C" void _s8034FCBC_6();
extern "C" void _s8034FCBC_7();
extern "C" void f_8034FCBC() {}
