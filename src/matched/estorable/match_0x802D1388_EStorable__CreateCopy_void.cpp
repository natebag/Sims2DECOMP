// 0x802D1388 EStorable::CreateCopy(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 28,0x40(1); stw 0,0x54(1); addi 29,1,8; mr 30,3; mr 3,29; bl _s802D1388_0; addi 3,1,8; mr 4,30; bl _s802D1388_1; addi 3,1,8; bl _s802D1388_2; mr 28,3; li 4,2; addi 3,1,8; bl _s802D1388_3; lis 9,-32697; li 0,0; addi 9,9,-23376; stw 0,0x20(29); stw 9,0x18(29); lis 30,-32697; stw 0,0x8(1); addi 30,30,-23992; addi 4,1,56; mr 3,29; stw 28,0x1c(29); bl _s802D1388_4; mr 3,28; stw 30,0x18(29); bl _s802D1388_5; lwz 3,0x38(1); lwz 0,0x54(1); mtspr 8,0; lmw 28,0x40(1); addi 1,1,80"

extern "C" void _s802D1388_0();
extern "C" void _s802D1388_1();
extern "C" void _s802D1388_2();
extern "C" void _s802D1388_3();
extern "C" void _s802D1388_4();
extern "C" void _s802D1388_5();

struct EStorable {
    void CreateCopy();
};

void EStorable::CreateCopy() {
}
