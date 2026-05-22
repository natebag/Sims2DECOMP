// 0x8036CD58 __sn_serialp (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32700; mr 30,3; lwz 0,0x2e48(9); mr 31,4; cmpwi 0,0; beq 0f; li 0,0; li 3,0; stw 0,0x2e48(9); bl _s8036CD58_0; 0:; mr 3,30; mr 4,31; bl _s8036CD58_1; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8036CD58_0();
extern "C" void _s8036CD58_1();
extern "C" void f_8036CD58() {}
