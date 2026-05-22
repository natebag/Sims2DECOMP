// 0x8024A880 __default_terminate (16B)
// ASMPROC_inject_before: before="blr" replace="bl f_802427E8" lines="stwu 1,-8(1); mflr 0; stw 0,12(1)"
extern "C" void f_802427E8();
extern "C" void f_8024A880() {}
