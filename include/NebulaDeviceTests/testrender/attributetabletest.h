#ifndef TEST_ATTRIBUTETABLETEST_H
#define TEST_ATTRIBUTETABLETEST_H
//------------------------------------------------------------------------------
/**
    @class Test::AttributeTableTest
  
    Test AttributeTable functionality.
    
    (C) 2006 Radon Labs GmbH
*/
#include "NebulaDeviceTests/testbase/testcase.h"
#include "Nebuladevice/addons/attr/attrid.h"
#include "Nebuladevice/addons/attr/attributetable.h"

//------------------------------------------------------------------------------
namespace Test
{
class AttributeTableTest : public TestCase
{
    __DeclareClass(AttributeTableTest);
public:
    /// run the test
    virtual void Run();

private:
    /// verify row contents...
    void VerifyRow(Attr::AttributeTable* table, int rowIndex);
};

}; // namespace Test
//------------------------------------------------------------------------------
#endif        
