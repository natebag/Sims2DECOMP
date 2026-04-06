// 0x803B50F8 _String_base<wchar_t>::_M_throw_length_error (28b)
extern "C" int puts(const char*);
extern "C" void abort();

template <class charT, class Alloc>
class _String_base {
public:
    void _M_throw_length_error() const;
};

template <class charT, class Alloc>
void _String_base<charT, Alloc>::_M_throw_length_error() const {
    puts("basic_string length error");
    abort();
}

class allocator_wchar {};

template void _String_base<short, allocator_wchar>::_M_throw_length_error() const;
