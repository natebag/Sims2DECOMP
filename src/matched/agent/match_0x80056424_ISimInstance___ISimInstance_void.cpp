// 0x80056424 ISimInstance::~ISimInstance(void) (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lis 11,-32698; lwz 0,0x328(31); addi 9,9,-14656; addi 11,11,-14600; mr 30,4; stw 9,0x320(31); stw 11,0x0(31); cmpwi 0,0; beq 0f; li 0,0; stw 0,0x328(31); 0:; lwz 11,0x3bc(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,0x3bc(31); bl _s80056424_0; lwz 11,0x3bc(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 11,0x3c0(31); li 0,0; stw 0,0x3bc(31); cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0xe0(9); lwz 0,0xe4(9); add 3,11,3; mtspr 8,0; blrl; lwz 4,0x3c0(31); bl _s80056424_1; lwz 11,0x3c0(31); cmpwi 11,0; beq 2f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 2:; li 0,0; addi 3,31,820; stw 0,0x3c0(31); li 4,2; bl _s80056424_2; addi 3,31,800; li 4,0; bl _s80056424_3; mr 3,31; li 4,0; bl _s80056424_4; andi. 0,30,1; beq 3f; bl _s80056424_5; mr 4,31; bl _s80056424_6; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80056424_0();
extern "C" void _s80056424_1();
extern "C" void _s80056424_2();
extern "C" void _s80056424_3();
extern "C" void _s80056424_4();
extern "C" void _s80056424_5();
extern "C" void _s80056424_6();
extern "C" void f_80056424() {}
