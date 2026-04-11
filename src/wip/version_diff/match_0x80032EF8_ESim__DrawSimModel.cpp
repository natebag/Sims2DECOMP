// 0x80032EF8 (60 bytes)
/* ESim::DrawSimModel(ERC *, EMat4 *, unsigned int) */

class ERC;
class EIStaticModel;
class EShader;
class EMat4;

struct SimRenderer {
    static void Render(ERC *rc, EIStaticModel **model, EShader *shader, EMat4 *mat, unsigned int flags, bool b);
};

struct ESim_DrawSimModel {
    char pad_63C[0x63C];
    struct ESimModel {
        char pad[0x68];
        EIStaticModel *parts[4];
    } *m_model;

    void DrawSimModel(ERC *rc, EMat4 *mat, unsigned int flags);
};

void ESim_DrawSimModel::DrawSimModel(ERC *rc, EMat4 *mat, unsigned int flags) {
    ESimModel *model = m_model;
    SimRenderer::Render(rc, &model->parts[0], 0, mat, flags, false);
}
