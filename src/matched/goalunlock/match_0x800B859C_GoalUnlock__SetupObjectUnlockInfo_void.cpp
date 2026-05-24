// 0x800B859C GoalUnlock::SetupObjectUnlockInfo(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 3,-32692; lis 4,3123; ori 4,4,56129; li 5,0; li 6,0; addi 3,3,-20832; bl _s800B859C_0; li 31,0; mr 30,3; lis 4,-32706; addi 4,4,-25592; bl _s800B859C_1; mr 11,3; li 10,0; lwz 0,0xc(11); cmplw 10,0; bge 6f; lis 9,-32696; addi 5,9,24188; 0:; mulli 9,10,72; lwz 0,0x4(11); li 11,0; add 7,0,9; addi 6,10,1; b 3f; 1:; rlwinm 8,11,2,0,29; lwzx 9,9,8; lha 0,0xc(9); cmpwi 0,0; ble 2f; lwz 9,0x1c(9); rlwinm 0,31,3,0,28; addi 11,31,1; add 10,0,5; stwx 9,5,0; extsh 31,11; lwz 9,0x0(7); lwzx 11,9,8; lhz 0,0xc(11); sth 0,0x4(10); b 5f; 2:; addi 11,11,1; 3:; lwz 9,0x0(7); li 0,0; cmpwi 9,0; beq 4f; lwz 0,-4(9); 4:; cmpw 11,0; blt 1b; 5:; mr 11,3; mr 10,6; lwz 0,0xc(11); cmplw 10,0; blt 0b; 6:; mr 3,30; bl _s800B859C_2; mr 10,31; cmplwi 10,127; bgt 8f; lis 9,-32696; rlwinm 0,10,3,0,28; addi 9,9,24188; li 11,0; addi 10,9,1016; add 9,0,9; 7:; stw 11,0x0(9); sth 11,0x4(9); addi 9,9,8; cmplw 9,10; ble 7b; 8:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800B859C_0();
extern "C" void _s800B859C_1();
extern "C" void _s800B859C_2();

struct GoalUnlock {
    void SetupObjectUnlockInfo();
};

void GoalUnlock::SetupObjectUnlockInfo() {
}
