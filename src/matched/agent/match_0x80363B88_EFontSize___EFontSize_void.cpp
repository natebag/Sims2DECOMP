// 0x80363B88 EFontSize::~EFontSize(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; addi 9,9,-9928; mr 30,4; stw 9,0x0(31); bl _s80363B88_0; addi 3,31,32; li 4,2; bl _s80363B88_1; addi 3,31,16; li 4,2; bl _s80363B88_2; lis 9,-32697; andi. 0,30,1; addi 9,9,-28472; stw 9,0x0(31); beq 0f; mr 3,31; bl _s80363B88_3; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80363B88_0();
extern "C" void _s80363B88_1();
extern "C" void _s80363B88_2();
extern "C" void _s80363B88_3();
extern "C" void f_80363B88() {}
