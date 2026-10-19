#pragma once
//------------------------------------------------------------------------------
/**
    @class Test::FModAudioApplication
    
    Simple audio test application.
    
    (C) 2008 Radon Labs GmbH
*/

#define USE_HTTP                                1

#define LOAD_PROJECT_FIRST_TEST                 0
#define LOAD_PROJECT_EXAMPLES                   0
#define LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST   1

#include "Nebuladevice/foundation/util/array.h"
#include "Nebuladevice/foundation/core/ptr.h"
#include "Nebuladevice/render/input/inputserver.h"
#include "Nebuladevice/foundation/timing/timer.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#if USE_HTTP
#include "Nebuladevice/foundation/http/httpinterface.h"
#include "Nebuladevice/foundation/http/httpserverproxy.h"
#endif
#include "Nebuladevice/foundation/io/gamecontentserver.h"
#include "Nebuladevice/foundation/io/assignregistry.h"
#include "Nebuladevice/foundation/io/ioserver.h"
#include "Nebuladevice/addons/audio2/fmodeventprojectid.h"

namespace Audio2 { class Audio2Interface; 
                   class Audio2Server; 
                   class Audio2Player; 
                   class Audio2Emitter; }
namespace Jobs { class JobSystem; }

//------------------------------------------------------------------------------
namespace Test
{
class FModAudioApplication
{
public:
    /// constructor
    FModAudioApplication();
    /// destructor
    virtual ~FModAudioApplication();
    /// open the application
    virtual bool Open();
    /// close the application
    virtual void Close();
    /// close the application
    virtual void Run();

private:
    void ProcessInput_Test();
    void ProcessInput_TestSoundStartStop();
	void ProcessInput_Test3DPan();
	void ProcessInput_Test3DVolume();
	void ProcessInput_Test3DDoppler();
	void ProcessInput_Test3DAll();

private:
	Ptr<Core::CoreServer> coreServer;
    Ptr<Jobs::JobSystem> jobSystem;
    Ptr<IO::GameContentServer> gameContentServer;
    Ptr<IO::AssignRegistry> assignRegistry;
    Ptr<IO::IoServer> ioServer;
#if USE_HTTP
    Ptr<Http::HttpInterface> httpInterface;
	Ptr<Http::HttpServerProxy> httpServerProxy;
#endif
    Timing::Timer masterTime;
	Ptr<Input::InputServer> inputServer;
    Ptr<Audio2::Audio2Interface> audioInterface;
    Ptr<Audio2::Audio2Server> audioServer;
    Ptr<Audio2::Audio2Player> audioPlayer;
    static const Audio2::FmodEventProjectId projectIdFirstTest;
    static const Audio2::FmodEventProjectId projectIdExamples;

#if LOAD_PROJECT_FIRST_TEST
    Ptr<Audio2::Audio2Emitter> audioEmitterPsMono;
#endif
#if LOAD_PROJECT_EXAMPLES
    Ptr<Audio2::Audio2Emitter> audioEmitterCar;    
#endif
#if LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST
    enum { PSMONO_INSTANCE_COUNT = 4 };
    Ptr<Audio2::Audio2Emitter> audioEmittersPsMonoInstance[PSMONO_INSTANCE_COUNT];  
#endif

    Ptr<Audio2::Audio2Emitter> emitterWatched;
};

} // namespace Test
//------------------------------------------------------------------------------
