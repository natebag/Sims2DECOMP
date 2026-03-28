// 0x80110368 (88 bytes)
// ObjResFile::ObjResFile(void)

class ObjResFile { public: void ObjResFile(void); };

__attribute__((naked))
void ObjResFile::ObjResFile(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x480355D9\n.long 0x3D208046\n.long 0x7FC3F378\n.long 0x39292158\n.long 0x913E000C\n.long 0x4802D679\n.long 0x3CA0803E\n.long 0x7FC3F378\n.long 0x38A5C2B4\n.long 0x38800002\n.long 0x4802D671\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
