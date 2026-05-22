// 0x800B1500 CareersImpl::Load(void) (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lwz 9,0x0(31); addi 30,31,8; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lis 3,-32692; lis 4,20288; ori 4,4,50412; li 6,0; li 5,0; addi 3,3,-20832; bl _s800B1500_0; mr 0,3; lis 4,-32706; addi 4,4,-26620; stw 0,0x4(31); bl _s800B1500_1; mr. 3,3; cmpwi 30,0; beq 0f; stw 3,0x8(31); 0:; lis 4,-32706; lwz 3,0x4(31); addi 4,4,-26612; addi 30,31,12; bl _s800B1500_2; mr 29,3; lis 5,-32706; lwz 3,0x4(31); addi 5,5,-26600; mr 4,29; bl _s800B1500_3; cmpwi 30,0; beq 1f; stw 3,0xc(31); 1:; lis 5,-32706; lwz 3,0x4(31); mr 4,29; addi 5,5,-26592; bl _s800B1500_4; addi 0,31,16; cmpwi 0,0; beq 2f; stw 3,0x10(31); 2:; li 0,0; addi 11,31,20; addi 9,31,24; sth 0,0x14(31); stw 9,0x1c(31); stw 11,0x18(31); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800B1500_0();
extern "C" void _s800B1500_1();
extern "C" void _s800B1500_2();
extern "C" void _s800B1500_3();
extern "C" void _s800B1500_4();
extern "C" void f_800B1500() {}
