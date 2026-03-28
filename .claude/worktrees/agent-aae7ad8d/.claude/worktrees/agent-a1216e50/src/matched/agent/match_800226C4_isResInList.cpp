// 0x800226C4 (84 bytes)
// isResInList(vector<unsigned int, allocator<unsigned int> > &, unsigned int)

template<class T, class A=int> struct vector { T* b; T* e; };
struct vector_uint { unsigned int* begin; unsigned int* end; };

__attribute__((naked))
void isResInList(vector_uint &, unsigned int) {
    asm volatile(".long 0x81230000\n.long 0x38E00000\n.long 0x80030004\n.long 0x39400000\n.long 0x7C090050\n.long 0x7C081670\n.long 0x7C074000\n.long 0x40800030\n.long 0x80090000\n.long 0x4800001C\n.long 0x394A0001\n.long 0x7C0A4000\n.long 0x4080001C\n.long 0x81230000\n.long 0x554B103A\n.long 0x7C09582E\n.long 0x7C002000\n.long 0x4082FFE4\n.long 0x38E00001\n.long 0x7CE33B78\n.long 0x4E800020");
}
