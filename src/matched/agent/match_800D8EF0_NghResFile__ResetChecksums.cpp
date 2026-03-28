/* NghResFile::ResetChecksums(void) - 16 bytes */

static int s_storeChecksum;
static int s_calcChecksum;

struct NghResFile {
    static void ResetChecksums(void);
};

void NghResFile::ResetChecksums(void) {
    s_storeChecksum = 0;
    s_calcChecksum = 0;
}
