// 0x8008FE28 ELiveMode::EndIntroCamera(CameraDirector (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,5; li 29,0; mr. 31,4; beq 0f; lwz 3,-21484(13); lwz 9,0x0(3); lha 0,0xb8(9); lwz 9,0xbc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; li 29,1; 0:; cmpwi 29,0; beq 2f; lis 9,-32697; lwz 0,0x5e7c(9); cmpwi 0,0; lwz 0,0x240(31); mr 3,31; rlwinm 0,0,0,0,30; stw 0,0x240(31); bl _s8008FE28_0; cmpwi 30,0; beq 1f; mr 3,30; li 4,-1; bl _s8008FE28_1; 1:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 2f; li 0,0; stw 0,0x54c(30); 2:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8008FE28_0();
extern "C" void _s8008FE28_1();
extern "C" void f_8008FE28() {}
