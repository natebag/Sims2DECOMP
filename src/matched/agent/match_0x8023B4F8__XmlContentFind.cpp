// 0x8023B4F8 _XmlContentFind(unsigned char*) (76B)

extern unsigned char* _XmlContentFind(unsigned char* p);

unsigned char* _XmlContentFind(unsigned char* p) {
    if (p == 0) return 0;
    if (*p != '<') return 0;
    do {
        ++p;
        if (*p == 0) return p;
    } while (*p != '>');
    unsigned char* result = 0;
    if (*(p - 1) != '/') {
        result = p + 1;
    }
    return result;
}
