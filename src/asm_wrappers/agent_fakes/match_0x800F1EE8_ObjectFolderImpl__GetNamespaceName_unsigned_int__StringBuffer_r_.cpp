/* ObjectFolderImpl::GetNamespaceName(unsigned int, StringBuffer &) at 0x800F1EE8 (132B) */

struct ObjectFolderImpl { void GetNamespaceName(); };

__attribute__((naked))
void ObjectFolderImpl::GetNamespaceName() {
    asm volatile(
        ".long 0x9421FED8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1011C\n"
        ".long 0x9001012C\n"
        ".long 0x81230000\n"
        ".long 0x7CBD2B78\n"
        ".long 0xA8090038\n"
        ".long 0x8129003C\n"
        ".long 0x7C630214\n"
        ".long 0x7D2803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7C7F1B79\n"
        ".long 0x41820040\n"
        ".long 0x3BC10008\n"
        ".long 0x38A00104\n"
        ".long 0x389E0008\n"
        ".long 0x7FC3F378\n"
        ".long 0x4BFB4681\n"
        ".long 0x813F000C\n"
        ".long 0x7FC4F378\n"
        ".long 0xA8690058\n"
        ".long 0x8009005C\n"
        ".long 0x7C7F1A14\n"
        ".long 0x7C0803A6\n"
        ".long 0x4E800021\n"
        ".long 0x7FC3F378\n"
        ".long 0x7FA4EB78\n"
        ".long 0x4BFB39C5\n"
        ".long 0x8001012C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1011C\n"
        ".long 0x38210128\n"
        ".long 0x4E800020\n"
    );
}
