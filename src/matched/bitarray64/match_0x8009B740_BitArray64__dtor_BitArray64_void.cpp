void del_BitArray64__dtor_BitArray64_void(void*);
void BitArray64__dtor_BitArray64_void(void* self, int c) { if (c & 1) del_BitArray64__dtor_BitArray64_void(self); }
