// 0x8021A564 InteractorModule::GrabManipulator::DropCurrentObject(void) (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,3; li 9,1; lwz 0,0x64(30); addi 3,30,100; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 2f; bl _s8021A564_0; cmpwi 3,0; beq 2f; lis 9,-32697; addi 31,1,8; addi 9,9,-31496; li 0,0; stw 9,0x8(31); addi 11,30,172; stw 0,0x8(1); mr 3,31; lis 9,-32697; lwz 0,0x8(11); addi 29,9,-32168; stw 0,0x4(31); lwz 0,0xc(11); mtspr 8,0; blrl; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 1f; mr 3,30; li 4,0; bl _s8021A564_1; 1:; mr 3,30; li 4,1; bl _s8021A564_2; stw 29,0x8(31); 2:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s8021A564_0();
extern "C" void _s8021A564_1();
extern "C" void _s8021A564_2();
extern "C" void f_8021A564() {}
