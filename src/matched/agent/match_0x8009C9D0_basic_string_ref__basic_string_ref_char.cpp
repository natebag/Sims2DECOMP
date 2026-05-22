// 0x8009C9D0 basic_string_ref::basic_string_ref(char, (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,5; mr 30,3; stb 4,0x8(1); cmpwi 31,-1; bne 0f; bl _s8009C9D0_0; 0:; stw 31,0x4(30); cmpwi 31,0; stw 31,0x8(30); beq 5f; addi 31,31,1; stw 31,0x8(30); cmpwi 31,0; beq 1f; bl _s8009C9D0_1; mr 4,31; li 5,0; bl _s8009C9D0_2; b 2f; 1:; li 3,0; 2:; lwz 0,0x4(30); li 11,0; stw 3,0x0(30); cmplw 11,0; bge 4f; 3:; lbz 0,0x8(1); lwz 9,0x0(30); stbx 0,9,11; addi 11,11,1; lwz 0,0x4(30); cmplw 11,0; blt 3b; 4:; bl _s8009C9D0_3; lwz 11,0x0(30); lwz 9,0x4(30); stbx 3,11,9; b 6f; 5:; stw 31,0x0(30); 6:; li 0,1; mr 3,30; stw 0,0xc(30); lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8009C9D0_0();
extern "C" void _s8009C9D0_1();
extern "C" void _s8009C9D0_2();
extern "C" void _s8009C9D0_3();
extern "C" void f_8009C9D0() {}
