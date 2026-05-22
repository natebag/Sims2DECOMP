// 0x8021AAF0 InteractorModule::PlacementObject::~PlacementObject(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; addi 11,31,20; lwz 9,0x14(31); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,6; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); lis 9,-21846; ori 9,9,43691; subf 0,3,0; mullw 0,0,9; srawi 0,0,1; mulli 4,0,6; cmplwi 4,128; ble 2f; bl _s8021AAF0_0; b 3f; 2:; bl _s8021AAF0_1; 3:; andi. 0,30,1; beq 4f; mr 3,31; bl _s8021AAF0_2; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021AAF0_0();
extern "C" void _s8021AAF0_1();
extern "C" void _s8021AAF0_2();
extern "C" void f_8021AAF0() {}
