// 0x803122FC (8 bytes) - EResource::operator new(unsigned int, void *)
// Disassembly:
//   803122FC: or r3, r4, r4   (mr r3, r4)
//   80312300: blr

typedef unsigned int size_t;

void* operator_new_EResource(size_t size, void* ptr) {
    return ptr;
}
