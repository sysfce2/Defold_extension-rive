// Copyright 2021 The Defold Foundation
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

#ifndef DM_RES_RIVE_SCENE_H
#define DM_RES_RIVE_SCENE_H

#include <dmsdk/gamesys/resources/res_textureset.h>

#include "defold/renderer.h"

#include "rive_ddf.h" // generated from the rive_ddf.proto

namespace dmRive
{
    struct Atlas;
    struct RiveSceneData;

    struct RiveSceneResource
    {
        dmRiveDDF::RiveSceneDesc*           m_DDF;
        dmGameSystem::TextureSetResource*   m_TextureSet;   // The atlas
        RiveSceneData*                      m_Scene;
        Atlas*                              m_Atlas;
        ShaderResources*                    m_Shaders;
    };
}

#endif // DM_RES_RIVE_SCENE_H
