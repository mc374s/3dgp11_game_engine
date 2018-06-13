#include "render_target.hlsli"

VS_OUT main(float4 pos : POSITION, float4 color : COLOR, float2 texcoord : TEXCOORD, float4 normal : NORMAL)
{
	VS_OUT vout;
	//vout.pos = pos;
	//vout.color = color;

	vout.pos = mul(pos, worldViewProjection);

	normal.w = 0;
	float4 N = normalize(mul(normal, world));
	float4 L = normalize(lightDirection);
	
	float alpha = color.a;
	vout.color = color * max(0, -dot(L, N));
	vout.color.a = alpha;
	vout.texcoord = texcoord;

	return vout;
}

