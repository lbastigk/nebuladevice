//------------------------------------------------------------------------------
//  jobspumathtest.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/jobs/stdjob.h"

#include "NebulaDeviceTests/spumathtest/job/testrunner.h"
#include "NebulaDeviceTests/spumathtest/job/float4test.h"
#include "NebulaDeviceTests/spumathtest/job/mathtestutil.h"
#include "NebulaDeviceTests/spumathtest/job/matrix44test.h"
#include "NebulaDeviceTests/spumathtest/job/quaterniontest.h"
#include "NebulaDeviceTests/spumathtest/job/planetest.h"
#include "NebulaDeviceTests/spumathtest/job/pointtest.h"
#include "NebulaDeviceTests/spumathtest/job/vectortest.h"
#include "NebulaDeviceTests/spumathtest/job/stackdebug.h"

extern "C"
{
//------------------------------------------------------------------------------
/**
*/
void
SpuMathTestJobFunc(__attribute((unused)) const JobFuncContext&)
{
    spu_printf("SpuMathTestJobFunc start");

    Test::TestRunner runner;
    Test::Float4Test f4("Float4Test");
/*
    Test::Matrix44Test m44("Matrix44Test");
    Test::QuaternionTest q("QuaternionTest");
    Test::PlaneTest pl("PlaneTest");
    Test::PointTest p("PointTest");
    Test::VectorTest v("VectorTest");
*/

    runner.AttachTestCase(&f4);
/*
    runner.AttachTestCase(&m44);

    runner.AttachTestCase(&q);
    runner.AttachTestCase(&pl);
    runner.AttachTestCase(&p);
    runner.AttachTestCase(&v);
*/
    runner.Run();
}
__ImplementSpursJob(SpuMathTestJobFunc);

}