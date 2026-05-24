// 0x80285160 AptActionQueueC::AddFunctionBack(AptCIH (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 10,4; lwz 0,0x10(31); mr 27,5; lwz 11,0x8(31); mr 26,6; mulli 0,0,20; lwz 9,0x0(31); addi 28,11,20; add 0,9,0; cmpw 28,0; bne 0f; mr 28,9; 0:; lwz 0,0x4(31); cmpw 28,0; beq 1f; li 0,2; lis 29,-32704; stw 0,0x0(11); lis 30,-32704; addi 4,29,12980; addi 5,30,11876; lwz 11,0x8(31); li 6,1809; stw 7,0x4(11); lwz 9,0x8(31); stw 10,0x8(9); lwz 11,0x8(31); lwz 10,0x8(11); lwz 9,0x8(10); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x8(31); addi 4,29,12980; addi 5,30,11876; li 6,1811; stw 27,0xc(11); lwz 9,0x8(31); lwz 10,0xc(9); lwz 11,0x8(10); lha 3,0x8(11); lwz 0,0xc(11); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x8(31); stw 26,0x10(9); stw 28,0x8(31); 1:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

struct AptActionQueueC {
    void AddFunctionBack_AptCIH();
};

void AptActionQueueC::AddFunctionBack_AptCIH() {
}
