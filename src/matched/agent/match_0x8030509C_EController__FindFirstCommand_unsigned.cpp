// 0x8030509C EController::FindFirstCommand(unsigned (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; cmpwi 4,0; stw 4,0x8(1); beq 1f; lwz 4,0x1a4(31); lis 7,-32720; lwz 5,0x1a8(31); addi 7,7,20604; addi 3,1,8; li 6,8; bl _s8030509C_0; mr. 3,3; beq 2f; lwz 11,0x1a4(31); cmpw 3,11; beq 2f; lwz 0,-8(3); lwz 9,0x8(1); cmpw 0,9; bne 2f; 0:; addi 3,3,-8; cmpw 3,11; beq 2f; lwz 0,-8(3); cmpw 0,9; beq 0b; b 2f; 1:; li 3,0; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s8030509C_0();
extern "C" void f_8030509C() {}
