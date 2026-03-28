/* HouseImpl::DoStream(ReconBuffer *, int) at 0x800BC1B8 (148B) */

struct HouseImpl { void DoStream(); };

__attribute__((naked))
void HouseImpl::DoStream() {
    asm volatile(
        ".long 0x9421FFE0\n"
        ".long 0x7C0802A6\n"
        ".long 0xBF810010\n"
        ".long 0x90010024\n"
        ".long 0x7C9F2378\n"
        ".long 0x7CBE2B78\n"
        ".long 0x38830018\n"
        ".long 0x7FE3FB78\n"
        ".long 0x4807790D\n"
        ".long 0x2C1E0059\n"
        ".long 0x41810058\n"
        ".long 0x3B810008\n"
        ".long 0x3BC00005\n"
        ".long 0x7F9DE378\n"
        ".long 0x7FE3FB78\n"
        ".long 0x7FA4EB78\n"
        ".long 0x38A00001\n"
        ".long 0x48077439\n"
        ".long 0x7FE3FB78\n"
        ".long 0x7FA4EB78\n"
        ".long 0x38A00001\n"
        ".long 0x48077429\n"
        ".long 0x37DEFFFF\n"
        ".long 0x4082FFDC\n"
        ".long 0x7FE3FB78\n"
        ".long 0x7F84E378\n"
        ".long 0x38A00001\n"
        ".long 0x48077411\n"
        ".long 0x7FE3FB78\n"
        ".long 0x7F84E378\n"
        ".long 0x38A00001\n"
        ".long 0x48077401\n"
        ".long 0x80010024\n"
        ".long 0x7C0803A6\n"
        ".long 0xBB810010\n"
        ".long 0x38210020\n"
        ".long 0x4E800020\n"
    );
}
