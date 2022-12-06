#include <string.h> // memcpy
#include <stdlib.h> // realloc

#include <dmsdk/dlib/array.h>
#include <dmsdk/dlib/log.h>
#include <dmsdk/dlib/math.h>
#include <dmsdk/dlib/vmath.h>
#include <dmsdk/render/render.h>

#include <common/vertices.h>

//#include <riverender/rive_render_api.h>

namespace dmRive
{


void ApplyDrawMode(dmRender::RenderObject& ro, dmRive::DrawMode draw_mode, uint8_t clipIndex)
{
    dmRender::StencilTestParams& stencil = ro.m_StencilTestParams;

    ro.m_SetStencilTest = 1;
    stencil.m_ColorBufferMask = 0xf;

    switch(draw_mode)
    {
        case dmRive::DRAW_MODE_CLIP_DECR:
            stencil.m_Ref                = 0x0;
            stencil.m_RefMask            = 0xFF;
            stencil.m_BufferMask         = 0xFF;
            stencil.m_ColorBufferMask    = 0;
            stencil.m_SeparateFaceStates = 0;

            stencil.m_Front = {
                .m_Func = dmGraphics::COMPARE_FUNC_ALWAYS,
                .m_OpSFail  = dmGraphics::STENCIL_OP_KEEP,
                .m_OpDPFail = dmGraphics::STENCIL_OP_KEEP,
                .m_OpDPPass = dmGraphics::STENCIL_OP_DECR_WRAP,
            };

            break;
        case dmRive::DRAW_MODE_CLIP_INCR:
            stencil.m_Ref                = 0x0;
            stencil.m_RefMask            = 0xFF;
            stencil.m_BufferMask         = 0xFF;
            stencil.m_ColorBufferMask    = 0;
            stencil.m_SeparateFaceStates = 0;

            stencil.m_Front = {
                .m_Func = dmGraphics::COMPARE_FUNC_ALWAYS,
                .m_OpSFail  = dmGraphics::STENCIL_OP_KEEP,
                .m_OpDPFail = dmGraphics::STENCIL_OP_KEEP,
                .m_OpDPPass = dmGraphics::STENCIL_OP_INCR_WRAP,
            };
            break;
        case dmRive::DRAW_MODE_DEFAULT:
            stencil.m_Ref          = clipIndex;
            stencil.m_RefMask      = 0xFF;
            stencil.m_BufferMask   = 0x00;
            stencil.m_Front.m_Func = clipIndex == 0 ? dmGraphics::COMPARE_FUNC_ALWAYS : dmGraphics::COMPARE_FUNC_EQUAL;
            break;
        default:
            printf("Draw Mode not supported :(\n");
            break;
    }
}


void CopyVertices(const dmRive::DrawDescriptor& draw_desc, uint32_t vertex_offset, RiveVertex* out_vertices, uint16_t* out_indices)
{
    printf("vertices\n");
    uint32_t vertex_count = draw_desc.m_VerticesCount;
    for (int i = 0; i < vertex_count; ++i)
    {
        rive::Vec2D& vtx = draw_desc.m_Vertices[i];
        out_vertices->x = vtx.x;
        out_vertices->y = vtx.y;
        out_vertices->u = 0.0f;
        out_vertices->v = 0.0f;
        out_vertices++;

        printf("%d / %d: %f %f\n", i, i+vertex_offset, vtx.x, vtx.y);
    }

    printf("indices\n");
    uint32_t indices_count = draw_desc.m_IndicesCount;
    for (int i = 0; i < indices_count; ++i)
    {
        *out_indices = draw_desc.m_Indices[i] + vertex_offset;

        printf("%d / %d: local: %d  global: %d\n", i, indices_count, draw_desc.m_Indices[i], *out_indices);
        out_indices++;
    }
}

} // namespace
