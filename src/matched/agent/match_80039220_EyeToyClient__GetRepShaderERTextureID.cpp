extern char g_repShaders2[];
struct TexObj { char pad[8]; int m_texID; };
struct ShaderData { char pad[32]; TexObj* m_texObj; };
struct InnerData { char pad[4]; ShaderData* m_shaderData; };
struct RepEntry { InnerData* m_inner; char pad[8]; };
int EyeToyClient_GetRepShaderERTextureID(int idx) {
    RepEntry* entries = (RepEntry*)g_repShaders2;
    InnerData* inner = entries[idx].m_inner;
    ShaderData* sd = inner->m_shaderData;
    TexObj* tex = sd->m_texObj;
    return tex->m_texID;
}
