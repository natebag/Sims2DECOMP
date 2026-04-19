/* ENgcRenderer::Flush(ENgcRendCommand*) at 0x8033ECB8 (32B) */
// 0x8033ECB8 (32 bytes)
extern void GXDrawDone();
class ENgcRendCommand;
class ENgcRenderer {
public:
    void Flush(ENgcRendCommand* cmd);
};
void ENgcRenderer::Flush(ENgcRendCommand*) {
    GXDrawDone();
}
