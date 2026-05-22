// 0x80029B94 EIFenceWall::~EIFenceWall(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-32640(13); mr 31,3; lis 9,-32698; lwz 3,0x4(31); addi 9,9,-20536; addi 11,11,-1; stw 9,0x0(31); mr 30,4; stw 11,-32640(13); cmpwi 3,0; beq 0f; mr 4,31; bl _s80029B94_0; 0:; lwz 3,0x3ac(31); cmpwi 3,0; beq 1f; bl _s80029B94_1; li 0,0; stw 0,0x3ac(31); 1:; mr 3,31; li 4,0; bl _s80029B94_2; andi. 0,30,1; beq 2f; bl _s80029B94_3; mr 4,31; bl _s80029B94_4; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80029B94_0();
extern "C" void _s80029B94_1();
extern "C" void _s80029B94_2();
extern "C" void _s80029B94_3();
extern "C" void _s80029B94_4();
extern "C" void f_80029B94() {}
