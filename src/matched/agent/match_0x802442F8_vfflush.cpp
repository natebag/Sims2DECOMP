struct FILE_s {
    char pad[0x0E];
    short m_fd;
};

extern int vfflush_inner(int fd, int a, int b, int c);

int vfflush_func(FILE_s* fp) {
    return vfflush_inner(fp->m_fd, 0, 0, 2);
}
