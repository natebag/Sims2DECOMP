// 0x8009C914 basic_string_ref::basic_string_ref(char (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr. 29,4; beq 0f; mr 3,29; bl _s8009C914_0; stw 3,0x8(30); stw 3,0x4(30); b 1f; 0:; stw 29,0x4(30); stw 29,0x8(30); 1:; lwz 4,0x8(30); cmpwi 4,0; beq 4f; addi 31,4,1; stw 31,0x8(30); cmpwi 31,0; beq 2f; bl _s8009C914_1; mr 4,31; li 5,0; bl _s8009C914_2; mr 0,3; b 3f; 2:; li 0,0; 3:; lwz 5,0x4(30); mr 4,29; mr 3,0; stw 0,0x0(30); bl _s8009C914_3; bl _s8009C914_4; lwz 11,0x0(30); lwz 9,0x4(30); stbx 3,11,9; b 5f; 4:; stw 4,0x0(30); 5:; li 0,1; mr 3,30; stw 0,0xc(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009C914_0();
extern "C" void _s8009C914_1();
extern "C" void _s8009C914_2();
extern "C" void _s8009C914_3();
extern "C" void _s8009C914_4();
extern "C" void f_8009C914() {}
