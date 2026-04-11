// 0x8009D9D4 BString::operator= (152b)
// FLAGS: -fno-elide-constructors

class BString {
public:
    struct basic_string_ref {
        void* ptr;
        int field4;
        int field8;
        int ref_count;
    };
    basic_string_ref* m_ref;
    
    void delete_ref();
    void reserve(int);
};

extern void* BS_alloc_mem(int size, int flags);
extern void BS_copy_mem(void* dst, void* src, int len);

BString* BString_operator_assign(BString* this_ptr, BString* other) {
    if (this_ptr == other) {
        return this_ptr;
    }
    
    // Delete current reference
    this_ptr->delete_ref();
    
    if (other->m_ref) {
        // Share reference
        this_ptr->m_ref = other->m_ref;
        // Increment ref count
        this_ptr->m_ref->ref_count++;
    } else {
        // Allocate new ref
        this_ptr->m_ref = (BString::basic_string_ref*)BS_alloc_mem(16, 0);
        this_ptr->m_ref->ref_count = 1;
    }
    
    return this_ptr;
}

void BString::delete_ref() {
    if (m_ref) {
        m_ref->ref_count--;
        if (m_ref->ref_count == 0) {
            // Free the ref
        }
    }
}
