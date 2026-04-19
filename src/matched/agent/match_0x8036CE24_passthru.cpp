/* close at 0x8036CE24 (32B) */
// 0x8036CE24 (32 bytes)
extern int PCclose(int fd);
int close(int fd) {
    return PCclose(fd);
}
