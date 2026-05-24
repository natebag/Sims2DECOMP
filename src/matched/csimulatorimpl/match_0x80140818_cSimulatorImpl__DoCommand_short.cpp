// 0x80140818 cSimulatorImpl::DoCommand(short, (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 11,3; cmpwi 4,218; mr 31,5; beq 4f; bgt 0f; cmpwi 4,135; beq 3f; cmpwi 4,205; beq 2f; b 8f; 0:; cmpwi 4,244; beq 7f; bgt 1f; cmpwi 4,224; beq 5f; b 8f; 1:; cmpwi 4,265; beq 6f; b 8f; 2:; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 9f; 3:; lwz 0,0x178(11); cmpw 0,31; bne 9f; addi 0,31,1; stw 0,0x178(11); b 9f; 4:; lwz 9,0x0(11); li 4,0; lha 3,0xa0(9); addi 29,9,208; lwz 10,0xa4(9); add 3,11,3; lha 30,0xd0(9); mtspr 8,10; add 30,11,30; blrl; lwz 0,0x4(29); add 4,3,31; mr 3,30; li 5,0; mtspr 8,0; blrl; b 9f; 5:; sth 31,0x1a(11); b 9f; 6:; sth 31,0x54(11); b 9f; 7:; sth 31,0x18(11); b 9f; 8:; li 3,0; b 10f; 9:; li 3,1; 10:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct cSimulatorImpl {
    void DoCommand();
};

void cSimulatorImpl::DoCommand() {
}
