struct EString { void* m_data; };
extern "C" void removeDriveLetter(void* data, void* sameData);
void EString_RemoveDriveLetter(EString* self) {
    void* d = self->m_data;
    removeDriveLetter(d, d);
}
