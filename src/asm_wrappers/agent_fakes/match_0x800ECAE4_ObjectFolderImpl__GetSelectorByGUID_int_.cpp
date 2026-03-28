/* ObjectFolderImpl::GetSelectorByGUID(int) at 0x800ECAE4 (136B) */

struct ObjectFolderImpl { void GetSelectorByGUID(); };

__attribute__((naked))
void ObjectFolderImpl::GetSelectorByGUID() {
    asm volatile(
        ".long 0x9421FFD8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF410010\n"
        ".long 0x9001002C\n"
        ".long 0x548915BA\n"
        ".long 0x3BA30040\n"
        ".long 0x7FFD482E\n"
        ".long 0x7D3B4B78\n"
        ".long 0x90810008\n"
        ".long 0x3B410008\n"
        ".long 0x3B800000\n"
        ".long 0x4800000C\n"
        ".long 0x7FFCFB78\n"
        ".long 0x83FF00A4\n"
        ".long 0x2C1F0000\n"
        ".long 0x41820034\n"
        ".long 0x83DA0000\n"
        ".long 0x7FE3FB78\n"
        ".long 0x48023DB1\n"
        ".long 0x7C1E1800\n"
        ".long 0x4082FFE0\n"
        ".long 0x2C1C0000\n"
        ".long 0x41820018\n"
        ".long 0x801F00A4\n"
        ".long 0x901C00A4\n"
        ".long 0x7D3DD82E\n"
        ".long 0x913F00A4\n"
        ".long 0x7FFDD92E\n"
        ".long 0x7FE3FB78\n"
        ".long 0x8001002C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB410010\n"
        ".long 0x38210028\n"
        ".long 0x4E800020\n"
    );
}
