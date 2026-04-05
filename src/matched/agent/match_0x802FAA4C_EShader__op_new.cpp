/* EShader::operator new(unsigned int) at 0x802FAA4C (48B) */
// FLAGS: -fno-elide-constructors

extern char g_heap48new[256];
extern void *heapAlloc48(void *, unsigned int, int);

void *EShader_op_new(unsigned int size) {
    return heapAlloc48(g_heap48new, size, 8);
}
