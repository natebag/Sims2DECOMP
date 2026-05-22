// 0x80116D00 cHitMan::UpdateActiveTrackVolumes(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-296(1); mfspr 0,8; stmw 30,0x120(1); stw 0,0x12c(1); addi 3,3,4; li 8,0; lwz 9,0x4(3); mr 7,3; li 30,0; addi 10,1,8; lwz 0,0x0(9); b 1f; 0:; lwz 0,0x8(9); addi 30,30,1; addi 8,8,1; stw 0,0x0(10); addi 10,10,4; lwz 9,0x108(1); stw 9,0x118(1); lwz 0,0x0(9); stw 9,0x110(1); 1:; stw 0,0x108(1); cmpwi 30,63; bgt 3f; lwz 0,0x4(7); li 11,1; lwz 9,0x108(1); stw 0,0x110(1); cmpw 9,0; bne 2f; li 11,0; 2:; cmpwi 11,0; bne 0b; 3:; cmpwi 8,0; ble 6f; mr 30,8; addi 31,1,8; 4:; lwz 3,0x0(31); addi 31,31,4; cmpwi 3,0; beq 5f; bl _s80116D00_0; 5:; addic. 30,30,-1; bne 4b; 6:; lwz 0,0x12c(1); mtspr 8,0; lmw 30,0x120(1); addi 1,1,296"
extern "C" void _s80116D00_0();
extern "C" void f_80116D00() {}
