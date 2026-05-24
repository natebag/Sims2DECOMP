// 0x800AB8C4 Behavior::GetNodeText(short, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; mr 29,6; addi 6,1,8; bl _s800AB8C4_0; cmpwi 3,0; beq 0f; mr 3,31; mr 4,30; mr 6,29; addi 5,1,8; bl _s800AB8C4_1; b 1f; 0:; lis 4,-32706; mr 3,29; addi 4,4,-27944; li 5,-1; bl _s800AB8C4_2; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s800AB8C4_0();
extern "C" void _s800AB8C4_1();
extern "C" void _s800AB8C4_2();

struct Behavior {
    void GetNodeText();
};

void Behavior::GetNodeText() {
}
