// 0x803135AC FlashBigFile::FlashBigFile (20b)

struct FlashBigFile {
    int f0;
    int f4;
    FlashBigFile();
};

FlashBigFile::FlashBigFile() {
    FlashBigFile* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
