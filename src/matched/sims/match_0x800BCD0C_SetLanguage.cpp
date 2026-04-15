/* SetLanguage(short*, char) - 0x800BCD0C (20 bytes) */
void SetLanguage(short* p, int lang);
void SetLanguage(short* p, int lang) {
    int lo = ((unsigned char*)p)[1];
    *p = (short)(lo | (lang << 8));
}
