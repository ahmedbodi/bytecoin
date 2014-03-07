// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0, uint256("0x00000000c3040b997c96926200ed00b0a5b2e97e3d0015deb41249489e666f84"))
	( 12305, uint256("0x0000000000096316da076ab294c5082be090c7190439aee8bbdfc7b49dae349d"))
        ( 14200, uint256("0x000000000002199e9958c3c9efd0e983d7239508b55ff61544fed91dfdf86d7b"))
        ( 15000, uint256("0x000000000001ccbb0d401b34b3b76160ea227e6b3e21aabfcc68c1b6ab453846"))
        ( 18420, uint256("0x0000000000000da303207143c6b5b1cf996f4fbdad16441a3db1e0824d99546e"))
        ( 20000, uint256("0x00000000000134b0d5d1f731cf0e3d200e9f7ba937f375a968ac5925c101f880"))
        ( 25000, uint256("0x0000000000015ba264b7214e95b7af5491645de41e01348e1438db02f0793aa4"))
        ( 30000, uint256("0x000000000000caf69addc340f1cf49976737c33a52f1826bd7cc405654d95c45"))
 	( 35000, uint256("0x0000000000002e4214709ad012414a1b030fa9aa1a6f1e2f9d1121418ee47283"))
        ( 40894, uint256("0x0000000000000effc30afbffd15fb296fa12e4ee80b514f71329324e27244ac1"))
        ;

    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, uint256("0000000017295c46d2ef2a1875ab3328cf6fc95e6edcb912c71ad0540080a807"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (!GetBoolArg("-checkpoints", true))
            return true;

        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (!GetBoolArg("-checkpoints", true))
            return 0;

        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (!GetBoolArg("-checkpoints", true))
            return NULL;

        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
