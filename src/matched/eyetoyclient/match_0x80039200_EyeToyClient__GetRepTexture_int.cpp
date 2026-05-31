// 0x80039200 EyeToyClient::GetRepTexture(int) (32 B)

struct RepShader {
    char pad_0000[0x14];
    int m_textureId;
};

struct RepNode2 {
    char pad_0000[0x20];
    RepShader* m_shader;
};

struct RepNode1 {
    char pad_0000[0x4];
    RepNode2* m_node2;
};

struct RepEntry {
    RepNode1* m_node1;
    char pad_0004[0x8];
};

extern RepEntry g_eyeToyReps[];

struct EyeToyClient {
    static int GetRepTexture(int index);
};

int EyeToyClient::GetRepTexture(int index) {
    RepNode1* n1 = *(RepNode1**)(index * 12 + (char*)g_eyeToyReps);
    return n1->m_node2->m_shader->m_textureId;
}
