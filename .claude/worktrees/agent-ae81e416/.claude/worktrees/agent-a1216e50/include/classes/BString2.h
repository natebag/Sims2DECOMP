#ifndef BSTRING2_H
#define BSTRING2_H

#include "types.h"

// BString2 - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 187 methods

class BString2 {
public:
    // Constructors / Destructors
    BString2(unsigned wchar_t *)  // 0x801F8B94
    BString2(void)  // 0x801F8878
    BString2(BString2 &, unsigned int, unsigned int)  // 0x801F8940
    BString2(unsigned int, BString2::capacity)  // 0x801F88C4
    BString2(unsigned wchar_t *, unsigned int, unsigned int)  // 0x801F8A70
    BString2(unsigned wchar_t *, unsigned int)  // 0x801F8B18
    BString2(wchar_t, unsigned int)  // 0x801F8C08
    ~BString2(void);  // 0x801F8C90

    // Methods
    void wchar_str(void);  // 0x80095C5C (68B)
    void remove(unsigned int, unsigned int);  // 0x800A7E18 (84B)
    void operator=(unsigned wchar_t *);  // 0x801F8DD4 (88B)
    void c_str(void);  // 0x801FAB9C (100B)
    void find(wchar_t, unsigned int);  // 0x801FB0EC (204B)
    void length(void);  // 0x801FC720 (48B)
    void get_at(unsigned int);  // 0x801F60BC (120B)
    void replace(unsigned int, unsigned int, wchar_t, unsigned int);  // 0x801FA328 (1528B)
    void assignDebug(char *);  // 0x801FC780 (180B)
    void append(BString2 &, unsigned int, unsigned int);  // 0x801F919C (200B)
    void operator=(BString2 &);  // 0x801F8D00 (212B)
    void substr(unsigned int, unsigned int);  // 0x801FBBA4 (244B)
    void erase(unsigned int, unsigned int);  // 0x801F9E04 (704B)
    void operator[](unsigned int);  // 0x801FAAA0 (252B)
    void find(unsigned wchar_t *, unsigned int);  // 0x801FB088 (100B)
    void assign(unsigned wchar_t *);  // 0x801F9688 (88B)
    void append(unsigned wchar_t *, unsigned int);  // 0x801F9264 (80B)
    void append(unsigned wchar_t *);  // 0x801F92B4 (88B)
    void assign(wchar_t, unsigned int);  // 0x801F96E0 (396B)
    void replace(unsigned int, unsigned int, unsigned wchar_t *);  // 0x801FA280 (168B)
    void delete_ref(void);  // 0x801F5FC0 (108B)
    void ref_count(void);  // 0x801F602C (48B)
    void point(void);  // 0x801F605C (48B)
    void len(void);  // 0x801F608C (48B)
    void data(void);  // 0x801FCBE4 (96B)
    void compare(BString2 &, unsigned int, unsigned int);  // 0x801FBC98 (184B)
    void compare(unsigned wchar_t *, unsigned int);  // 0x801FBDD8 (124B)
    void compare(wchar_t, unsigned int, unsigned int);  // 0x801FBE54 (468B)
    void eos(void);  // 0x801F72B8 (60B)
    void assign_str(unsigned wchar_t *, unsigned int);  // 0x801F72F4 (352B)
    void reserve(void);  // 0x801FC750 (48B)
    void append_str(unsigned wchar_t *, unsigned int);  // 0x801F7454 (452B)
    void insert_str(unsigned int, unsigned wchar_t *, unsigned int);  // 0x801F7618 (852B)
    void replace_str(unsigned int, unsigned int, unsigned wchar_t *, unsigned int);  // 0x801F796C (1120B)
    void compare_str(unsigned int, unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F7DCC (304B)
    void find_str(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F7EFC (504B)
    void rfind_str(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F80F4 (556B)
    void rfind(wchar_t, unsigned int);  // 0x801FB2E8 (312B)
    void find_first_of_str(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F8320 (328B)
    void find_last_of_str(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F8468 (368B)
    void find_first_not_of_str(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F85D8 (296B)
    void find_last_not_of_str(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801F8700 (376B)
    void operator=(wchar_t);  // 0x801F8E2C (272B)
    void operator+=(BString2 &);  // 0x801F8F3C (100B)
    void operator+=(unsigned wchar_t *);  // 0x801F8FA0 (88B)
    void operator+=(wchar_t);  // 0x801F8FF8 (420B)
    void append(wchar_t, unsigned int);  // 0x801F930C (520B)
    void assign(BString2 &, unsigned int, unsigned int);  // 0x801F9514 (292B)
    void assign(unsigned wchar_t *, unsigned int);  // 0x801F9638 (80B)
    void insert(unsigned int, BString2 &, unsigned int, unsigned int);  // 0x801F986C (212B)
    void insert(unsigned int, unsigned wchar_t *, unsigned int);  // 0x801F9940 (88B)
    void insert(unsigned int, unsigned wchar_t *);  // 0x801F9998 (96B)
    void insert(unsigned int, wchar_t, unsigned int);  // 0x801F99F8 (1036B)
    void replace(unsigned int, unsigned int, BString2 &, unsigned int, unsigned int);  // 0x801FA0C4 (284B)
    void replace(unsigned int, unsigned int, unsigned wchar_t *, unsigned int);  // 0x801FA1E0 (160B)
    void put_at(unsigned int, wchar_t);  // 0x801FA920 (384B)
    void resize(unsigned int, wchar_t);  // 0x801FAC00 (448B)
    void resize(unsigned int);  // 0x801FADC0 (76B)
    void reserve(unsigned int);  // 0x801FAE0C (204B)
    void copy(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FAED8 (228B)
    void find(BString2 &, unsigned int);  // 0x801FAFBC (112B)
    void find(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FB02C (92B)
    void rfind(BString2 &, unsigned int);  // 0x801FB1B8 (112B)
    void rfind(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FB228 (92B)
    void rfind(unsigned wchar_t *, unsigned int);  // 0x801FB284 (100B)
    void find_first_of(BString2 &, unsigned int);  // 0x801FB420 (112B)
    void find_first_of(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FB490 (92B)
    void find_first_of(unsigned wchar_t *, unsigned int);  // 0x801FB4EC (100B)
    void find_first_of(wchar_t, unsigned int);  // 0x801FB550 (96B)
    void find_last_of(BString2 &, unsigned int);  // 0x801FB5B0 (112B)
    void find_last_of(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FB620 (92B)
    void find_last_of(unsigned wchar_t *, unsigned int);  // 0x801FB67C (100B)
    void find_last_of(wchar_t, unsigned int);  // 0x801FB6E0 (96B)
    void find_first_not_of(BString2 &, unsigned int);  // 0x801FB740 (112B)
    void find_first_not_of(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FB7B0 (92B)
    void find_first_not_of(unsigned wchar_t *, unsigned int);  // 0x801FB80C (100B)
    void find_first_not_of(wchar_t, unsigned int);  // 0x801FB870 (204B)
    void find_last_not_of(BString2 &, unsigned int);  // 0x801FB93C (112B)
    void find_last_not_of(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FB9AC (92B)
    void find_last_not_of(unsigned wchar_t *, unsigned int);  // 0x801FBA08 (100B)
    void find_last_not_of(wchar_t, unsigned int);  // 0x801FBA6C (312B)
    void compare(unsigned wchar_t *, unsigned int, unsigned int);  // 0x801FBD50 (136B)
    void operator==(BString2 &);  // 0x801FC604 (96B)
    void operator!=(BString2 &);  // 0x801FC664 (100B)
    void operator<(BString2 &);  // 0x801FC6C8 (88B)
    void empty(void);  // 0x80232A4C (80B)
    void size(void);  // 0x8054EABC (68B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [R/W] (BString2, append, append_str, ...)
    u16 m_field_002;  // 0x002 [W] (operator+=, operator=)
    u32 m_field_004;  // 0x004 [W] (erase, insert, insert_str, ...)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R] (delete_ref)
};

#endif // BSTRING2_H
