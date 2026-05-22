// 0x80303F9C EController::~EController(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32697; lwz 3,0x1fc(31); addi 9,9,-21000; mr 30,4; stw 9,0x208(31); cmpwi 3,0; beq 0f; bl _s80303F9C_0; li 0,0; stw 0,0x1fc(31); 0:; lwz 3,0x200(31); cmpwi 3,0; beq 1f; bl _s80303F9C_1; li 0,0; stw 0,0x200(31); 1:; andi. 0,30,1; beq 2f; mr 3,31; bl _s80303F9C_2; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80303F9C_0();
extern "C" void _s80303F9C_1();
extern "C" void _s80303F9C_2();
extern "C" void f_80303F9C() {}
