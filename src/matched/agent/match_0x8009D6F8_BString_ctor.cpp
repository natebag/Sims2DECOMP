// FLAGS: -fno-elide-constructors
// 0x8009D6F8 BString::BString (32B)
extern int VT_BString[];
struct BString { BString(); };
BString::BString() { *(int**)this = VT_BString; VT_BString[3]++; }
