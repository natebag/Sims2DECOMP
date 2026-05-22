// 0x803C247C EStorable::Construct(EStorable (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32697; addi 9,9,-28472; stw 9,0x0(3)"
extern "C" void f_803C247C() {}
