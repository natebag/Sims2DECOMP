// 0x8035AEE8 EDataHeader::Clear(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 3,0x0(31); li 0,-1; stw 0,0xc(31); stw 30,0x4(31); cmpwi 3,0; stw 30,0x8(31); stw 30,0x10(31); beq 0f; bl _s8035AEE8_0; 0:; stw 30,0x0(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8035AEE8_0();
extern "C" void f_8035AEE8() {}
