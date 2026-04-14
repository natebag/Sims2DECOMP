/* basic_string_ref::~basic_string_ref(void) - 0x8009CA98 (64 bytes) */

struct basic_string_ref {
    void delete_ptr();
    ~basic_string_ref();
};

basic_string_ref::~basic_string_ref()
{
    delete_ptr();
}
