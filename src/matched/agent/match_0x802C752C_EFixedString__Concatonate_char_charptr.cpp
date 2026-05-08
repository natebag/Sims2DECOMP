// EFixedString::Concatonate(char, char*) - 0x802C752C (44B)

struct EFixedString;

void EFixedString_Concatonate_charptr_charptr(EFixedString* self, char* str1, char* str2);

void EFixedString_Concatonate_char_charptr(EFixedString* self, char c, char* str) {
    short wc = (short)(c << 8);
    EFixedString_Concatonate_charptr_charptr(self, (char*)&wc, str);
}
