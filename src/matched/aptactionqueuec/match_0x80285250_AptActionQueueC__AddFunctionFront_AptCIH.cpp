// 0x80285250 AptActionQueueC::AddFunctionFront(AptCIH (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 10,4; lwz 9,0x4(31); mr 28,5; lwz 0,0x0(31); mr 27,6; addi 9,9,-20; cmplw 9,0; bge 0f; lwz 9,0x10(31); mulli 9,9,20; addi 9,9,-20; add 9,0,9; 0:; lwz 0,0x8(31); cmpw 9,0; beq 1f; stw 9,0x4(31); li 0,2; stw 0,0x0(9); lis 30,-32704; lis 29,-32704; addi 4,30,13060; lwz 11,0x4(31); addi 5,29,11876; li 6,1863; stw 7,0x4(11); lwz 9,0x4(31); stw 10,0x8(9); lwz 11,0x4(31); lwz 10,0x8(11); lwz 9,0x8(10); lwz 0,0xc(9); lha 3,0x8(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x4(31); addi 4,30,13060; addi 5,29,11876; li 6,1865; stw 28,0xc(11); lwz 9,0x4(31); lwz 10,0xc(9); lwz 11,0x8(10); lha 3,0x8(11); lwz 0,0xc(11); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x4(31); stw 27,0x10(9); 1:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

struct AptActionQueueC {
    void AddFunctionFront_AptCIH();
};

void AptActionQueueC::AddFunctionFront_AptCIH() {
}
