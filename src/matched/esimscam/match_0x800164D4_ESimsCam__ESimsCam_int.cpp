// 0x800164D4 ESimsCam::ESimsCam(int) (456 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stfd f31,0x58(1); stmw 17,0x1c(1); stw 0,0x64(1); lis 9,-32698; mr 31,3; addi 9,9,-21016; mr 29,4; stw 9,0x56c(31); addi 3,31,16; bl _s800164D4_0; li 0,4; addi 21,1,8; mtspr 9,0; 0:; bdnz 0b; li 0,4; mulli 28,29,456; mtspr 9,0; addi 20,31,1224; addi 19,31,1148; addi 18,31,1160; addi 17,31,1172; 1:; bdnz 1b; mr 3,20; li 30,0; bl _s800164D4_1; li 22,1; lis 9,-32697; stw 29,0x4(31); addi 9,9,13784; stw 30,0x560(31); add 9,28,9; li 3,92; stw 9,0x0(31); bl _s800164D4_2; lwz 4,0x0(31); bl _s800164D4_3; lis 9,-32707; stw 3,0x550(31); lfs f31,-7428(9); li 23,-1; lis 27,-30717; lis 26,-252; stfs f31,0x8(21); lis 28,26125; stfs f31,0x4(21); lis 29,4362; stfs f31,0x8(1); lis 10,28670; lis 8,28549; lis 7,-21244; lwz 0,0x8(1); ori 27,27,16580; lwz 11,0x8(21); ori 26,26,28754; lwz 24,0x4(21); ori 28,28,8680; stfs f31,0x8(21); ori 29,29,4478; stfs f31,0x4(21); ori 10,10,32302; stfs f31,0x8(1); ori 8,8,21236; stw 0,0x47c(31); ori 7,7,56074; lwz 0,0x8(21); lis 4,-340; lwz 9,0x8(1); mr 3,20; lwz 25,0x4(21); ori 4,4,59851; stfs f31,0x8(21); li 5,2; stfs f31,0x4(21); li 6,0; stfs f31,0x8(1); stw 11,0x8(19); stw 24,0x4(19); stw 9,0x488(31); lwz 11,0x8(1); stw 0,0x8(18); stw 25,0x4(18); lwz 0,0x8(21); lwz 9,0x4(21); stw 11,0x494(31); stw 0,0x8(17); stw 9,0x4(17); stw 23,0x4a8(31); stfs f31,0x4a0(31); stfs f31,0x4a4(31); stw 22,0x540(31); sth 30,0x544(31); stw 30,0x548(31); stw 27,0x4ac(31); stw 26,0x4b0(31); stw 28,0x4b4(31); stw 29,0x4b8(31); stw 10,0x4bc(31); stw 8,0x4c0(31); stw 7,0x4c4(31); bl _s800164D4_4; stfs f31,0x470(31); mr 3,31; stw 22,0x474(31); stw 30,0x568(31); stw 30,0x46c(31); stw 30,0x564(31); lwz 0,0x64(1); mtspr 8,0; lmw 17,0x1c(1); lfd f31,0x58(1); addi 1,1,96"

extern "C" void _s800164D4_0();
extern "C" void _s800164D4_1();
extern "C" void _s800164D4_2();
extern "C" void _s800164D4_3();
extern "C" void _s800164D4_4();

struct ESimsCam {
    void ESimsCam();
};

void ESimsCam::ESimsCam() {
}
