/* Swizzle2(void *) at 0x800A7E64 (20B) */

void Swizzle2(void* ptr) {
    unsigned char* p = (unsigned char*)ptr;
    unsigned char tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
}
