extern unsigned int strlen(const char *s);
extern char *strcpy(char *dest, const char *src);

struct BehPrintParams {
    char m_filename[513];
    void SetFilename(char *filename);
};

void BehPrintParams::SetFilename(char *filename) {
    if (strlen(filename) <= 512U) {
        strcpy(m_filename, filename);
    }
}
