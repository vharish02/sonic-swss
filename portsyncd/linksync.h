#ifndef __LINKSYNC__
#define __LINKSYNC__

#include "dbconnector.h"
#include "producerstatetable.h"
#include "netmsg.h"

#include <map>

namespace swss {

class LinkSync : public NetMsg
{
public:
    enum { MAX_ADDR_SIZE = 64 };

    LinkSync(DBConnector *appl_db, DBConnector *state_db);

    virtual void onMsg(int nlmsg_type, struct nl_object *obj);

private:
    ProducerStateTable m_portTableProducer, m_vlanTableProducer, m_vlanMemberTableProducer;
    Table m_portTable, m_vlanMemberTable, m_statePortTable;

    std::map<unsigned int, std::string> m_ifindexNameMap;
};

}

#endif
