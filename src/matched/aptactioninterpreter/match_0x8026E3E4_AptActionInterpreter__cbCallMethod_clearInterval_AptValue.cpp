// 0x8026E3E4 AptActionInterpreter::cbCallMethod_clearInterval(AptValue (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32694; lwz 11,-16032(9); addi 9,9,-16032; lwz 0,0x8(9); rlwinm 11,11,2,0,29; add 11,11,0; lwz 3,-4(11); lwz 0,0x0(3); rlwinm 0,0,5,31,31; xori 30,0,1; cmpwi 30,0; bne 2f; bl _s8026E3E4_0; lwz 9,-23008(13); rlwinm 31,3,5,0,26; lwz 11,0x2c(9); lwzx 0,31,11; add 9,31,11; cmpwi 0,0; beq 2f; lwz 11,0x4(9); lis 4,-32704; lis 5,-32704; addi 4,4,6448; lwz 9,0x8(11); addi 5,5,6212; li 6,1417; lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-23008(13); lwz 9,0x2c(11); stwx 30,31,9; lwz 0,0x2c(11); add 31,31,0; lwz 0,0x14(31); cmpwi 0,0; ble 1f; mr 30,0; addi 29,31,20; lis 27,-32704; lis 28,-32704; 0:; lwz 11,0x14(31); addi 4,27,5240; lwz 0,0x8(29); addi 5,28,5280; rlwinm 11,11,2,0,29; li 6,126; add 11,11,0; lwz 10,-4(11); lwz 9,0x8(10); lha 3,0x10(9); lwz 0,0x14(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x14(31); addic. 30,30,-1; addi 9,9,-1; stw 9,0x14(31); bne 0b; 1:; lwz 11,-23008(13); lwz 9,0x30(11); addi 9,9,-1; stw 9,0x30(11); 2:; lwz 3,-22936(13); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8026E3E4_0();

struct AptActionInterpreter {
    void cbCallMethod_clearInterval();
};

void AptActionInterpreter::cbCallMethod_clearInterval() {
}
