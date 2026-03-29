struct ERShader {
    void SetShaderASyncForState(int state);
    void UpdateWeatherShader(int state);
};

void ERShader::UpdateWeatherShader(int state)
{
    SetShaderASyncForState(state);
}
