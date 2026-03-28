// 0x80110424 (88 bytes)
// ObjResFile::Open(StringBuffer &)

class ObjResFile { public: void Open(StringBuffer &); };

__attribute__((naked))
void ObjResFile::Open(StringBuffer &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x480355E1\n.long 0x7C7E1B79\n.long 0x40820024\n.long 0x806DABFC\n.long 0x7FE4FB78\n.long 0x81230000\n.long 0xA8090108\n.long 0x8129010C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
