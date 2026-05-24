// 0x8029D838 AptAnimationPoolData::AddListenerToQueue(AptValue (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 29,4; mr 27,5; lwz 0,0x0(29); mr 23,6; li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 0f; rlwinm 11,0,5,31,31; 0:; cmpwi 11,0; beq 1f; mr 3,29; mr 4,27; bl _s8029D838_0; cmpwi 3,0; beq 8f; 1:; lwz 9,0x8(29); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,29,3; blrl; lwz 0,0x0(29); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 2f; rlwinm 11,0,5,31,31; 2:; cmpwi 11,0; bne 3f; lwz 0,0x10(3); and. 9,0,27; bne 3f; lwz 11,0x8(3); cmpwi 11,0; beq 3f; lwz 9,0x8(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x10(3); and. 9,0,27; beq 8f; 3:; lis 9,-32700; lis 11,-32694; addi 24,9,-9760; addi 21,11,-11332; lis 25,-32703; lis 26,-32703; li 22,1; mr 28,24; 4:; lwz 0,0x0(28); and. 9,0,27; beq 7f; lwz 4,0x4(28); mr 3,29; li 5,0; rlwinm 4,4,2,0,29; add 4,4,21; bl _s8029D838_1; mr. 3,3; beq 7f; lwz 0,0x0(3); andis. 9,0,2048; beq 7f; rlwinm 9,0,0,25,31; li 11,0; addi 9,9,-43; cmplwi 9,2; bgt 5f; rlwinm 11,0,5,31,31; 5:; cmpwi 11,0; beq 7f; mr 31,3; lwz 30,0x24(31); cmpw 30,29; beq 6f; lwz 9,0x8(31); mr 4,29; lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,31,3; blrl; mr 31,3; lwz 3,0x28(31); bl _s8029D838_2; lwz 11,0x28(31); addi 4,25,-30176; addi 5,26,-30280; li 6,1194; lwz 9,0x8(11); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; stw 30,0x28(31); addi 4,25,-30176; addi 5,26,-30280; li 6,1199; lhz 9,0x5c(30); addi 9,9,1; sth 9,0x5c(30); lwz 11,0x28(31); lwz 9,0x8(11); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x0(31); rlwimi 0,22,8,18,23; stw 0,0x0(31); 6:; lwz 9,0x8(31); lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; mr 30,3; lwz 3,-23008(13); bl _s8029D838_3; mr 5,31; mr 6,30; mr 4,29; mr 7,23; bl _s8029D838_4; 7:; addi 28,28,8; addi 0,24,40; cmpw 28,0; ble 4b; 8:; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"

extern "C" void _s8029D838_0();
extern "C" void _s8029D838_1();
extern "C" void _s8029D838_2();
extern "C" void _s8029D838_3();
extern "C" void _s8029D838_4();

struct AptAnimationPoolData {
    void AddListenerToQueue_AptValue();
};

void AptAnimationPoolData::AddListenerToQueue_AptValue() {
}
