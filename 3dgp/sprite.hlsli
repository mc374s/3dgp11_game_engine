struct VS_OUT
{
	float4 pos : SV_POSITION;
	float4 color : COLOR;
	// UNIT.04
	float2 texcoord : TEXCOORD;
};

cbuffer PROJECTION_CBUFFER : register(b0)
{
	row_major matrix world;
	row_major matrix view;
	row_major matrix projection;
	row_major matrix worldViewProjection;
	float4 materialColor;
	float4 lightDirection;
};