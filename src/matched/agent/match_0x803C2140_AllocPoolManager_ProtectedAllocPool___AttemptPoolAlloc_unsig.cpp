// 0x803C2140 AllocPoolManager<ProtectedAllocPool>::AttemptPoolAlloc(unsigned (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 27,5; cmplwi 4,64; ble 1f; b 4f; 0:; mr 3,30; b 5f; 1:; addi 0,4,-1; rlwinm 28,0,29,3,31; cmpwi 28,7; bgt 4f; mulli 9,28,52; addi 0,9,8; addi 9,9,32; add 31,0,3; add 29,9,3; 2:; lwz 0,0x10(31); cmplw 27,0; bgt 3f; stw 29,0x8(1); li 4,-1; lwz 9,0x18(31); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,29,3; blrl; mr 3,31; bl _s803C2140_0; lwz 11,0x8(1); mr 30,3; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 30,0; bne 0b; 3:; addi 28,28,1; addi 29,29,52; addi 31,31,52; cmpwi 28,7; ble 2b; 4:; li 3,0; 5:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s803C2140_0();
extern "C" void f_803C2140() {}
