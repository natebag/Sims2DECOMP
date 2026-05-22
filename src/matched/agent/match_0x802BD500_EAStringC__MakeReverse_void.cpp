// 0x802BD500 EAStringC::MakeReverse(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 5,0; lwz 9,0x0(31); li 7,1; lhz 4,0x2(9); mr 6,4; mr 8,4; bl _s802BD500_0; lwz 9,0x0(31); lhz 0,0x2(9); cmplwi 0,1; bgt 0f; mr 3,31; b 3f; 0:; addi 10,9,8; add 9,10,0; addi 11,9,-1; cmplw 10,11; bge 2f; 1:; lbz 0,0x0(11); lbz 9,0x0(10); stb 0,0x0(10); stb 9,0x0(11); addi 10,10,1; addi 11,11,-1; cmplw 10,11; blt 1b; 2:; lwz 9,0x0(31); li 0,0; mr 3,31; sth 0,0x6(9); 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802BD500_0();
extern "C" void f_802BD500() {}
