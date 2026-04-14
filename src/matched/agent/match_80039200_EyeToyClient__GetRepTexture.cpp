extern char g_repShaders[];
struct TexObj { char pad[20]; void* m_texture; };
struct ShaderData { char pad[32]; TexObj* m_texObj; };
struct InnerData { char pad[4]; ShaderData* m_shaderData; };
struct RepEntry { InnerData* m_inner; char pad[8]; };
void* EyeToyClient_GetRepTexture(int idx) {
    RepEntry* entries = (RepEntry*)g_repShaders;
    InnerData* inner = entries[idx].m_inner;
    ShaderData* sd = inner->m_shaderData;
    TexObj* tex = sd->m_texObj;
    return tex->m_texture;
}
