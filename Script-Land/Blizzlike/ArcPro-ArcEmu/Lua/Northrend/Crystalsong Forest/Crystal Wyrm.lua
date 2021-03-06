--[[ WoTD License - 
This software is provided as free and open source by the
team of The WoTD Team. This script was written and is
protected by the GPL v2. Please give credit where credit
is due, if modifying, redistributing and/or using this 
software. Thank you.
Thank: WoTD Team; for the Script
~~End of License... Please Stand By...
-- WoTD Team, Janurary 19, 2010. ]]

function CrystalWyrm_OnCombat(Unit, Event)
	Unit:RegisterEvent("CrystalWyrm_FrostBreath", 8000, 0)
end

function CrystalWyrm_FrostBreath(Unit, Event) 
	Unit:FullCastSpellOnTarget(47425, Unit:GetMainTank()) 
end

function CrystalWyrm_OnLeaveCombat(Unit, Event) 
	Unit:RemoveEvents() 
end

function CrystalWyrm_OnDied(Unit, Event) 
	Unit:RemoveEvents()
end

RegisterUnitEvent(31393, 1, "CrystalWyrm_OnCombat")
RegisterUnitEvent(31393, 2, "CrystalWyrm_OnLeaveCombat")
RegisterUnitEvent(31393, 4, "CrystalWyrm_OnDied")