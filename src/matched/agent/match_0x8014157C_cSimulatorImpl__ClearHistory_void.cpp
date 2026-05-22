// 0x8014157C cSimulatorImpl::ClearHistory(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 11,8; li 0,0; mtspr 9,11; addi 9,3,368; 0:; stw 0,0x0(9); addi 9,9,-4; bdnz 0b; li 11,0; li 10,0; 1:; rlwinm 9,11,5,0,26; addi 0,11,1; li 11,8; add 9,9,3; mtspr 9,11; addi 9,9,208; 2:; stw 10,0x0(9); addi 9,9,-4; bdnz 2b; mr 11,0; cmpwi 11,4; ble 1b; li 0,0; sth 0,0x4c(3)"
extern "C" void f_8014157C() {}
