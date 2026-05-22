// 0x8022683C InteractorModule::WallPainter::SendBuildItemCountChangeEvent(int) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 29,0x3c(1); stw 0,0x4c(1); lis 9,-32697; addi 31,1,8; addi 9,9,-30392; li 0,0; stw 9,0x8(31); addi 29,1,28; stw 0,0x1c(1); addi 9,1,36; stw 0,0x4(29); mr 30,3; stw 0,0x4(9); mr 3,29; stw 4,0x18(1); addi 4,30,156; bl _s8022683C_0; li 0,5; addi 30,30,172; stw 0,0x8(1); mr 3,31; lwz 0,0x8(30); stw 0,0x4(31); lwz 0,0xc(30); mtspr 8,0; blrl; lwz 9,0x1c(1); lwz 0,0x4(29); cmpw 9,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(29); cmpwi 3,0; beq 3f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 2f; bl _s8022683C_1; b 3f; 2:; bl _s8022683C_2; 3:; lis 9,-32697; addi 9,9,-32168; stw 9,0x8(31); lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x3c(1); addi 1,1,72"
extern "C" void _s8022683C_0();
extern "C" void _s8022683C_1();
extern "C" void _s8022683C_2();
extern "C" void f_8022683C() {}
