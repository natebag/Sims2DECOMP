typedef unsigned short wchar_t;

int UCS2ToUTF8(wchar_t* src, int srcLen, char* dst);

int CUCS2ToUTF8(wchar_t* src, int srcLen, char* dst) {
    return UCS2ToUTF8(src, srcLen, dst);
}
