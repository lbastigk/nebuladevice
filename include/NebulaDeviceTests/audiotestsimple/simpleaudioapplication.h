#pragma once
//------------------------------------------------------------------------------
/**
    @class Test::SimpleAudioApplication
    
    Simple audio test application.
    
    (C) 2008 Radon Labs GmbH
*/
#include "audio/audioserver.h"
#include "audio/audioplayer.h"
#include "audio/audiointerface.h"
#include "audio/audioemitter3d.h"
#include "Nebuladevice/foundation/util/array.h"
#include "Nebuladevice/foundation/core/ptr.h"
#include "Nebuladevice/render/input/inputserver.h"
#include "Nebuladevice/foundation/io/assignregistry.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/foundation/http/httpinterface.h"
#include "Nebuladevice/foundation/http/httpserverproxy.h"

//------------------------------------------------------------------------------
namespace Test
{
class SimpleAudioApplication
{
public:
    /// constructor
    SimpleAudioApplication();
    /// destructor
    virtual ~SimpleAudioApplication();
    /// open the application
    virtual bool Open();
    /// close the application
    virtual void Close();
    /// close the application
    virtual void Run();

private:
	void ProcessInput_TestSoundStartStop();
	void ProcessInput_Test3DPan();
	void ProcessInput_Test3DVolume();
	void ProcessInput_Test3DDoppler();
	void ProcessInput_Test3DAll();

private:
	Ptr<Core::CoreServer> coreServer;
    Ptr<Audio::AudioInterface> audioInterface;
    Ptr<Audio::AudioServer> audioServer;
    Ptr<Audio::AudioPlayer> audioPlayer;
	Ptr<Input::InputServer> inputServer;
	Ptr<IO::AssignRegistry> assignRegistry;
	Ptr<Http::HttpInterface> httpInterface;
	Ptr<Http::HttpServerProxy> httpServerProxy;

	Ptr<Audio::AudioEmitter3D> emitter;

	static const Resources::ResourceId	soundBankResource;
	static const CoreAudio::SoundBankId	soundBankId;
};

} // namespace Test
//------------------------------------------------------------------------------
