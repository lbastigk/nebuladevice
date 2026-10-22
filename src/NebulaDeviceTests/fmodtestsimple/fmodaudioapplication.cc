//------------------------------------------------------------------------------
//  fmodaudioapplication.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/fmodtestsimple/fmodaudioapplication.h"
#include "Nebuladevice/foundation/math/matrix44.h"
#include "Nebuladevice/foundation/io/ioserver.h"
#include "Nebuladevice/foundation/util/stringatom.h"
#include "Nebuladevice/foundation/io/fswrapper.h"
#include "Nebuladevice/addons/audio2/audio2interface.h"
#include "Nebuladevice/addons/audio2/audio2server.h"
#include "Nebuladevice/addons/audio2/audio2player.h"
#include "Nebuladevice/addons/audio2/fmodeventid.h"
#include "Nebuladevice/addons/audio2/audio2emitter.h"
#include "Nebuladevice/addons/audio2/audio2listener.h"
#include "Nebuladevice/addons/audio2/fmodeventcategoryid.h"
#include "Nebuladevice/addons/audio2/fmodeventparameterid.h"
#include "Nebuladevice/foundation/math/vector.h"
#include "Nebuladevice/foundation/io/logfileconsolehandler.h"
#include "Nebuladevice/foundation/jobs/jobsystem.h"


using namespace Math;
using namespace Base;
using namespace Test;
#if USE_HTTP
using namespace Http;
#endif
using namespace Audio2;


const Audio2::FmodEventProjectId FModAudioApplication::projectIdFirstTest("first_test");
const Audio2::FmodEventProjectId FModAudioApplication::projectIdExamples("examples");

//static const Math::vector listenerPosition(10.0f, 20.0f, -15.0f);
static const Math::vector listenerPosition(0.0f, 0.0f, 0.0f);

//------------------------------------------------------------------------------
/*
*/
FModAudioApplication::FModAudioApplication()
{
}

//------------------------------------------------------------------------------
/*
*/
FModAudioApplication::~FModAudioApplication()
{
}

//------------------------------------------------------------------------------
/*
*/
bool 
FModAudioApplication::Open()
{
    this->coreServer = Core::CoreServer::Create();
    this->coreServer->SetCompanyName(Util::StringAtom("Radon Labs GmbH"));
    this->coreServer->SetAppName(Util::StringAtom("PS3 Audio Test Simple"));
    this->coreServer->Open();

    this->jobSystem = Jobs::JobSystem::Create();
    this->jobSystem->Setup();

    // setup IO
    this->gameContentServer = IO::GameContentServer::Create();
    this->gameContentServer->SetTitle("RL Test Title");
    this->gameContentServer->SetTitleId("RLTITLEID");
    this->gameContentServer->SetVersion("1.00");
    this->gameContentServer->Setup();

	this->assignRegistry = IO::AssignRegistry::Create();
	this->assignRegistry->Setup();

    this->ioServer = IO::IoServer::Create();
    this->ioServer->MountStandardArchives();
    
    // attach a log file console handler
    #if __WIN32__
    Ptr<IO::LogFileConsoleHandler> logFileHandler = IO::LogFileConsoleHandler::Create();
    IO::Console::Instance()->AttachHandler(logFileHandler.upcast<IO::ConsoleHandler>());
    #endif

#if USE_HTTP
    // setup HTTP server
    this->httpInterface = Http::HttpInterface::Create();
    this->httpInterface->Open();
    this->httpServerProxy = HttpServerProxy::Create();
    this->httpServerProxy->Open();
#endif

    // setup the audio system
    this->audioInterface = Audio2Interface::Create();
    this->audioInterface->Open();
    this->audioServer = Audio2Server::Create();
    this->audioServer->Open();

    this->audioPlayer = Audio2::Audio2Player::Create();

    const matrix44 listenerTransform = matrix44::translation(listenerPosition);
    Audio2::Audio2Listener::Instance()->SetTransform(listenerTransform);


#if LOAD_PROJECT_FIRST_TEST || LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST
    this->audioServer->LoadEventProject(projectIdFirstTest);
    const Audio2::FmodEventId eventIdPsMono(projectIdFirstTest, "eventgroup0/event_psmono");
#endif
#if LOAD_PROJECT_FIRST_TEST
    this->audioEmitterPsMono = Audio2::Audio2Emitter::Create();
    this->audioEmitterPsMono->Setup(eventIdPsMono);
    //this->audioEmitterPsMono->Set3DAttributes(vector(1.0f, 0.0f, -1.0f), vector::nullvec());
    //this->audioEmitterPsMono->Set3DAttributes(vector(10.0f, 20.0f, -15.0f), vector::nullvec());
    this->emitterWatched = this->audioEmitterPsMono;
#endif
#if LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST
    int index;
    for(index = 0; index < PSMONO_INSTANCE_COUNT; ++index)
    {
        this->audioEmittersPsMonoInstance[index] = Audio2::Audio2Emitter::Create();
        this->audioEmittersPsMonoInstance[index]->Setup(eventIdPsMono);
//        this->audioEmittersPsMonoInstance[index]->Set3DAttributes(vector(
//            (float)(index - (PSMONO_INSTANCE_COUNT/2)), 0.0f, -1.0f), vector::nullvec());
    }
    this->emitterWatched = this->audioEmittersPsMonoInstance[0];
#endif

#if LOAD_PROJECT_EXAMPLES
    this->audioServer->LoadEventProject(projectIdExamples);
    const Audio2::FmodEventId eventIdCar(projectIdExamples, "AdvancedTechniques/Car");
    this->audioEmitterCar = Audio2::Audio2Emitter::Create();
    this->audioEmitterCar->Setup(eventIdCar);
    this->audioEmitterCar->SetParameter("load", 1.0f);
    this->audioEmitterCar->SetParameter("RPM", 0.0f);
    this->emitterWatched = this->audioEmitterCar;
#endif

    return true;
}

//------------------------------------------------------------------------------
/*
*/
void 
FModAudioApplication::Close()
{    
    this->emitterWatched = 0;

#if LOAD_PROJECT_FIRST_TEST
    this->audioEmitterPsMono->Discard();
    this->audioEmitterPsMono = 0;
#endif

#if LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST
    int index;
    for(index = 0; index < PSMONO_INSTANCE_COUNT; ++index)
    {
        this->audioEmittersPsMonoInstance[index]->Discard();
        this->audioEmittersPsMonoInstance[index] = 0;
    }
#endif

#if LOAD_PROJECT_EXAMPLES
    this->audioEmitterCar->Discard();
    this->audioEmitterCar = 0;
#endif

    this->audioPlayer = 0;

#if LOAD_PROJECT_FIRST_TEST || LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST
    this->audioServer->UnloadEventProject(projectIdFirstTest);
#endif
#if LOAD_PROJECT_EXAMPLES
    this->audioServer->UnloadEventProject(projectIdExamples);
#endif

    this->audioServer->Close();
    this->audioServer = 0;

    this->audioInterface->Close();
    this->audioInterface = 0;

#if USE_HTTP
    this->httpServerProxy->Close();
    this->httpServerProxy = 0;

    this->httpInterface->Close();
    this->httpInterface = 0;
#endif

    this->ioServer->UnmountStandardArchives();
    this->ioServer = 0;

    this->assignRegistry->Discard();
    this->assignRegistry = 0;

    this->gameContentServer->Discard();
    this->gameContentServer = 0;

    this->jobSystem->Discard();
    this->jobSystem = 0;

    this->coreServer->Close();
    this->coreServer = 0;
}

//------------------------------------------------------------------------------
/*
*/
void 
FModAudioApplication::Run()
{
    static const int frameCount = 100;
    for (int frame = 0; frame < frameCount; ++frame)
    {
#if LOAD_PROJECT_FIRST_TEST_INSTANCE_TEST
        if (frame == 0)
        {
            for (int index = 0; index < PSMONO_INSTANCE_COUNT; ++index)
            {
                this->audioEmittersPsMonoInstance[index]->Play();
            }
        }
#endif

        this->audioServer->OnFrame();
#if USE_HTTP
        this->httpServerProxy->HandlePendingRequests();
#endif

        if(this->emitterWatched.isvalid())
        {
            static Audio2::FmodEventState lastState = (Audio2::FmodEventState)0;
            Audio2::FmodEventState state = this->emitterWatched->GetState();
            if(state != lastState)
            {
                n_printf("state\n"
                         "  playing      : %s\n"
                         "  paused       : %s\n"
                         "  voices stolen: %s\n",
                    (state & EventPlaying) ? "yes" : "no",
                    (state & EventPaused) ? "yes" : "no",
                    (state & EventVoicesStolen) ? "yes" : "no");
            }
            lastState = state;
        }

        Core::SysFunc::Sleep(0.01);
    }
}
