// 0x80304D28 EController::GetStick(int, (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,4; mr 30,3; mr 29,5; mr 4,6; bl _s80304D28_0; cmpwi 31,0; bne 0f; andis. 0,3,15; b 1f; 0:; cmpwi 31,1; bne 2f; andis. 0,3,240; 1:; beq 2f; lis 9,-32702; lfs f1,-1632(9); b 4f; 2:; rlwinm 0,31,2,0,29; addi 9,30,396; lwzx 11,9,0; mr 5,29; cmpwi 11,0; beq 3f; subfic 0,5,0; adde 5,0,5; 3:; rlwinm 0,31,3,0,28; rlwinm 10,5,2,0,29; add 10,10,0; addi 9,30,404; lwzx 0,9,10; lis 7,17200; lwz 9,0x200(30); xoris 0,0,32768; lis 8,-32702; stw 0,0x14(1); addi 9,9,40; lfd f0,-1624(8); stw 7,0x10(1); lfsx f13,9,10; lfd f1,0x10(1); fsub f1,f1,f0; frsp f1,f1; fmuls f1,f1,f13; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80304D28_0();
extern "C" void f_80304D28() {}
