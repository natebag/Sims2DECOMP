// 0x80179BB0 UIDB::UIDBSetInt(char (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 0,-31520(13); mr 9,3; mr 31,4; li 3,0; cmpwi 0,0; beq 1f; mr 3,9; li 4,105; bl _s80179BB0_0; mr. 3,3; bne 0f; li 3,0; b 1f; 0:; stw 31,0x8(3); li 3,1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80179BB0_0();
extern "C" void f_80179BB0() {}
