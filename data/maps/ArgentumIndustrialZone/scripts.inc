
ArgentumIndustrialZone_MapScripts::
    .byte 0

@ ===== AEVUM PORYGON FABRICATOR BEGIN =====
ArgentumIndustrialZone_EventScript_PorygonFabricator::
    lockall
    givemon SPECIES_PORYGON, 55
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, ArgentumIndustrialZone_EventScript_PorygonFabricated
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, ArgentumIndustrialZone_EventScript_PorygonFabricated
    goto Common_EventScript_NoMoreRoomForPokemon

ArgentumIndustrialZone_EventScript_PorygonFabricated::
    msgbox ArgentumIndustrialZone_Text_PorygonFabricated, MSGBOX_DEFAULT
    releaseall
    end

ArgentumIndustrialZone_Text_PorygonFabricated:
    .string "The industrial system generated a PORYGON.$"
@ ===== AEVUM PORYGON FABRICATOR END =====

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
ArgentumIndustrialZone_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_ARGENTUM, ArgentumIndustrialZone_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_DUBIOUS_DISC, 1
    goto_if_eq VAR_RESULT, FALSE, ArgentumIndustrialZone_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_DUBIOUS_DISC, 1
    setflag FLAG_AEVUM_CACHE_ARGENTUM
    releaseall
    end

ArgentumIndustrialZone_EventScript_AevumEvolutionCacheEmpty::
    msgbox ArgentumIndustrialZone_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

ArgentumIndustrialZone_EventScript_AevumEvolutionCacheBagFull::
    msgbox ArgentumIndustrialZone_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

ArgentumIndustrialZone_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

ArgentumIndustrialZone_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
