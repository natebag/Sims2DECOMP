// 0x8006CB98 (48B) ScrollingTextBox::SetTextColor(EVec4&)
// if (m_pColor != 0) copy 4 floats from ref to m_pColor.
// Interleaved lfs/stfs per component.

struct EVec4_TC { float x, y, z, w; };

struct ScrollingTextBox_TC {
    char _pad[36];
    EVec4_TC* m_pColor;  // +0x24
    void SetTextColor(EVec4_TC& color);
};

void ScrollingTextBox_TC::SetTextColor(EVec4_TC& color) {
    EVec4_TC* dst = m_pColor;
    if (dst == 0) {
        return;
    }
    dst->x = color.x;
    dst->y = color.y;
    dst->z = color.z;
    dst->w = color.w;
}
