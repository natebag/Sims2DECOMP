// 0x80047104 EFloorShdTblNode::EmptyTable(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; li 0,0; lwz 11,0x5ea0(9); li 10,0; stw 0,-32500(13); lwz 11,0x0(11); cmpwi 11,0; beq 0f; lwz 10,-4(11); 0:; cmpwi 10,0; ble 2f; lis 9,-32696; mr 31,10; addi 30,9,-29672; 1:; mr 3,30; bl _s80047104_0; addi 30,30,16; addic. 31,31,-1; bne 1b; 2:; lis 9,-32696; addi 31,9,-28520; addi 30,31,468; 3:; mr 3,31; bl _s80047104_1; addi 31,31,12; cmpw 31,30; ble 3b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80047104_0();
extern "C" void _s80047104_1();
extern "C" void f_80047104() {}
