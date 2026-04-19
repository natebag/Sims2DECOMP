// 0x8009BF5C (80B) basic_string_ref::delete_ptr()
// If size != 0, free data via allocator, then clear data+size.

class string_ref_a;
extern void Free_sra(void*, char*);

class string_ref_a {
public:
    char* data;
    int unk4;
    int size;
    void delete_ptr();
    void* GetAllocator();
};

void string_ref_a::delete_ptr() {
    if (size != 0) {
        char* ptr = data;
        Free_sra(GetAllocator(), ptr);
        size = 0;
        data = 0;
    }
}
