/* QuickResFile::ValidFile(void) - 0x80132B70 - 24 bytes */
/* lwz r0, 8(r3); li r3, 1; cmpwi r0, 0; bnelr; li r3, 0; blr */

class QuickResFile {
public:
    char _pad[0x8];
    int m_fileData;

    int ValidFile(void);
};

int QuickResFile::ValidFile(void) {
    return m_fileData != 0;
}
