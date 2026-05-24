// 0x80165824 CasScene::Draw(ERC (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 29,0x4c(1); stw 0,0x5c(1); mr 30,4; mr 29,3; bl _s80165824_0; lwz 9,0x70(30); li 5,0; li 4,0; lwz 0,0x124(9); lha 3,0x120(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,0; lwz 0,0x13c(9); lha 3,0x138(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 4,72; li 5,0; lwz 0,0x154(9); lha 3,0x150(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x70(30); lis 9,-32706; li 8,0; lfs f1,-972(9); lwz 0,0x21c(11); li 4,2; lha 3,0x218(11); li 5,2; mtspr 8,0; li 6,2; add 3,30,3; li 7,1; blrl; lwz 9,0x70(30); li 7,0; li 4,1; li 5,1; lwz 0,0x1cc(9); li 6,0; lha 3,0x1c8(9); mtspr 8,0; add 3,30,3; blrl; lwz 11,0x70(30); lis 9,-32706; lfs f1,-968(9); li 6,0; lwz 0,0x1d4(11); li 4,0; lha 3,0x1d0(11); li 5,5; mtspr 8,0; add 3,30,3; blrl; lwz 9,0x70(30); li 5,0; li 4,0; lwz 0,0x204(9); lha 3,0x200(9); mtspr 8,0; add 3,30,3; blrl; addi 3,1,8; bl _s80165824_1; lwz 9,0x4(29); lwz 4,0xab4(29); lha 3,0x80(9); lwz 0,0x84(9); add 3,29,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; mr 3,29; addi 6,1,8; bl _s80165824_2; lwz 0,0x5c(1); mtspr 8,0; lmw 29,0x4c(1); addi 1,1,88"

extern "C" void _s80165824_0();
extern "C" void _s80165824_1();
extern "C" void _s80165824_2();

struct CasScene {
    void Draw();
};

void CasScene::Draw() {
}
