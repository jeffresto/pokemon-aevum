
MeridianResearchFacility_MapScripts::
    .byte 0

@ ===== AEVUM RESEARCH ACQUISITIONS BEGIN =====
MeridianResearchFacility_EventScript_PorygonReward::
    lockall
    goto_if_set FLAG_AEVUM_RECEIVED_PORYGON, MeridianResearchFacility_EventScript_PorygonAlreadyReceived
    givemon SPECIES_PORYGON, 28
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeridianResearchFacility_EventScript_PorygonReceived
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeridianResearchFacility_EventScript_PorygonReceived
    goto Common_EventScript_NoMoreRoomForPokemon

MeridianResearchFacility_EventScript_PorygonReceived::
    setflag FLAG_AEVUM_RECEIVED_PORYGON
    msgbox MeridianResearchFacility_Text_PorygonReceived, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_PorygonAlreadyReceived::
    msgbox MeridianResearchFacility_Text_PorygonAlreadyReceived, MSGBOX_DEFAULT
    releaseall
    end

@ Late-game repeatable source. Needed so Porygon, Porygon2 and
@ Porygon-Z can all be registered on one save without Ditto.
MeridianResearchFacility_EventScript_PorygonFabricator::
    lockall
    givemon SPECIES_PORYGON, 50
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeridianResearchFacility_EventScript_PorygonFabricated
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeridianResearchFacility_EventScript_PorygonFabricated
    goto Common_EventScript_NoMoreRoomForPokemon

MeridianResearchFacility_EventScript_PorygonFabricated::
    msgbox MeridianResearchFacility_Text_PorygonFabricated, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_RestoreAnorith::
    lockall
    goto_if_set FLAG_AEVUM_REVIVED_ANORITH, MeridianResearchFacility_EventScript_AnorithAlreadyRevived
    checkitem ITEM_CLAW_FOSSIL
    goto_if_eq VAR_RESULT, FALSE, MeridianResearchFacility_EventScript_NoClawFossil
    givemon SPECIES_ANORITH, 25
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeridianResearchFacility_EventScript_AnorithSuccess
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeridianResearchFacility_EventScript_AnorithSuccess
    goto Common_EventScript_NoMoreRoomForPokemon

MeridianResearchFacility_EventScript_AnorithSuccess::
    removeitem ITEM_CLAW_FOSSIL
    setflag FLAG_AEVUM_REVIVED_ANORITH
    msgbox MeridianResearchFacility_Text_AnorithRestored, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_NoClawFossil::
    msgbox MeridianResearchFacility_Text_NoClawFossil, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_AnorithAlreadyRevived::
    msgbox MeridianResearchFacility_Text_AlreadyRestored, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_RestoreLileep::
    lockall
    goto_if_set FLAG_AEVUM_REVIVED_LILEEP, MeridianResearchFacility_EventScript_LileepAlreadyRevived
    checkitem ITEM_ROOT_FOSSIL
    goto_if_eq VAR_RESULT, FALSE, MeridianResearchFacility_EventScript_NoRootFossil
    givemon SPECIES_LILEEP, 25
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeridianResearchFacility_EventScript_LileepSuccess
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeridianResearchFacility_EventScript_LileepSuccess
    goto Common_EventScript_NoMoreRoomForPokemon

MeridianResearchFacility_EventScript_LileepSuccess::
    removeitem ITEM_ROOT_FOSSIL
    setflag FLAG_AEVUM_REVIVED_LILEEP
    msgbox MeridianResearchFacility_Text_LileepRestored, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_NoRootFossil::
    msgbox MeridianResearchFacility_Text_NoRootFossil, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_LileepAlreadyRevived::
    msgbox MeridianResearchFacility_Text_AlreadyRestored, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_RestoreAerodactyl::
    lockall
    goto_if_set FLAG_AEVUM_REVIVED_AERODACTYL, MeridianResearchFacility_EventScript_AerodactylAlreadyRevived
    checkitem ITEM_OLD_AMBER
    goto_if_eq VAR_RESULT, FALSE, MeridianResearchFacility_EventScript_NoOldAmber
    givemon SPECIES_AERODACTYL, 30
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeridianResearchFacility_EventScript_AerodactylSuccess
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeridianResearchFacility_EventScript_AerodactylSuccess
    goto Common_EventScript_NoMoreRoomForPokemon

MeridianResearchFacility_EventScript_AerodactylSuccess::
    removeitem ITEM_OLD_AMBER
    setflag FLAG_AEVUM_REVIVED_AERODACTYL
    msgbox MeridianResearchFacility_Text_AerodactylRestored, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_NoOldAmber::
    msgbox MeridianResearchFacility_Text_NoOldAmber, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_AerodactylAlreadyRevived::
    msgbox MeridianResearchFacility_Text_AlreadyRestored, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_Text_PorygonReceived:
    .string "The research team entrusted you with PORYGON.$"

MeridianResearchFacility_Text_PorygonAlreadyReceived:
    .string "The original PORYGON research sample is already yours.$"

MeridianResearchFacility_Text_PorygonFabricated:
    .string "The industrial replicator produced another PORYGON.$"

MeridianResearchFacility_Text_NoClawFossil:
    .string "A CLAW FOSSIL is required for this restoration.$"

MeridianResearchFacility_Text_NoRootFossil:
    .string "A ROOT FOSSIL is required for this restoration.$"

MeridianResearchFacility_Text_NoOldAmber:
    .string "OLD AMBER is required for this restoration.$"

MeridianResearchFacility_Text_AnorithRestored:
    .string "ANORITH was successfully restored.$"

MeridianResearchFacility_Text_LileepRestored:
    .string "LILEEP was successfully restored.$"

MeridianResearchFacility_Text_AerodactylRestored:
    .string "AERODACTYL was successfully restored.$"

MeridianResearchFacility_Text_AlreadyRestored:
    .string "That specimen has already been restored.$"
@ ===== AEVUM RESEARCH ACQUISITIONS END =====

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
MeridianResearchFacility_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_MERIDIAN, MeridianResearchFacility_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_THUNDER_STONE, 2
    goto_if_eq VAR_RESULT, FALSE, MeridianResearchFacility_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_UP_GRADE, 1
    goto_if_eq VAR_RESULT, FALSE, MeridianResearchFacility_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_ELECTIRIZER, 1
    goto_if_eq VAR_RESULT, FALSE, MeridianResearchFacility_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_THUNDER_STONE, 2
    giveitem ITEM_UP_GRADE, 1
    giveitem ITEM_ELECTIRIZER, 1
    setflag FLAG_AEVUM_CACHE_MERIDIAN
    releaseall
    end

MeridianResearchFacility_EventScript_AevumEvolutionCacheEmpty::
    msgbox MeridianResearchFacility_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_EventScript_AevumEvolutionCacheBagFull::
    msgbox MeridianResearchFacility_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

MeridianResearchFacility_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

MeridianResearchFacility_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
