// FLAGS: -fno-elide-constructors
// 0x800A1AD4 BString2::BString2 (32B)
extern int VT_BString2[];
struct BString2 { BString2(); };
BString2::BString2() { *(int**)this = VT_BString2; VT_BString2[3]++; }
