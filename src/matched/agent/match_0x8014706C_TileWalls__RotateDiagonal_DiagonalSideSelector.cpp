// 0x8014706C TileWalls::RotateDiagonal(DiagonalSideSelector, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mulli 4,4,20; rlwinm 3,3,2,0,29; lis 9,-32688; addi 9,9,-16336; add 3,3,4; lwzx 3,9,3"
extern "C" int f_8014706C() {}
