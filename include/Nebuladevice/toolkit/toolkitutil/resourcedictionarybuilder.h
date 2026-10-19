#pragma once
//------------------------------------------------------------------------------
/**
    @class ToolkitUtil::ResourceDictionaryBuilder
    
    Build resource dictionary files.
    
    (C) 2008 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/toolkit/toolkitutil/platform.h"
#include "Nebuladevice/foundation/io/uri.h"
#include "Nebuladevice/foundation/util/stringatom.h"
#include "Nebuladevice/render/resources/streaming/textureinfo.h"
#include "Nebuladevice/foundation/io/stream.h"
#include "Nebuladevice/render/resources/streaming/poolresourcemapper.h"

#define DEBUG_RES_DICT_BUILDER (1)

//------------------------------------------------------------------------------
namespace ToolkitUtil
{

class ResourceDictionaryBuilder
{
public:
    /// constructor
    ResourceDictionaryBuilder(void);
    /// destructor
    ~ResourceDictionaryBuilder(void);
    
    /// set target platform
    void SetPlatform(Platform::Code platform);
    /// set texture directory
    void SetTextureDirectory(const Util::String& texDir);

    /// build the dictionary
    bool BuildDictionary();

    /// unloads dictionary explicitly
    void Unload();

private:
    /// add textures to the dictionary
    bool AddTexturesToDictionary();
    /// save dictionary
    bool SaveDictionary();
    /// reads texture-info from given file-stream and write to given format-info
    bool ReadTextureData(Ptr<IO::Stream>& stream, Resources::TextureInfo& format);
    /// analyzes all textures in resource dictionary and writes default pool to given direction
    void CreateDefaultTexturePool(const IO::URI& fileName, uint maxBytes);
    
    static const SizeT MaxResIdLength = 124;
    Platform::Code platform;
    Util::String texDir;
    Util::Dictionary<Util::StringAtom, Resources::TextureInfo> dict;
};

//------------------------------------------------------------------------------
/**
*/
inline void
ResourceDictionaryBuilder::SetPlatform(Platform::Code p)
{
    this->platform = p;
}

//------------------------------------------------------------------------------
/**
*/
inline void
ResourceDictionaryBuilder::SetTextureDirectory(const Util::String& dir)
{
    this->texDir = dir;
}

} // namespace ToolkitUtil
//------------------------------------------------------------------------------
