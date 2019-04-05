#pragma once
#include "common.h"

namespace px
{
    namespace render
    {

        struct Aabb
        {
            float m_min[3];
            float m_max[3];
        };

        struct Obb
        {
            float m_mtx[16];
        };

        struct Sphere
        {
            float m_center[3];
            float m_radius;
        };

        struct Primitive
        {
            uint32_t m_start_index;
            uint32_t m_num_indices;
            uint32_t m_start_vertex;
            uint32_t m_num_vertices;

            Sphere  m_sphere;
            Aabb    m_aabb;
            Obb     m_obb;
        };

        typedef tinystl::vector<Primitive>  PrimitiveArray;

        struct Group
        {
            Group();

            void Reset();
            
            bgfx::VertexBufferHandle  m_vbh;
            bgfx::IndexBufferHandle   m_ibh;
            Sphere                    m_sphere;
            Aabb                      m_aabb;
            Obb                       m_obb;
            PrimitiveArray            m_prims;
        };

        struct Mesh
        {
            void Load(bx::ReaderSeekerI* reader);
            void UnLoad();
            void Submit(bgfx::ViewId id, bgfx::ProgramHandle program, 
                const float* mtx, uint64_t state)const;
        
            bgfx::VertexDecl m_decl;
            typedef tinystl::vector<Group>  GroupArray;
            GroupArray  m_groups;
        };

        Mesh  *LoadMesh(bx::ReaderSeekerI* reader);

        bgfx::ShaderHandle LoadShader(bx::FileReaderI* reader, const char* name);
        
        bgfx::ProgramHandle LoadProgram(bx::FileReaderI* reader, const char *vs_name, const char *fs_name);

        bgfx::TextureHandle LoadTexture(bx::FileReaderI* reader, const char* file_path, uint32_t flags, uint8_t skp, bgfx::TextureInfo* info, bimg::Orientation::Enum* orientation);
    }

} // namespace px
