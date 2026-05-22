// 0x802BCC24 EAStringC::Find(char, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); lhz 0,0x2(3); cmpw 5,0; bge 1f; mr. 0,5; bge 0f; li 0,0; 0:; addi 3,3,8; add 3,3,0; bl _s802BCC24_0; mr. 0,3; bne 2f; 1:; li 3,-1; b 3f; 2:; lwz 3,0x0(31); addi 3,3,8; subf 3,3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802BCC24_0();
extern "C" void f_802BCC24() {}
