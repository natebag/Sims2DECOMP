/* ENgcRenderer::NgcTexInvalidateAll(EDLEntry*) at 0x803477AC (32B) */
// 0x803477AC (32 bytes)
extern void GXInvalidateTexAll();
class EDLEntry;
class ENgcRenderer {
public:
    void NgcTexInvalidateAll(EDLEntry* entry);
};
void ENgcRenderer::NgcTexInvalidateAll(EDLEntry*) {
    GXInvalidateTexAll();
}
