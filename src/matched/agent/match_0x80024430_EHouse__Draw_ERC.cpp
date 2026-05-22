// 0x80024430 EHouse::Draw(ERC (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 29,4; lwz 0,0x1c(31); cmpwi 0,0; beq 2f; bl _s80024430_0; lis 30,-32697; addi 30,30,24012; lwz 9,0xd0(30); lwz 3,0x4(9); bl _s80024430_1; lwz 9,0xd0(30); lwz 3,0x8(31); lwz 4,0x4(9); bl _s80024430_2; lwz 3,0x124(31); cmpwi 3,0; beq 1f; lis 9,-32697; lfs f1,0x44(31); lwz 0,0x5c70(9); cmpwi 0,0; beq 0f; lis 9,-32707; lfs f0,0x96c(9); fmuls f1,f1,f0; 0:; bl _s80024430_3; 1:; lwz 3,0x1c(31); mr 4,29; bl _s80024430_4; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80024430_0();
extern "C" void _s80024430_1();
extern "C" void _s80024430_2();
extern "C" void _s80024430_3();
extern "C" void _s80024430_4();
extern "C" void f_80024430() {}
