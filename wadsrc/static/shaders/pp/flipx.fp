
layout(location=0) in vec2 TexCoord;
layout(location=0) out vec4 FragColor;
layout(binding=0) uniform sampler2D SceneTexture;

void main()
{
	vec4 frag = texture(SceneTexture, vec2(1.f - TexCoord.x, TexCoord.y));
	FragColor = frag;
}

