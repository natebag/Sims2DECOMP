// 0x8011150C (124 bytes)
// ObjSelector::GetShortFilename(StringBuffer *)

class ObjSelector { public: void GetShortFilename(StringBuffer *); };

__attribute__((naked))
void ObjSelector::GetShortFilename(StringBuffer *) {
    asm volatile(".long 0x9421FDC0\n.long 0x7C0802A6\n.long 0xBF61022C\n.long 0x90010244\n.long 0x3BC10008\n.long 0x83A30018\n.long 0x7C9B2378\n.long 0x38A00104\n.long 0x389E0008\n.long 0x7FC3F378\n.long 0x4BF95079\n.long 0x3B810118\n.long 0x7FA4EB78\n.long 0x7FC3F378\n.long 0x38A0FFFF\n.long 0x4BF950D9\n.long 0x38810120\n.long 0x38A00104\n.long 0x38610118\n.long 0x4BF95055\n.long 0x7FC3F378\n.long 0x7F84E378\n.long 0x4BF943B5\n.long 0x7F63DB78\n.long 0x7F84E378\n.long 0x4BF951F9\n.long 0x80010244\n.long 0x7C0803A6\n.long 0xBB61022C\n.long 0x38210240\n.long 0x4E800020");
}
