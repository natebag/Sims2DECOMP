/* basic_string_ref2::~basic_string_ref2(void) - 0x800A0C30 (64 bytes) */

struct basic_string_ref2 {
    void delete_ptr();
    ~basic_string_ref2();
};

basic_string_ref2::~basic_string_ref2()
{
    delete_ptr();
}
