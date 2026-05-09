// 0x800A7FD4 (128B) wcsstr
// Wide-char substring search using wcslen/wcschr/wcsncmp.

extern "C" {
    unsigned int wcslen(const wchar_t* s);
    wchar_t* wcschr(const wchar_t* s, wchar_t c);
    int wcsncmp(const wchar_t* a, const wchar_t* b, unsigned int n);
    
    wchar_t* wcsstr(const wchar_t* haystack, const wchar_t* needle) {
        unsigned int len = wcslen(needle);
        wchar_t first = needle[0];
        if (len == 0) {
            return 0;
        }
        while (1) {
            haystack = wcschr(haystack, first);
            if (!haystack) {
                return 0;
            }
            if (wcsncmp(haystack, needle, len) == 0) {
                return (wchar_t*)haystack;
            }
            haystack++;
        }
    }
}
