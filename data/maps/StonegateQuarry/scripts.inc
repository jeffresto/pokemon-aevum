@ Pokémon Aevum — StonegateQuarry

StonegateQuarry_MapScripts::
    .byte 0

@ ===== AEVUM STONEGATE RELICS BEGIN =====
StonegateQuarry_EventScript_OddKeystone::
    lockall
    goto_if_set FLAG_AEVUM_RECEIVED_ODD_KEYSTONE, StonegateQuarry_EventScript_OddKeystoneGone
    checkitemspace ITEM_ODD_KEYSTONE
    goto_if_eq VAR_RESULT, FALSE, StonegateQuarry_EventScript_RelicBagFull
    giveitem ITEM_ODD_KEYSTONE
    goto_if_eq VAR_RESULT, FALSE, StonegateQuarry_EventScript_RelicBagFull
    setflag FLAG_AEVUM_RECEIVED_ODD_KEYSTONE
    releaseall
    end

StonegateQuarry_EventScript_OldAmber::
    lockall
    goto_if_set FLAG_AEVUM_RECEIVED_OLD_AMBER, StonegateQuarry_EventScript_OldAmberGone
    checkitemspace ITEM_OLD_AMBER
    goto_if_eq VAR_RESULT, FALSE, StonegateQuarry_EventScript_RelicBagFull
    giveitem ITEM_OLD_AMBER
    goto_if_eq VAR_RESULT, FALSE, StonegateQuarry_EventScript_RelicBagFull
    setflag FLAG_AEVUM_RECEIVED_OLD_AMBER
    releaseall
    end

StonegateQuarry_EventScript_OddKeystoneGone::
    msgbox StonegateQuarry_Text_RelicGone, MSGBOX_DEFAULT
    releaseall
    end

StonegateQuarry_EventScript_OldAmberGone::
    msgbox StonegateQuarry_Text_RelicGone, MSGBOX_DEFAULT
    releaseall
    end

StonegateQuarry_EventScript_RelicBagFull::
    msgbox StonegateQuarry_Text_RelicBagFull, MSGBOX_DEFAULT
    releaseall
    end

StonegateQuarry_Text_RelicGone:
    .string "You already recovered the relic that was stored here.$"

StonegateQuarry_Text_RelicBagFull:
    .string "There is not enough room in your Bag for the relic.$"
@ ===== AEVUM STONEGATE RELICS END =====

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
StonegateQuarry_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_STONEGATE, StonegateQuarry_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_METAL_COAT, 1
    goto_if_eq VAR_RESULT, FALSE, StonegateQuarry_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_PROTECTOR, 1
    goto_if_eq VAR_RESULT, FALSE, StonegateQuarry_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_METAL_COAT, 1
    giveitem ITEM_PROTECTOR, 1
    setflag FLAG_AEVUM_CACHE_STONEGATE
    releaseall
    end

StonegateQuarry_EventScript_AevumEvolutionCacheEmpty::
    msgbox StonegateQuarry_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

StonegateQuarry_EventScript_AevumEvolutionCacheBagFull::
    msgbox StonegateQuarry_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

StonegateQuarry_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

StonegateQuarry_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
