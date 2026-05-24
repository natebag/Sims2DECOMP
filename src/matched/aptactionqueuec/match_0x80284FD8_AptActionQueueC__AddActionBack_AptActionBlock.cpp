// 0x80284FD8 AptActionQueueC::AddActionBack(AptActionBlock (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 8,4; lwz 0,0x10(31); mr 10,5; lwz 11,0x8(31); mr 29,6; mulli 0,0,20; lwz 9,0x0(31); addi 30,11,20; add 0,9,0; cmpw 30,0; bne 0f; mr 30,9; 0:; lwz 0,0x4(31); cmpw 30,0; beq 1f; li 0,1; lis 4,-32704; stw 0,0x0(11); lis 5,-32704; addi 4,4,12796; addi 5,5,11876; lwz 9,0x4c(10); li 6,1707; lwz 11,0x8(31); lwz 0,0x28(9); stw 0,0x8(11); lwz 9,0x8(31); stw 8,0xc(9); lwz 11,0x8(31); stw 10,0x10(11); lwz 9,0x8(10); lha 3,0x8(9); lwz 0,0xc(9); add 3,10,3; mtspr 8,0; blrl; lwz 9,0x8(31); stw 29,0x4(9); stw 30,0x8(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct AptActionQueueC {
    void AddActionBack_AptActionBlock();
};

void AptActionQueueC::AddActionBack_AptActionBlock() {
}
