// Copyright 2020-2024 The Defold Foundation
// Copyright 2014-2020 King
// Copyright 2009-2014 Ragnar Svensson, Christian Murray
// Licensed under the Defold License version 1.0 (the "License"); you may not use
// this file except in compliance with the License.
//
// You may obtain a copy of the License, together with FAQs at
// https://www.defold.com/license
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef DM_DEFOLD_RENDER_H
#define DM_DEFOLD_RENDER_H

#include "defold_graphics.h"

#include <dmsdk/render/render.h>

namespace dmRender
{
    const dmVMath::Matrix4& GetViewMatrix(HRenderContext render_context);
    const dmVMath::Matrix4& GetViewProjectionMatrix(HRenderContext render_context);
    HMaterial               NewMaterial(HRenderContext render_context, dmGraphics::HVertexProgram vertex_program, dmGraphics::HFragmentProgram fragment_program);
    void                    SetMaterialTags(HMaterial material, uint32_t tag_count, const dmhash_t* tags);
    bool                    SetMaterialSampler(HMaterial material, dmhash_t name_hash, uint32_t unit, dmGraphics::TextureWrap u_wrap, dmGraphics::TextureWrap v_wrap, dmGraphics::TextureFilter min_filter, dmGraphics::TextureFilter mag_filter, float max_anisotropy);
}

#endif
