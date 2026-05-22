// 0x8009C864 basic_string_ref::basic_string_ref(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,5; mr 30,3; mr 29,4; cmpwi 31,-1; bne 0f; bl _s8009C864_0; 0:; stw 31,0x4(30); cmpwi 31,0; stw 31,0x8(30); beq 3f; addi 31,31,1; stw 31,0x8(30); cmpwi 31,0; beq 1f; bl _s8009C864_1; mr 4,31; li 5,0; bl _s8009C864_2; mr 0,3; b 2f; 1:; li 0,0; 2:; lwz 5,0x4(30); mr 4,29; mr 3,0; stw 0,0x0(30); bl _s8009C864_3; bl _s8009C864_4; lwz 11,0x0(30); lwz 9,0x4(30); stbx 3,11,9; b 4f; 3:; stw 31,0x0(30); 4:; li 0,1; mr 3,30; stw 0,0xc(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009C864_0();
extern "C" void _s8009C864_1();
extern "C" void _s8009C864_2();
extern "C" void _s8009C864_3();
extern "C" void _s8009C864_4();
extern "C" void f_8009C864() {}
