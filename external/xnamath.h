#pragma once

#include <DirectXMath.h>
#include <cstdint>

using namespace DirectX;

using XMUBYTEN4 = std::uint32_t;

inline XMVECTOR
XMLoadUByteN4(const XMUBYTEN4* value)
{
    const std::uint32_t packed = *value;
    constexpr float scale = 1.0f / 255.0f;
    return XMVectorSet(
        static_cast<float>((packed >> 0) & 0xff) * scale,
        static_cast<float>((packed >> 8) & 0xff) * scale,
        static_cast<float>((packed >> 16) & 0xff) * scale,
        static_cast<float>((packed >> 24) & 0xff) * scale
    );
}

#ifndef _XMFLOAT3
using _XMFLOAT3 = XMFLOAT3;
#endif

#ifndef _DECLSPEC_ALIGN_16_
#define _DECLSPEC_ALIGN_16_ __declspec(align(16))
#endif

inline float&
XMVectorComponentRef(XMVECTOR& value, unsigned int index)
{
    return reinterpret_cast<float*>(&value)[index];
}

inline XMVECTOR
XMVectorPermuteControl(
    unsigned int i0,
    unsigned int i1,
    unsigned int i2,
    unsigned int i3)
{
    return XMVectorSetInt(i0, i1, i2, i3);
}

inline XMVECTOR
XMVectorPermute(XMVECTOR v0, XMVECTOR v1, XMVECTOR control)
{
    return DirectX::XMVectorPermute(
        v0,
        v1,
        DirectX::XMVectorGetIntX(control),
        DirectX::XMVectorGetIntY(control),
        DirectX::XMVectorGetIntZ(control),
        DirectX::XMVectorGetIntW(control)
    );
}
