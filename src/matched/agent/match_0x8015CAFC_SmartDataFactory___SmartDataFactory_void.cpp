// 0x8015CAFC SmartDataFactory::~SmartDataFactory(void) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32698; mr 30,3; addi 9,9,23328; addi 31,30,4; stw 9,0x0(30); mr 29,4; lwz 0,0x8(31); cmpwi 0,0; beq 0f; lwz 9,0x4(31); mr 3,31; lwz 4,0x4(9); bl _s8015CAFC_0; lwz 9,0x4(31); li 0,0; stw 9,0x8(9); lwz 11,0x4(31); stw 0,0x4(11); lwz 9,0x4(31); stw 9,0xc(9); stw 0,0x8(31); 0:; lwz 3,0x4(31); cmpwi 3,0; beq 1f; li 4,32; bl _s8015CAFC_1; 1:; andi. 0,29,1; beq 2f; mr 3,30; bl _s8015CAFC_2; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8015CAFC_0();
extern "C" void _s8015CAFC_1();
extern "C" void _s8015CAFC_2();
extern "C" void f_8015CAFC() {}
