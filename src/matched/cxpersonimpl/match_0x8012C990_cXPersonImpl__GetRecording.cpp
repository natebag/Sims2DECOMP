// 0x8012C990 cXPersonImpl::GetRecording (8B)

struct cXPerson_GetRecording {
    char pad[0x430];
    int m_val;
    int GetRecording();
};

int cXPerson_GetRecording::GetRecording() {
    return m_val;
}
