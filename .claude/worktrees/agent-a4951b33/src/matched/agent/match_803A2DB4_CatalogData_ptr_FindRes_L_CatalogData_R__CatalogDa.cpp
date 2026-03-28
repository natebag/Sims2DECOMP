// 0x803A2DB4 (96 bytes)
// CatalogData * FindRes<CatalogData>(CatalogData *, CatalogData *, int)

__attribute__((naked))
void CatalogData * FindRes<CatalogData>(CatalogData *, CatalogData *, int) {
    asm volatile(".long 0x7C6B1B78\n.long 0x7C0B2050\n.long 0x7C092671\n.long 0x4081001C\n.long 0x2C090001\n.long 0x4082001C\n.long 0x800B0000\n.long 0x7D635B78\n.long 0x7C002800\n.long 0x4D820020\n.long 0x38600000\n.long 0x4E800020\n.long 0x54000FFE\n.long 0x7C090214\n.long 0x54001836\n.long 0x7D2B002E\n.long 0x7C6B0214\n.long 0x7C092851\n.long 0x4D820020\n.long 0x4081000C\n.long 0x39630010\n.long 0x4BFFFFB0\n.long 0x7C641B78\n.long 0x4BFFFFA8");
}
