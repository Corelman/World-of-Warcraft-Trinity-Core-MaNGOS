/*
 * Copyright (C) 2011-2013 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2013 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Player.h"
#include "Battleground.h"
#include "BattlegroundRB.h"
#include "Language.h"

BattlegroundRB::BattlegroundRB()
{
    //TODO FIX ME!
    StartMessageIds[BG_STARTING_EVENT_FIRST]  = 0;
    StartMessageIds[BG_STARTING_EVENT_SECOND] = LANGUAGE_BG_WS_START_ONE_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANGUAGE_BG_WS_START_HALF_MINUTE;
    StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANGUAGE_BG_WS_HAS_BEGUN;
}

BattlegroundRB::~BattlegroundRB()
{
}

void BattlegroundRB::StartingEventCloseDoors()
{
}

void BattlegroundRB::StartingEventOpenDoors()
{
}

void BattlegroundRB::AddPlayer(Player* player)
{
    Battleground::AddPlayer(player);
    //create score and add it to map, default values are set in constructor
    BattlegroundRBScore* sc = new BattlegroundRBScore;

    PlayerScores[player->GetGUID()] = sc;
}

void BattlegroundRB::RemovePlayer(Player* /*player*/, uint64 /*guid*/, uint32 /*team*/)
{
}

void BattlegroundRB::HandleAreaTrigger(Player* /*Source*/, uint32 /*Trigger*/)
{
    // this is wrong way to implement these things. On official it done by gameobject spell cast.
    if (GetStatus() != STATUS_IN_PROGRESS)
        return;
}

void BattlegroundRB::UpdatePlayerScore(Player* Source, uint32 type, uint32 value, bool doAddHonor)
{
    std::map<uint64, BattlegroundScore*>::iterator itr = PlayerScores.find(Source->GetGUID());

    if (itr == PlayerScores.end())                         // player not found...
        return;

    Battleground::UpdatePlayerScore(Source, type, value, doAddHonor);
}