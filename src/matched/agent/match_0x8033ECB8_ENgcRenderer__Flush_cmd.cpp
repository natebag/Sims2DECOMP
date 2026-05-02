// ENgcRenderer::Flush(ENgcRendCommand *) at 0x8033ECB8 (32B)
// DOL:
//   stwu r1,-8(r1); mflr r0; stw r0,12(r1)
//   bl GXDrawDone
//   epilogue

extern "C" void GXDrawDone();

struct ENgcRenderer_FLU2 {
    void Flush(void* cmd);
};

void ENgcRenderer_FLU2::Flush(void* /*cmd*/) {
    GXDrawDone();
}
