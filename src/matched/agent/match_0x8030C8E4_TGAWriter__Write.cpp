struct TDF_INFO;

struct TGAWriter {
    int WriteTGA();
    int WriteTDF(TDF_INFO *info);
    int WriteSDF();
    int Write();
};

int TGAWriter::Write() {
    if (WriteTGA() == 0) return 0;
    if (WriteTDF(0) == 0) return 0;
    if (WriteSDF() == 0) return 0;
    return 1;
}
