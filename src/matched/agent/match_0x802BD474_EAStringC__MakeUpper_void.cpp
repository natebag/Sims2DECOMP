// 0x802BD474 EAStringC::MakeUpper(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 5,0; lwz 9,0x0(30); li 7,1; lhz 31,0x2(9); mr 4,31; mr 6,31; mr 8,31; bl _s802BD474_0; lwz 9,0x0(30); cmpwi 31,0; addi 10,9,8; beq 2f; mtspr 9,31; lis 9,-32704; addi 8,9,-935; 0:; lbz 0,0x0(10); extsb 11,0; lbzx 9,11,8; andi. 0,9,2; beq 1f; addi 11,11,-32; 1:; stb 11,0x0(10); addi 10,10,1; bdnz 0b; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802BD474_0();
extern "C" void f_802BD474() {}
