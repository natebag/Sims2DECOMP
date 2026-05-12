// 0x802D3534 (48B) EString::Replace(char, char)
// Walks string via lbzu; extsb+cmpw for char-vs-char comparison (signed params);
// cmpwi+beqlr early exit for empty string; do-while body on first non-null char.

struct EString_Repl {
    void* m_data;  // offset 0: char* to actual string
    void Replace(char from, char to);
};

void EString_Repl::Replace(char from, char to) {
    char* ptr = (char*)m_data;
    unsigned char c = (unsigned char)*ptr;
    if (!c) return;
    do {
        if ((char)c == from) *ptr = to;
        c = (unsigned char)*++ptr;
    } while (c);
}
