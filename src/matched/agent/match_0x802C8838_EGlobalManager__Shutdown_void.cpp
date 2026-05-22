// 0x802C8838 EGlobalManager::Shutdown(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,-26876(13); cmpwi 9,0; bne 1f; lwz 11,-26868(13); li 0,1; stw 0,-26876(13); stw 9,-26880(13); cmpwi 11,0; ble 1f; lis 9,-32688; addi 31,9,-12960; 0:; addi 0,11,-1; rlwinm 0,0,3,0,28; lwzx 11,31,0; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; lwz 9,-26868(13); addi 9,9,-1; mr 11,9; stw 9,-26868(13); cmpwi 11,0; bgt 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_802C8838() {}
