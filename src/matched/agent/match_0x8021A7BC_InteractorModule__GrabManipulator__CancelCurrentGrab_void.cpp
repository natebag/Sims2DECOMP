// 0x8021A7BC InteractorModule::GrabManipulator::CancelCurrentGrab(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); lis 9,-32697; addi 30,1,8; addi 9,9,-31496; li 0,1; stw 9,0x8(30); mr 31,3; stw 0,0x8(1); addi 11,31,172; mr 3,30; lis 9,-32697; lwz 0,0x8(11); addi 29,9,-32168; stw 0,0x4(30); lwz 0,0xc(11); mtspr 8,0; blrl; addi 3,31,100; bl _s8021A7BC_0; mr 3,31; li 4,1; bl _s8021A7BC_1; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 0f; mr 3,31; li 4,0; bl _s8021A7BC_2; 0:; stw 29,0x8(30); lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8021A7BC_0();
extern "C" void _s8021A7BC_1();
extern "C" void _s8021A7BC_2();
extern "C" void f_8021A7BC() {}
