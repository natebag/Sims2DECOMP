/* 0x8005f7e0 (76 bytes) - SAnimator2::PreloadDress(PropRef *) */
struct PropRef;
extern char g_strPreloadDress[];
extern "C" int LookupDress(char* str, int id);

class SAnimator2 {
public:
    int getCorrectId(PropRef* prop);
    int PreloadDress(PropRef* prop);
};

int SAnimator2::PreloadDress(PropRef* prop) {
    int id = getCorrectId(prop);
    if (id == 0) return 0;
    int result = LookupDress(g_strPreloadDress, id);
    if (result == 0) return 0;
    return 1;
}
