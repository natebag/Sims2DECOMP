/* 0x80053DA4 (12 bytes) - ISimsObjectModel::GetDynamic(void) */
class ISimsObjectModel {
public:
    char pad[0x32C];
    unsigned int m_field_32C;
    int GetDynamic(void);
};

int ISimsObjectModel::GetDynamic(void) {
    return (m_field_32C >> 6) & 1;
}
