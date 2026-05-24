// 0x800234F4 ESimsDataManager::QueueCommand(ESim (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,3; mr 29,4; mr 28,5; bl _s800234F4_0; stw 30,0x8(1); li 0,2; stw 0,0xd20(30); li 4,-1; lwz 9,0x0(30); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x43c(29); lwz 10,0x8(1); addi 9,9,1; stw 9,0x43c(29); lwz 11,0x0(10); lwz 0,0x1c(11); lha 3,0x18(11); mtspr 8,0; add 3,10,3; blrl; lwz 10,-22652(13); lis 6,-32697; mr 4,30; addi 6,6,18080; lwz 11,0x0(10); mr 7,29; mr 8,28; li 5,1; lha 3,0x50(11); li 9,0; lwz 0,0x54(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800234F4_0();

struct ESimsDataManager {
    void QueueCommand_ESim();
};

void ESimsDataManager::QueueCommand_ESim() {
}
