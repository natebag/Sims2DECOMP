// 0x8000D674 AptWord::Resize(float) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 30,0x10(1); stw 0,0x24(1); mr 31,3; fmr f31,f1; lwz 9,0xc(31); cmpwi 9,0; beq 1f; lwz 0,0x0(9); cmpwi 0,0; bne 0f; lwz 0,0xc(9); cmpwi 0,0; beq 1f; 0:; lis 30,-32707; lfs f1,0x24(9); lfs f2,-10496(30); li 4,1; lwz 3,-32708(13); bl _s8000D674_0; lwz 4,-32708(13); addi 3,1,8; lwz 5,0x8(31); li 6,1; li 7,0; li 8,0; bl _s8000D674_1; lwz 9,0x8(1); fmr f1,f31; lwz 0,0xc(1); li 4,1; lwz 3,-32708(13); lfs f2,-10496(30); stw 0,0x28(31); stw 9,0x24(31); bl _s8000D674_2; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x10(1); lfd f31,0x18(1); addi 1,1,32"

extern "C" void _s8000D674_0();
extern "C" void _s8000D674_1();
extern "C" void _s8000D674_2();

struct AptWord {
    void Resize();
};

void AptWord::Resize() {
}
