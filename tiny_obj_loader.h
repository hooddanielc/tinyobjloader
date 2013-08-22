#pragma once

#include <string>
#include <vector>
#include <map>

namespace tinyobj {
    
    typedef struct
    {
        std::string name;
        
        float ambient[3];
        float diffuse[3];
        float specular[3];
        float transmittance[3];
        float emission[3];
        float shininess;
        
        std::string ambient_texname;
        std::string diffuse_texname;
        std::string specular_texname;
        std::string normal_texname;
        std::map<std::string, std::string> unknown_parameter;
    } material_t;
    
    typedef struct
    {
        std::vector<int> v_indices;
        std::vector<int> vt_indices;
        std::vector<int> vn_indices;
    } face_t;
    
    typedef struct
    {
        std::vector<float>          positions;
        std::vector<float>          normals;
        std::vector<float>          texcoords;
        std::vector<unsigned int>   indices;
        std::vector<face_t>         faces;
    } mesh_t;
    
    typedef struct
    {
        std::string  name;
        material_t   material;
        mesh_t       mesh;
    } shape_t;
    
    /// Loads .obj from a file.
    /// 'shapes' will be filled with parsed shape data
    /// The function returns error string.
    /// Returns empty string when loading .obj success.
    /// 'mtl_basepath' is optional, and used for base path for .mtl file.
    std::string LoadObj(
                        std::vector<shape_t>& shapes,   // [output]
                        const char* filename,
                        const char* mtl_basepath = NULL);
    
};