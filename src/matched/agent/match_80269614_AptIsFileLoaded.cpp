struct AptFile {
    int m_field0;
    int m_field4;
    int m_state;
};

int AptFile_Release(AptFile *);
void AptFile_Delete(AptFile *);

int AptIsFileLoaded(AptFile **pFile) {
    int loaded = 0;
    AptFile *f = *pFile;
    int exists = (f != 0) ? 1 : 0;
    if (exists != 0) {
        if (f->m_state == 4) {
            loaded = 1;
        }
    }
    AptFile *f2 = *pFile;
    if (f2 != 0) {
        if (AptFile_Release(f2) == 0) {
            AptFile_Delete(*pFile);
        }
    }
    return loaded;
}
