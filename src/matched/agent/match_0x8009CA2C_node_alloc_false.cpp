// 0x8009CA2C __node_alloc<false, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; lwz 0,0x4(30); li 11,0; stw 3,0x0(30); cmplw 11,0; bge 1f; 0:; lbz 0,0x8(1); lwz 9,0x0(30); stbx 0,9,11; addi 11,11,1; lwz 0,0x4(30); cmplw 11,0; blt 0b; 1:; bl _s8009CA2C_0; lwz 11,0x0(30); lwz 9,0x4(30); stbx 3,11,9; b 2f; stw 31,0x0(30); 2:; li 0,1; mr 3,30; stw 0,0xc(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; bl _s8009CA2C_1; andi. 0,30,1; beq 3f; mr 3,31; bl _s8009CA2C_2; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8009CA2C_0();
extern "C" void _s8009CA2C_1();
extern "C" void _s8009CA2C_2();
extern "C" void f_8009CA2C() {}
