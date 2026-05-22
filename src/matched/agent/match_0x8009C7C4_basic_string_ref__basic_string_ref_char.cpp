// 0x8009C7C4 basic_string_ref::basic_string_ref(char (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; stw 5,0x4(30); cmpwi 6,0; stw 6,0x8(30); beq 2f; addi 31,6,1; stw 31,0x8(30); cmpwi 31,0; beq 0f; bl _s8009C7C4_0; mr 4,31; li 5,0; bl _s8009C7C4_1; b 1f; 0:; li 3,0; 1:; lwz 5,0x4(30); stw 3,0x0(30); cmpwi 5,0; beq 3f; mr 4,29; bl _s8009C7C4_2; bl _s8009C7C4_3; lwz 11,0x0(30); lwz 9,0x4(30); stbx 3,11,9; b 3f; 2:; stw 6,0x0(30); 3:; li 0,1; mr 3,30; stw 0,0xc(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009C7C4_0();
extern "C" void _s8009C7C4_1();
extern "C" void _s8009C7C4_2();
extern "C" void _s8009C7C4_3();
extern "C" void f_8009C7C4() {}
