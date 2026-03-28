/* PlumbBob::PlumbBobOrderTableCallback(ELevelDrawData &, EOrderTableData *) at 0x800597EC (76B) */

struct ERC;
struct ELevelDrawData;
struct EOrderTableData;

void PlumbBob_DrawShadow(ELevelDrawData *drawData, ERC *erc);

struct PlumbBob {
    char pad_00[0x98];
    ERC *m_erc;
    char pad_9C[0x0C];
    int m_fieldA8;
    int m_fieldAC;
    int m_fieldB0;
    int m_fieldB4;
    int m_fieldB8;

    void PlumbBobOrderTableCallback(ELevelDrawData *drawData, EOrderTableData *orderData);
};

void PlumbBob::PlumbBobOrderTableCallback(ELevelDrawData *drawData, EOrderTableData *orderData) {
    PlumbBob_DrawShadow(drawData, m_erc);
    m_fieldA8 = 0;
    m_fieldAC = 0;
    m_fieldB4 = 0;
    m_fieldB0 = 0;
    m_fieldB8 = 0;
}
