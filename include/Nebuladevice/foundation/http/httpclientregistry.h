#pragma once
//------------------------------------------------------------------------------
/**
    @class Http::HttpClientRegistry
    
    The HttpClientRegistry provides a way to re-use existing connections
    to HTTP servers instead of setting up a HTTP connection for every 
    single HTTP request.     
    
    (C) 2009 Radon Labs GmbH
*/
// HttpClientRegistry not implemented on the Wii
#if __NEBULA3_HTTP_FILESYSTEM__
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/foundation/http/httpclient.h"
#include "Nebuladevice/foundation/io/uri.h"
#include "Nebuladevice/foundation/util/dictionary.h"
#include "Nebuladevice/foundation/util/stringatom.h"

//------------------------------------------------------------------------------
namespace Http
{
class HttpClientRegistry : public Core::RefCounted
{
    __DeclareClass(HttpClientRegistry);
    __DeclareSingleton(HttpClientRegistry);
public:
    /// constructor
    HttpClientRegistry();
    /// destructor
    virtual ~HttpClientRegistry();

    /// setup the client registry
    void Setup();
    /// discard the client registry, closes all open connections
    void Discard();
    /// return true if the object has been setup
    bool IsValid() const;

    /// open a connection to a HTTP server, reuse connection if already connected
    Ptr<HttpClient> ObtainConnection(const IO::URI& uri);
    /// give up connection to a HTTP server, this will NEVER disconnect!
    void ReleaseConnection(const IO::URI& uri);
    /// check if a connection to an HTTP server exists
    bool IsConnected(const IO::URI& uri) const;
    /// disconnect all connections with a zero use count
    void DisconnectIdle();

private:
    struct Connection
    {
        Ptr<HttpClient> httpClient;
        SizeT useCount;
    };

    Util::Dictionary<Util::StringAtom, Connection> connections;
    bool isValid;
};

//------------------------------------------------------------------------------
/**
*/
inline bool
HttpClientRegistry::IsValid() const
{
    return this->isValid;
}

} // namespace Http
//------------------------------------------------------------------------------
#endif //__WII__    