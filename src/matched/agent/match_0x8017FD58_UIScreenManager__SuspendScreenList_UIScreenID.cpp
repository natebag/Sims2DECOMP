// 0x8017FD58 UIScreenManager::SuspendScreenList(UIScreenID (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); lwz 9,-31496(13); mr 31,3; addi 29,31,136; addi 27,31,140; addi 9,9,1; mr 28,4; stw 9,-31496(13); li 3,0; li 11,0; li 24,2; lis 25,-32706; lis 26,-32706; 0:; rlwinm 9,11,4,0,27; addi 30,11,1; lwzx 0,29,9; mr 10,9; cmpwi 0,1; bne 5f; addi 12,31,132; li 7,0; mr 5,12; li 8,0; mr 6,10; mr 11,28; 1:; lwz 9,0x0(11); addi 11,11,4; cmpwi 9,68; ble 2f; li 8,1; 2:; lwzx 0,5,6; cmpw 9,0; bne 3f; li 7,1; 3:; cmpwi 7,0; bne 4f; cmpwi 8,0; beq 1b; b 5f; 4:; lwz 0,-31496(13); addi 4,1,8; stwx 24,29,10; mr 3,31; stwx 0,27,10; lwzx 5,12,10; bl _s8017FD58_0; lwz 3,-25136(13); addi 4,25,15128; li 5,0; li 6,0; li 7,2; addi 8,26,15188; addi 9,1,8; crxor 6,6,6; bl _s8017FD58_1; lwz 3,-31496(13); 5:; mr 11,30; cmpwi 11,23; ble 0b; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s8017FD58_0();
extern "C" void _s8017FD58_1();
extern "C" void f_8017FD58() {}
