typedef unsigned char u8;

extern char* getCorrectId(u8* self, u8* prop);
extern int someFunc(const char* a, const char* b);
extern char g_someString[];

int SAnimator2_PreloadDress(u8* self, u8* prop) {
    char* id = getCorrectId(self, prop);
    if (id == 0) {
        return 0;
    }
    if (someFunc(g_someString, id) == 0) {
        return 0;
    }
    return 1;
}
