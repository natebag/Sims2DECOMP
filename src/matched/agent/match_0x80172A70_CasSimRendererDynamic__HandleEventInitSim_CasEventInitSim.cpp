// 0x80172A70 CasSimRendererDynamic::HandleEventInitSim(CasEventInitSim (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; addi 30,31,8; bl _s80172A70_0; mr 3,30; bl _s80172A70_1; mr 3,31; bl _s80172A70_2; mr 3,30; bl _s80172A70_3; mr 3,30; bl _s80172A70_4; lis 9,-32702; lis 11,-32702; addi 9,9,17920; addi 11,11,18064; li 7,0; li 6,0; b 1f; 0:; addi 6,10,4; addi 7,7,1; 1:; cmplwi 7,36; bge 3f; mr 10,6; lwz 8,0x218(31); lwzx 0,10,9; cmpw 0,8; beq 2f; lwzx 0,10,11; cmpw 0,8; bne 0b; 2:; lwz 9,0x224(31); lwzx 0,6,9; stw 0,0x218(31); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80172A70_0();
extern "C" void _s80172A70_1();
extern "C" void _s80172A70_2();
extern "C" void _s80172A70_3();
extern "C" void _s80172A70_4();
extern "C" void f_80172A70() {}
