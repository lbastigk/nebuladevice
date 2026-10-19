//------------------------------------------------------------------------------
//  util/segmentedgfxutil.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/application/graphicsfeature/graphicsutil/segmentedgfxutil.h"
#include "Nebuladevice/render/graphics/graphicsserver.h"
#include "Nebuladevice/render/graphics/modelentity.h"
#include "Nebuladevice/render/graphics/stage.h"
#include "Nebuladevice/render/resources/resourceid.h"
#include "Nebuladevice/render/models/nodes/transformnode.h"
#include "Nebuladevice/foundation/core/factory.h"

namespace GraphicsFeature
{
using namespace Graphics;
//------------------------------------------------------------------------------
/**
*/
SegmentedGfxUtil::SegmentedGfxUtil()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
Util::Array<Ptr<Graphics::ModelEntity> >
SegmentedGfxUtil::CreateAndSetupGraphicsEntities(const Util::String& resName, const Math::matrix44& worldMatrix, const Ptr<Graphics::Stage> stage)
{
    Util::Array<Ptr<Graphics::ModelEntity> > graphicsEntities;

    // load whole model
    //Ptr<Models::ManagedModel> model = ModelServer::Instance()->LoadManagedModel(ResourceId(resName));    

    //  TODO:
    // collect segment hierarchy nodes from resource    
    //if (model->GetModel()->HasNode("model"))
    //{
    //    Util::Array<Ptr<Models::ModelNode> > modelNodes = model->GetModel()->GetNodes();
    //    Util::Array<Ptr<Models::ModelNode> > segments;                
    //    for (int i = 0; i < modelNodes.Size(); i++)
    //    {
    //        if (modelNodes[i]->HHasHints(nSceneNode::LevelSegment)))
    //        {
    //            segments.Append(curNode);
    //        }
    //    }

    //    // check if segments actually exist
    //    if (segments.Size() > 0)
    //    {
    //        nTransformNode* shadowNode = (nTransformNode*) resource->GetNode()->Find("shadow");
    //    
    //        // create one graphics entity for each segment
    //        int num = segments.Size();
    //        int i;
    //        for (i = 0; i < num; i++)
    //        {
    //            // build a resource name for the segment
    //            Util::String segResName = resName;
    //            segResName.TrimRight("/");
    //            segResName.Append("/model/");
    //            segResName.Append(segments[i]->GetName());
    //            
    //            // create and setup graphics entity
				//Ptr<Graphics::ModelEntity> ge = Graphics::ModelEntity::Create();
    //            ge->SetResourceId(ResourceId(segResName));
    //            ge->SetTransform(worldMatrix);

    //            // see if a shadow node of the same name exists
    //            if (shadowNode && shadowNode->Find(segments[i]->GetName()))
    //            {
    //                Util::String shdResName = resName;
    //                shdResName.TrimRight("/");
    //                shdResName.Append("/shadow/");
    //                shdResName.Append(segments[i]->GetName());
    //                ge->SetShadowResourceName(shdResName);
    //            }
    //            if (stage.isvalid())
    //            {
    //                stage->AttachEntity(ge.upcast<Graphics::GraphicsEntity>());
    //            }
    //            graphicsEntities.Append(ge.upcast<Graphics::GraphicsEntity>());
    //        }            
    //        return graphicsEntities;
    //    }
    //}

    Util::String fullResourceName("mdl:");
    fullResourceName.Append(resName);
    fullResourceName.Append(".n3");

    // fallthrough: don't create segments
	Ptr<Graphics::ModelEntity> ge = Graphics::ModelEntity::Create();
    ge->SetResourceId(Resources::ResourceId(fullResourceName));
    ge->SetTransform(worldMatrix);
    if (stage.isvalid())
    {
        stage->AttachEntity(ge.upcast<Graphics::GraphicsEntity>());
    }
    graphicsEntities.Append(ge);
    
    return graphicsEntities;
}

}; // namespace GraphicsFeature
