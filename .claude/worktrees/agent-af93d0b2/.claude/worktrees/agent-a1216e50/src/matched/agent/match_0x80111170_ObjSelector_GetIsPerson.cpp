/* ObjSelector::GetIsPerson(void) - 0x80111170 - 24 bytes */

struct CatalogResource {
    char _pad[0x12];
    short m_type;
};

class ObjSelector {
public:
    char _pad[0x38];
    CatalogResource* m_catalogResource;

    int GetIsPerson(void);
};

int ObjSelector::GetIsPerson(void) {
    return m_catalogResource->m_type == 2;
}
