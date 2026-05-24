// 0x802992A4 AptPseudoDisplayList::Remove(AptPseudoCIH_t (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; lwz 9,0xc(31); cmpwi 9,0; beq 0f; lwz 0,0x8(31); stw 0,0x8(9); 0:; lwz 9,0x8(31); cmpwi 9,0; beq 1f; lwz 0,0xc(31); stw 0,0xc(9); 1:; cmpwi 31,0; beq 3f; lwz 9,0x4(31); li 30,0; stw 30,0x0(31); stw 30,0x8(31); cmpwi 9,0; stw 30,0xc(31); beq 2f; mr 3,9; stw 30,0x0(9); stw 30,0x4(9); li 4,28; stw 30,0x8(9); bl _s802992A4_0; stw 30,0x4(31); 2:; mr 3,31; li 4,20; bl _s802992A4_1; 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s802992A4_0();
extern "C" void _s802992A4_1();

struct AptPseudoDisplayList {
    void Remove_AptPseudoCIH_t();
};

void AptPseudoDisplayList::Remove_AptPseudoCIH_t() {
}
