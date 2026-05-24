// 0x800AB4A0 Behavior::CountNodes(short) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); li 0,0; addi 5,1,8; stw 0,0x8(1); li 6,1; bl _s800AB4A0_0; cmpwi 3,0; bne 1f; lwz 11,0x8(1); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 3,0; b 3f; 1:; lwz 3,0x8(1); bl _s800AB4A0_1; lwz 11,0x8(1); mr 31,3; cmpwi 11,0; beq 2f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 2:; mr 3,31; 3:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

extern "C" void _s800AB4A0_0();
extern "C" void _s800AB4A0_1();

struct Behavior {
    void CountNodes();
};

void Behavior::CountNodes() {
}
