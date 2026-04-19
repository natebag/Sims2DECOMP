// 0x800A00B8 (80B) basic_string_ref2::delete_ptr()
// If size != 0, free data via allocator, then clear data+size.

class string_ref_b;
extern void Free_srb(void*, char*);

class string_ref_b {
public:
    char* data;
    int unk4;
    int size;
    void delete_ptr();
    void* GetAllocator();
};

void string_ref_b::delete_ptr() {
    if (size != 0) {
        char* ptr = data;
        Free_srb(GetAllocator(), ptr);
        size = 0;
        data = 0;
    }
}
