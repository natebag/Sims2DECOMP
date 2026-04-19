/* strtodf at 0x8036E900 (32B) */
// 0x8036E900 (32 bytes)
extern double strtod(const char* s, char** end);
double strtodf(const char* s, char** end) {
    return strtod(s, end);
}
