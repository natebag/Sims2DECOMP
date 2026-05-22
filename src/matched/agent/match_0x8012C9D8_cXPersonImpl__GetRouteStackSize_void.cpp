// 0x8012C9D8 cXPersonImpl::GetRouteStackSize(void) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x40c(3); lis 0,-15985; lwz 3,0x410(3); ori 0,0,39961; subf 3,9,3; mullw 3,3,0; srawi 3,3,2"
extern "C" int f_8012C9D8() {}
