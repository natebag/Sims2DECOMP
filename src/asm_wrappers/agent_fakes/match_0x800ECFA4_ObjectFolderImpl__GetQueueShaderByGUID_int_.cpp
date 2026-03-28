/* ObjectFolderImpl::GetQueueShaderByGUID(int) at 0x800ECFA4 (132B) */

struct ObjectFolderImpl { void GetQueueShaderByGUID(); };

__attribute__((naked))
void ObjectFolderImpl::GetQueueShaderByGUID() {
    asm volatile(
        ".long 0x9421FFF8\n"
        ".long 0x7C0802A6\n"
        ".long 0x9001000C\n"
        ".long 0x81230000\n"
        ".long 0xA8090078\n"
        ".long 0x8129007C\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x81230054\n"
        ".long 0x39000000\n"
        ".long 0x81490000\n"
        ".long 0x2F8A0000\n"
        ".long 0x7D4B5378\n"
        ".long 0x48000024\n"
        ".long 0x812B0000\n"
        ".long 0x812900C0\n"
        ".long 0x2C090000\n"
        ".long 0x4182000C\n"
        ".long 0x8069001C\n"
        ".long 0x48000024\n"
        ".long 0x396B0004\n"
        ".long 0x39080001\n"
        ".long 0x38000000\n"
        ".long 0x419E0008\n"
        ".long 0x800AFFFC\n"
        ".long 0x7C080000\n"
        ".long 0x4180FFD0\n"
        ".long 0x38600000\n"
        ".long 0x8001000C\n"
        ".long 0x7C0803A6\n"
        ".long 0x38210008\n"
        ".long 0x4E800020\n"
    );
}
