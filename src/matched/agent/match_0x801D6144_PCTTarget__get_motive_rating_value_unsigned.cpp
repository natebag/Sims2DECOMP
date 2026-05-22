// 0x801D6144 PCTTarget::get_motive_rating_value(unsigned (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); rlwinm 31,4,2,0,29; addi 30,3,216; lwzx 0,30,31; mr 29,5; cmpwi 0,0; beq 0f; addi 9,3,204; lwzx 3,9,31; bl _s801D6144_0; cmpwi 3,0; bne 0f; lwzx 3,30,31; mr 4,29; bl _s801D6144_1; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801D6144_0();
extern "C" void _s801D6144_1();
extern "C" void f_801D6144() {}
