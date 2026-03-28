/* ActionMenu::MenuItem::ClearMenu(void) at 0x801831B8 (144b) */

extern void operator_delete_array(void*);
extern void DestroyMenuItem(void*, int);
extern void EShader_Release(void*);

struct MenuItem {
    char pad_00[0x4C];
    void* m_name;
    char pad_50[0x04];
    void* m_shader;
    char pad_58[0x04];
    void* m_right;
    void* m_left;

    void ClearMenu();
};

void MenuItem::ClearMenu() {
    if (m_name != 0) {
        operator_delete_array(m_name);
        m_name = 0;
    }
    if (m_left != 0) {
        DestroyMenuItem(m_left, 3);
        m_left = 0;
    }
    if (m_right != 0) {
        DestroyMenuItem(m_right, 3);
        m_right = 0;
    }
    if (m_shader != 0) {
        EShader_Release(m_shader);
        m_shader = 0;
    }
}
