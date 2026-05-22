// 0x80090F60 TArray<int, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f1,-32564(9); blr; lis 9,-32706; lfs f1,-32564(9); blr; lwz 3,-32160(13)"
extern "C" float f_80090F60() {}
