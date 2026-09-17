@ Pokémon Aevum — BRAMBLEWOOD
@ Placeholder map script file.

Bramblewood_MapScripts::
    .byte 0

@ ===== AEVUM EVOLUTION CACHE BEGIN =====
Bramblewood_EventScript_AevumEvolutionCache::
    lockall
    goto_if_set FLAG_AEVUM_CACHE_BRAMBLEWOOD, Bramblewood_EventScript_AevumEvolutionCacheEmpty
    checkitemspace ITEM_LEAF_STONE, 1
    goto_if_eq VAR_RESULT, FALSE, Bramblewood_EventScript_AevumEvolutionCacheBagFull
    checkitemspace ITEM_MOON_STONE, 1
    goto_if_eq VAR_RESULT, FALSE, Bramblewood_EventScript_AevumEvolutionCacheBagFull
    giveitem ITEM_LEAF_STONE, 1
    giveitem ITEM_MOON_STONE, 1
    setflag FLAG_AEVUM_CACHE_BRAMBLEWOOD
    releaseall
    end

Bramblewood_EventScript_AevumEvolutionCacheEmpty::
    msgbox Bramblewood_Text_AevumEvolutionCacheEmpty, MSGBOX_DEFAULT
    releaseall
    end

Bramblewood_EventScript_AevumEvolutionCacheBagFull::
    msgbox Bramblewood_Text_AevumEvolutionCacheBagFull, MSGBOX_DEFAULT
    releaseall
    end

Bramblewood_Text_AevumEvolutionCacheEmpty:
    .string "The supply cache has already been emptied.$"

Bramblewood_Text_AevumEvolutionCacheBagFull:
    .string "You need more room in your Bag before opening this cache.$"
@ ===== AEVUM EVOLUTION CACHE END =====
