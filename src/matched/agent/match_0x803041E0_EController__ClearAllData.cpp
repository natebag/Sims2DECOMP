struct EController { char pad[4]; int m_flags; char pad2[0x1F4]; void* m_data; };
extern "C" void clearData(void*, int);
void EController_ClearAllData(EController* self) {
    clearData(self->m_data, (unsigned)self->m_flags >> 1 & 1);
}
