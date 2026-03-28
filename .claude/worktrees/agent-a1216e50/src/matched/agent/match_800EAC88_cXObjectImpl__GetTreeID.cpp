// 0x800EAC88 (96 bytes)
// cXObjectImpl::GetTreeID(ObjEntryPoint)

class cXObjectImpl { public: void GetTreeID(ObjEntryPoint); };

__attribute__((naked))
void cXObjectImpl::GetTreeID(ObjEntryPoint) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x81630004\n.long 0x7C9E2378\n.long 0x812B0004\n.long 0x800901CC\n.long 0xA86901C8\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0x7FC4F378\n.long 0xA8090070\n.long 0x81290074\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
