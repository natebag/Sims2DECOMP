// 0x801F0400 INVTarget::UninstallInventoryPanelInfo(void) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); lis 9,-32704; lis 11,-32704; addi 24,9,-16548; addi 25,11,-15780; mr 31,3; li 27,0; lis 26,-32704; li 28,0; li 29,0; 0:; lwz 0,0x84(31); lwz 3,0x1c(31); mulli 0,0,48; add 0,29,0; lwzx 30,24,0; mr 4,30; bl _s801F0400_0; cmpwi 3,0; beq 1f; lwz 0,0x0(31); cmpwi 0,0; beq 1f; lwz 3,0x1c(31); cmpwi 3,0; beq 1f; mr 4,30; bl _s801F0400_1; 1:; lwz 0,0x84(31); addi 4,26,-30460; addi 27,27,1; addi 29,29,4; mulli 0,0,48; add 0,28,0; lwzx 3,25,0; addi 28,28,4; bl _s801F0400_2; cmplwi 27,11; ble 0b; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s801F0400_0();
extern "C" void _s801F0400_1();
extern "C" void _s801F0400_2();
extern "C" void f_801F0400() {}
