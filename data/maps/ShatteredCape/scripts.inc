@ Pokémon Aevum — SHATTERED CAPE
@ Placeholder map script file.

ShatteredCape_MapScripts::
    .byte 0

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
ShatteredCape_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_SHATTERED_CAPE, ShatteredCape_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_DRAGON_SCALE, 1
    goto_if_eq VAR_RESULT, FALSE, ShatteredCape_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_MAGMARIZER, 1
    goto_if_eq VAR_RESULT, FALSE, ShatteredCape_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_DRAGON_SCALE, 1
    giveitem ITEM_MAGMARIZER, 1
    setflag FLAG_AEVUM_CACHE_SHATTERED_CAPE
    releaseall
    end

ShatteredCape_EventScript_AevumEvolutionCacheEmpty::
    msgbox ShatteredCape_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

ShatteredCape_EventScript_AevumEvolutionCacheBagFull::
    msgbox ShatteredCape_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

ShatteredCape_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

ShatteredCape_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
