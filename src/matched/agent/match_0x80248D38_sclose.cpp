struct FILE_sc {
    char pad_00[0x0E];
    short m_fd;
    char pad_10[0x4C];
    void* m_closefn;
};

extern int sclose_inner(void* closefn, short fd);

int sclose_func(FILE_sc* fp) {
    short fd = fp->m_fd;
    return sclose_inner(fp->m_closefn, fd);
}
