#ifndef BSTRING_H
#define BSTRING_H

#include "types.h"

// BString - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 184 methods

class BString {
public:
    // Constructors / Destructors
    BString(void)  // 0x801F1C8C
    BString(unsigned int, BString::capacity)  // 0x801F1CD8
    BString(BString &, unsigned int, unsigned int)  // 0x801F1D54
    BString(char *, unsigned int, unsigned int)  // 0x801F1E84
    BString(char *, unsigned int)  // 0x801F1F2C
    BString(char *)  // 0x801F1FA8
    BString(char, unsigned int)  // 0x801F201C
    ~BString(void);  // 0x801F20A4

    // Methods
    void c_str(void);  // 0x801F3D90 (100B)
    void delete_ref(void);  // 0x801EF59C (108B)
    void ref_count(void);  // 0x801EF608 (48B)
    void data(void);  // 0x801EF638 (96B)
    void length(void);  // 0x801F588C (48B)
    void point(void);  // 0x801EF698 (48B)
    void len(void);  // 0x801EF6C8 (48B)
    void get_at(unsigned int);  // 0x801EF6F8 (112B)
    void operator[](unsigned int);  // 0x801EF768 (120B)
    void compare(BString &, unsigned int, unsigned int);  // 0x801F4E4C (184B)
    void compare(char *, unsigned int);  // 0x801F4F8C (124B)
    void compare(char, unsigned int, unsigned int);  // 0x801F5008 (436B)
    void eos(void);  // 0x801F08A0 (64B)
    void assign_str(char *, unsigned int);  // 0x801F08E0 (344B)
    void reserve(void);  // 0x801F58BC (48B)
    void append_str(char *, unsigned int);  // 0x801F0A38 (428B)
    void insert_str(unsigned int, char *, unsigned int);  // 0x801F0BE4 (748B)
    void replace_str(unsigned int, unsigned int, char *, unsigned int);  // 0x801F0ED0 (952B)
    void compare_str(unsigned int, char *, unsigned int, unsigned int);  // 0x801F1288 (296B)
    void find_str(char *, unsigned int, unsigned int);  // 0x801F13B0 (456B)
    void find(char, unsigned int);  // 0x801F42C8 (196B)
    void rfind_str(char *, unsigned int, unsigned int);  // 0x801F1578 (508B)
    void rfind(char, unsigned int);  // 0x801F44BC (304B)
    void find_first_of_str(char *, unsigned int, unsigned int);  // 0x801F1774 (312B)
    void find_last_of_str(char *, unsigned int, unsigned int);  // 0x801F18AC (352B)
    void find_first_not_of_str(char *, unsigned int, unsigned int);  // 0x801F1A0C (280B)
    void find_last_not_of_str(char *, unsigned int, unsigned int);  // 0x801F1B24 (360B)
    void operator=(BString &);  // 0x801F20FC (212B)
    void operator=(char *);  // 0x801F21D0 (88B)
    void operator=(char);  // 0x801F2228 (272B)
    void operator+=(BString &);  // 0x801F2338 (100B)
    void operator+=(char *);  // 0x801F239C (88B)
    void operator+=(char);  // 0x801F23F4 (404B)
    void append(BString &, unsigned int, unsigned int);  // 0x801F2588 (192B)
    void append(char *, unsigned int);  // 0x801F2648 (80B)
    void append(char *);  // 0x801F2698 (88B)
    void append(char, unsigned int);  // 0x801F26F0 (488B)
    void assign(BString &, unsigned int, unsigned int);  // 0x801F28D8 (284B)
    void assign(char *, unsigned int);  // 0x801F29F4 (80B)
    void assign(char *);  // 0x801F2A44 (88B)
    void assign(char, unsigned int);  // 0x801F2A9C (380B)
    void insert(unsigned int, BString &, unsigned int, unsigned int);  // 0x801F2C18 (204B)
    void insert(unsigned int, char *, unsigned int);  // 0x801F2CE4 (88B)
    void insert(unsigned int, char *);  // 0x801F2D3C (96B)
    void insert(unsigned int, char, unsigned int);  // 0x801F2D9C (908B)
    void erase(unsigned int, unsigned int);  // 0x801F3128 (648B)
    void replace(unsigned int, unsigned int, BString &, unsigned int, unsigned int);  // 0x801F33B0 (276B)
    void replace(unsigned int, unsigned int, char *, unsigned int);  // 0x801F34C4 (160B)
    void replace(unsigned int, unsigned int, char *);  // 0x801F3564 (168B)
    void replace(unsigned int, unsigned int, char, unsigned int);  // 0x801F360C (1304B)
    void put_at(unsigned int, char);  // 0x801F3B24 (376B)
    void resize(unsigned int, char);  // 0x801F3DF4 (432B)
    void resize(unsigned int);  // 0x801F3FA4 (76B)
    void reserve(unsigned int);  // 0x801F3FF0 (204B)
    void copy(char *, unsigned int, unsigned int);  // 0x801F40BC (220B)
    void find(BString &, unsigned int);  // 0x801F4198 (112B)
    void find(char *, unsigned int, unsigned int);  // 0x801F4208 (92B)
    void find(char *, unsigned int);  // 0x801F4264 (100B)
    void rfind(BString &, unsigned int);  // 0x801F438C (112B)
    void rfind(char *, unsigned int, unsigned int);  // 0x801F43FC (92B)
    void rfind(char *, unsigned int);  // 0x801F4458 (100B)
    void find_first_of(BString &, unsigned int);  // 0x801F45EC (112B)
    void find_first_of(char *, unsigned int, unsigned int);  // 0x801F465C (92B)
    void find_first_of(char *, unsigned int);  // 0x801F46B8 (100B)
    void find_first_of(char, unsigned int);  // 0x801F471C (96B)
    void find_last_of(BString &, unsigned int);  // 0x801F477C (112B)
    void find_last_of(char *, unsigned int, unsigned int);  // 0x801F47EC (92B)
    void find_last_of(char *, unsigned int);  // 0x801F4848 (100B)
    void find_last_of(char, unsigned int);  // 0x801F48AC (96B)
    void find_first_not_of(BString &, unsigned int);  // 0x801F490C (112B)
    void find_first_not_of(char *, unsigned int, unsigned int);  // 0x801F497C (92B)
    void find_first_not_of(char *, unsigned int);  // 0x801F49D8 (100B)
    void find_first_not_of(char, unsigned int);  // 0x801F4A3C (196B)
    void find_last_not_of(BString &, unsigned int);  // 0x801F4B00 (112B)
    void find_last_not_of(char *, unsigned int, unsigned int);  // 0x801F4B70 (92B)
    void find_last_not_of(char *, unsigned int);  // 0x801F4BCC (100B)
    void find_last_not_of(char, unsigned int);  // 0x801F4C30 (304B)
    void substr(unsigned int, unsigned int);  // 0x801F4D60 (236B)
    void compare(char *, unsigned int, unsigned int);  // 0x801F4F04 (136B)
    void operator==(BString &);  // 0x801F5770 (96B)
    void operator!=(BString &);  // 0x801F57D0 (100B)
    void operator<(BString &);  // 0x801F5834 (88B)
    void assignDebug(unsigned wchar_t *);  // 0x801F58EC (172B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R/W] (BString, append, append_str, ...)
    u8 m_field_001;  // 0x001 [W] (operator+=, operator=)
    u8 _pad_002[2];  // 0x002
    u32 m_field_004;  // 0x004 [W] (erase, insert, insert_str, ...)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R] (delete_ref)
};

#endif // BSTRING_H
