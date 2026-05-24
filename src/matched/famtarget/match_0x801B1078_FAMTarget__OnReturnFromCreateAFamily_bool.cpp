// 0x801B1078 FAMTarget::OnReturnFromCreateAFamily(bool) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; mr 30,4; lwz 3,0x5f10(9); li 4,68; li 5,0; bl _s801B1078_0; cmpwi 30,0; beq 0f; lwz 10,-21476(13); lis 9,-32697; lwz 4,0x5c5c(9); lwz 11,0x0(10); lwz 0,0x124(11); lha 3,0x120(11); mtspr 8,0; add 3,10,3; blrl; lwz 0,0x16c(31); mr 4,3; cmpwi 0,0; bne 0f; cmpwi 4,0; beq 0f; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0x140(9); lwz 9,0x144(9); add 3,3,0; mtspr 8,9; blrl; 0:; mr 3,31; bl _s801B1078_1; mr 3,31; bl _s801B1078_2; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s801B1078_0();
extern "C" void _s801B1078_1();
extern "C" void _s801B1078_2();

struct FAMTarget {
    void OnReturnFromCreateAFamily();
};

void FAMTarget::OnReturnFromCreateAFamily() {
}
