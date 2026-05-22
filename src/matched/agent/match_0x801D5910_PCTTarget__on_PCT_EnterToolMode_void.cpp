// 0x801D5910 PCTTarget::on_PCT_EnterToolMode(void) (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 11,3; lwz 0,0xb0(11); lwz 8,0xa8(11); mulli 10,0,20; add 9,8,10; cmpwi 9,0; beq 0f; lwzx 0,8,10; cmpwi 0,0; beq 0f; blt 0f; cmpwi 0,4; bgt 0f; li 0,0; mr 3,11; stw 0,0xe8(11); li 4,0; bl _s801D5910_0; b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801D5910_0();
extern "C" void f_801D5910() {}
