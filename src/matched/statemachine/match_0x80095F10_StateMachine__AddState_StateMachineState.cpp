// 0x80095F10 StateMachine::AddState(StateMachineState (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 27,3; stw 4,0x8(1); bl _s80095F10_0; cmpwi 3,0; bne 12f; addi 31,27,44; addi 26,1,8; lwz 30,0x4(31); lwz 0,0xc(31); cmpw 30,0; beq 0f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(31); addi 9,9,4; stw 9,0x4(31); b 11f; 0:; lwz 0,0x2c(27); li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 1f; mr 11,10; 1:; lwz 0,0x0(11); add. 0,9,0; beq 3f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 2f; mr 3,28; bl _s80095F10_1; mr 29,3; b 4f; 2:; mr 3,28; bl _s80095F10_2; mr 29,3; b 4f; 3:; li 29,0; li 28,0; 4:; lwz 4,0x0(31); cmpw 30,4; beq 5f; subf 30,4,30; mr 3,29; mr 5,30; bl _s80095F10_3; add 0,3,30; b 6f; 5:; mr 0,29; 6:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 8f; 7:; lwz 0,0x0(26); stw 0,0x0(30); addi 30,30,4; bdnz 7b; 8:; lwz 3,0x0(31); lwz 0,0xc(31); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 10f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 9f; bl _s80095F10_4; b 10f; 9:; bl _s80095F10_5; 10:; add 0,28,29; stw 29,0x0(31); stw 0,0xc(31); stw 30,0x4(31); 11:; lwz 9,0x8(1); stw 27,0x8(9); 12:; lwz 3,0x8(1); lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s80095F10_0();
extern "C" void _s80095F10_1();
extern "C" void _s80095F10_2();
extern "C" void _s80095F10_3();
extern "C" void _s80095F10_4();
extern "C" void _s80095F10_5();

struct StateMachine {
    void AddState_StateMachineState();
};

void StateMachine::AddState_StateMachineState() {
}
