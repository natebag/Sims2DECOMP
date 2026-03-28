extern int __vt_NghResFileReader[];

int NghResFileReaderFunc(void *);

struct NghResFileReader {
    char pad_00[0x04];
    int* m_vtable;

    int ReadBothInit();
};

int NghResFileReader::ReadBothInit() {
    m_vtable = __vt_NghResFileReader;
    return NghResFileReaderFunc(this);
}
