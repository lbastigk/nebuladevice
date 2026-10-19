//------------------------------------------------------------------------------
//  factory.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/addons/db/dbfactory.h"
#include "Nebuladevice/addons/db/database.h"
#include "Nebuladevice/addons/db/command.h"
#include "Nebuladevice/addons/db/table.h"
#include "Nebuladevice/addons/db/dataset.h"
#include "Nebuladevice/addons/db/reader.h"
#include "Nebuladevice/addons/db/writer.h"
#include "Nebuladevice/addons/db/relation.h"
#include "Nebuladevice/addons/db/valuetable.h"

namespace Db
{
__ImplementClass(Db::DbFactory, 'DBFC', Core::RefCounted);
__ImplementSingleton(Db::DbFactory);

//------------------------------------------------------------------------------
/**
*/
DbFactory::DbFactory()
{
    __ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
DbFactory::~DbFactory()
{
    __DestructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Database>
DbFactory::CreateDatabase() const
{
    n_error("Db::DbFactory::CreateDatabase() called!");
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Command>
DbFactory::CreateCommand() const
{
    n_error("Db::DbFactory::CreateCommand() called!");
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Table>
DbFactory::CreateTable() const
{
    n_error("Db::DbFactory::CreateTable() called!");
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Dataset>
DbFactory::CreateDataset() const
{
    n_error("Db::DbFactory::CreateDataset() called!");
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
Ptr<FilterSet>
DbFactory::CreateFilterSet() const
{
    n_error("Db::DbFactory::CreateFilterSet() called!");
    return 0;
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Relation>
DbFactory::CreateRelation() const
{
    return Relation::Create();
}

//------------------------------------------------------------------------------
/**
*/
Ptr<ValueTable>
DbFactory::CreateValueTable() const
{
    return ValueTable::Create();
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Reader>
DbFactory::CreateReader() const
{
    return Reader::Create();
}

//------------------------------------------------------------------------------
/**
*/
Ptr<Writer>
DbFactory::CreateWriter() const
{
    return Writer::Create();
}

} // namespace Db
