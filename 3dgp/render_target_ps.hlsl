#include "render_target.hlsli"

Texture2D diffuse_map : register(t0);
SamplerState diffuse_map_sampler_state : register(s0);

float4 main(VS_OUT pin) : SV_TARGET
{
	float4 color = diffuse_map.Sample(diffuse_map_sampler_state, pin.texcoord);

	// í èÌ
	color = color*pin.color;
	// îΩì]
	/*color.r = 1 - color.r;
	color.g = 1 - color.g;
	color.b = 1 - color.b;*/
	// íEêF
	/*float gray = (color.r + color.g + color.b) / 3;
	color.r = color.g = color.b = gray;*/
	// êFìhÇË
	/*color.r = pin.color.r;
	color.g = pin.color.g;
	color.b = pin.color.b;*/
	//if (color.g < 0.5 /*&& color.g > 0*/) {
	//	color.a = 0;
	//}
	/*static float dis = 0;
	dis += 0.2;

	if (distance(pin.texcoord, (0.5, 0.5)) < dis) {
	color.a = 0;
	}*/


	/*if (distance(pin.texcoord, inputPos) < inputSize.x)
	{
	color.a = 0;
	}*/

	return color;
}